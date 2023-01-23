using System;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Net.Mime;
using System.Reactive.Linq;
using System.Windows.Media;
using Microsoft.Practices.Prism.Mvvm;
using OpenCvSharp;
using System.Drawing;
using Reactive.Bindings;
using Reactive.Bindings.Extensions;

namespace ProcessingImage {
    public class MainWinVM : BindableBase {
        //ディレクトリのパスを格納
        public ObservableCollection<string> PathList { get; } = new ObservableCollection<string>();

        //選択されているオプションの数
        public ReactiveProperty<int> AllOptionProps { get; } = new ReactiveProperty<int>();

        //Option = ImgEditMethodの略
        public OptionHolder OptionHolder { get; } = OptionHolder.GetInstance();

        public ReactiveProperty<bool> SaveDesktop { get; } = new ReactiveProperty<bool>(true);
        public ReactiveProperty<string> OutputDirectryName { get; } = new ReactiveProperty<string>();

        public ReactiveCommand CheckAllCommand { get; } = new ReactiveCommand();
        public ReactiveCommand UnCheckAllCommand { get; } = new ReactiveCommand();

        public ReactiveCommand EditCommand { get; }

        public ReactiveProperty<int> NumberOfImage { get; } = new ReactiveProperty<int>(); //ディレクトリ内にある画像の枚数
        public ReactiveProperty<int> NumberOfOutImage { get; } //加工後の枚数
        public ReactiveCommand ClearCommand { get; } = new ReactiveCommand();

        public ReactiveCommand StartCommand { get; }

        public MainWinVM() {
            //DirectryListに値が追加、削除、リセットされた時に変更後の値をNumberOfImageに出力
            PathList.ObserveAddChanged().Subscribe(x => { NumberOfImage.Value += SearchImageFile(x); });
            PathList.ObserveRemoveChanged().Subscribe(x => { NumberOfImage.Value -= SearchImageFile(x); });
            PathList.ObserveResetChanged().Subscribe(_ => { NumberOfImage.Value = 0; });


            //OptionのNumofCheckが変化したときの動作定義
            OptionHolder.Options.ObserveElementProperty(x => x.IsChecked)
                .Subscribe(x => AllOptionProps.Value += x.Value ? 1 : -1);
            //上ではtrueの数を数えられないためここで初期化する
            AllOptionProps.Value = OptionHolder.Options.Count(x => x.IsChecked);
            //デバッグ用
            AllOptionProps.Subscribe(x => Console.WriteLine(nameof(AllOptionProps) + @":{0}", x));


            //処理後の画像枚数を数える
            NumberOfOutImage = NumberOfImage.CombineLatest(AllOptionProps, (x, y) => x * y)
                .ToReactiveProperty();
            //0の時はエラー
            NumberOfOutImage.SetValidateNotifyError(x => x == 0 ? "" : null);


            //Clearボタンが押されたときにSourceListを空にする
            ClearCommand.Subscribe(_ => PathList.Clear());


            //OutputDirectryNameが空か存在しないディレクトリを指していた場合、エラーにする
            OutputDirectryName.SetValidateNotifyError(x => {
                if (string.IsNullOrEmpty(x)) {
                    return "Please enter a output directry path";
                }
                else if (!Directory.Exists(x)) {
                    return "The directry does not exist";
                }

                return null;
            });


            //Check Allボタンを押したとき、全てのOptionにチェックをつける
            CheckAllCommand.Subscribe(_ => {
                foreach (var option in OptionHolder.Options) {
                    option.IsChecked = true;
                }
            });
            //UnCheck Allボタンを押したとき、全てのOptionからチェックを外す
            UnCheckAllCommand.Subscribe(_ => {
                foreach (var option in OptionHolder.Options) {
                    option.IsChecked = false;
                }
            });


            //準備が整ったらStartできるようにする
            StartCommand = NumberOfOutImage.ObserveHasErrors
                .CombineLatest(OutputDirectryName.ObserveHasErrors,
                    (x, y) => new {image = x, directry = y})
                .CombineLatest(SaveDesktop,
                    (a, outDir) => !a.image & (!a.directry || outDir))
                .ToReactiveCommand();
            StartCommand.Subscribe(_ => MakeImage());
        }

        //ディレクトリ内から画像ファイルの枚数を数える
        //ファイルパスが入った場合は例外発生
        private static int SearchImageFile(string directryPath) {
            if (File.Exists(directryPath)) throw new ArgumentException("ファイルパスが入力されました。");

            //画像拡張子の配列
            string[] extensions = {
                ".bmp", ".dib",
                ".jpeg", ".jpg", ".jpe",
                ".jp2",
                ".png",
                ".sr", ".ras",
                ".tiff", ".tif",
                ".exr",
                ".webp",
                ".pbm", ".pgm", ".ppm"
            };
            return Directory.GetFiles(directryPath, "*", SearchOption.TopDirectoryOnly)
                .Count(file => extensions.Any(extention => file.ToLower().EndsWith(extention)));
        }

        private void MakeImage() {
            string[] extensions = {
                ".bmp", ".dib",
                ".jpeg", ".jpg", ".jpe",
                ".jp2",
                ".png",
                ".sr", ".ras",
                ".tiff", ".tif",
                ".exr",
                ".webp",
                ".pbm", ".pgm", ".ppm"
            };

            //保存用ディレクトリへのパス。ない場合は作成する。
            var savePath = SaveDesktop.Value
                ? Environment.GetFolderPath(Environment.SpecialFolder.DesktopDirectory) + "\\processed"
                : OutputDirectryName.Value;
            if (!Directory.Exists(savePath)) Directory.CreateDirectory(savePath);

            //各Optionごとの処理を実行
            foreach (var option in OptionHolder.Options) {
                if (!option.IsChecked) continue;

                foreach (var path in PathList) {
                    //画像のリストを取得
                    var imagePaths = Directory.GetFiles(path, "*", SearchOption.TopDirectoryOnly)
                        .Where(file => extensions.Any(extention => file.ToLower().EndsWith(extention)))
                        .ToArray();

                    //画像ごとに処理を実行
                    foreach (var imgpath in imagePaths) {
                        using (var dst = option.ConvertImageFunc(new Mat(imgpath))) {
                            savePath += @"\\" + Path.GetFileName(imgpath);

                            Cv2.ImWrite(savePath, dst);

                            savePath = Path.GetDirectoryName(savePath);
                        }
                    }
                }
            }
        }
    }
}