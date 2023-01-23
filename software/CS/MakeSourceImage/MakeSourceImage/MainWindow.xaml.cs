using System;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text.RegularExpressions;
using System.Threading;
using System.Windows;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Threading;
using OpenCvSharp;
using OpenCvSharp.Extensions;
using OpenNI;
using Window = System.Windows.Window;

namespace MakeSourceImage {
    /// <summary>
    /// MainWindow.xaml の相互作用ロジック
    /// </summary>
    public partial class MainWindow : Window {
        private BitmapSource _colorBitmapSource;
        private BitmapSource _depthBitmapSource;
        private bool _shouldRun;

        private readonly string[] _filePath = {
            "C:\\Users\\dorayaki4369\\GoogleDrive\\Source\\CS\\MakeSourceImage\\color_depth\\color",
            "C:\\Users\\dorayaki4369\\GoogleDrive\\Source\\CS\\MakeSourceImage\\color_depth\\depth"
        };

        private int _shotNum;

        public MainWindow() {
            InitializeComponent();

            try {
                //ContextとImageGeneratorの作成
                var context = Context.CreateFromXmlFile("SamplesConfig.xml", out var _);
                _shouldRun = true;

                //画像更新のためのスレッドを作成
                var image = context.FindExistingNode(NodeType.Image) as ImageGenerator;
                var depth = context.FindExistingNode(NodeType.Depth) as DepthGenerator;

                var imageReaderThread = new Thread(() => {
                    while (_shouldRun) {
                        context.WaitAndUpdateAll();

                        //画像取得スレッド
                        Dispatcher.BeginInvoke(DispatcherPriority.Background, new Action(() => {
                            var imageMeta = image?.GetMetaData();
                            var depthMeta = depth?.GetMetaData();

                            //ImageMetaDataをBitmapSourceに変換する
                            if (imageMeta == null) return;
                            _colorBitmapSource = BitmapSource.Create(
                                imageMeta.XRes, imageMeta.YRes,
                                96, 96, PixelFormats.Rgb24, null, imageMeta.ImageMapPtr,
                                imageMeta.DataSize, imageMeta.XRes * imageMeta.BytesPerPixel
                            );
                            _colorBitmapSource = new CroppedBitmap(_colorBitmapSource, new Int32Rect(0, 0, 240, 240));

                            //書き込み
                            ColorImage.Source = _colorBitmapSource;

                            //DepthMetaDataをMatに変換する
                            if (depthMeta == null) return;
                            var depthArray = new short[depthMeta.XRes * depthMeta.YRes];
                            Marshal.Copy(depthMeta.DepthMapPtr, depthArray, 0, depthArray.Length);
                            for (var i = 0; i < depthArray.Length; i++) {
                                depthArray[i] = (short) (0xffff - 0xffff * depthArray[i] / depth.DeviceMaxDepth);
                            }

                            _depthBitmapSource = BitmapSource.Create(depthMeta.XRes, depthMeta.YRes,
                                96, 96, PixelFormats.Gray16, null, depthArray,
                                depthMeta.XRes * depthMeta.BytesPerPixel);
                            _depthBitmapSource = new CroppedBitmap(_depthBitmapSource, new Int32Rect(0, 0, 240, 240));

                            //書き込み
                            DepthImage.Source = _depthBitmapSource;
                        }));
                    }
                });

                imageReaderThread.Start();
            }
            catch (Exception e) {
                MessageBox.Show(e.Message);
            }

            //保存場所の画像検索、DataGridに表示
            Console.WriteLine(@"Data Loading. Please Wait.");
            if (!Directory.Exists(_filePath[0]) && !Directory.Exists(_filePath[1]))
                throw new DirectoryNotFoundException(@"保存するディレクトリが見つかりませんでした。");
            _shotNum = Directory.GetFiles(_filePath[0], @"*.jpg", SearchOption.TopDirectoryOnly).Length;

            ImageNum.Text = _shotNum.ToString();
        }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e) {
            _shouldRun = false;
        }

        //画像を保存
        private void ClickSaveButton(object sender, RoutedEventArgs e) {
            try {
                //color
                var enc = new PngBitmapEncoder();
                var fs = new FileStream(_filePath[0] + "\\" + _shotNum + ".jpg", FileMode.Create);
                enc.Frames.Add(BitmapFrame.Create(_colorBitmapSource));
                enc.Save(fs);
                fs.Close();
                fs.Dispose();

                //depth
                enc = new PngBitmapEncoder();
                fs = new FileStream(_filePath[1] + "\\" + _shotNum + ".jpg", FileMode.Create);
                enc.Frames.Add(BitmapFrame.Create(_depthBitmapSource));
                enc.Save(fs);

                fs.Close();
                fs.Dispose();

                _shotNum++;
                ImageNum.Text = _shotNum.ToString();
            }
            catch {
                Console.WriteLine(e);
                throw;
            }
        }

        private void SaveButton_OnKeyDown(object sender, KeyEventArgs e) {
            if (e.Key == Key.LeftCtrl) {
                ClickSaveButton(null, null);
            }
        }
    }
}