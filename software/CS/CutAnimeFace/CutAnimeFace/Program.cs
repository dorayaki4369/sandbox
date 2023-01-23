using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using OpenCvSharp;

namespace CutAnimeFace {
    internal class Program {
        private static int _framenum;

        //フレーム切り出し
        private static void Main() {
            Cv2.WaitKey();
            Console.WriteLine("Creating face image...");

            using (var video = VideoCapture.FromFile("Videos\\PERFECT HUMAN.mp4")) {
                while (true) {
                    using (var frame = video.RetrieveMat()) {
                        _framenum++;
                        if (frame.Empty()) {
                            Console.WriteLine("End of video");
                            break;
                        }

                        //全フレーム切り出すと画像数が増えすぎるので10フレームごとに検出
                        if (_framenum % 10 == 0) DetectAndSaveImg(frame);
                    }
                }
            }
        }

        //顔検出
        private static void DetectAndSaveImg(Mat image) {
            //画像のグレースケール化
            var grayImage = new Mat();
            Cv2.CvtColor(image, grayImage, ColorConversionCodes.BGR2GRAY);

            //ヒストグラムの平坦化
            Cv2.EqualizeHist(grayImage, grayImage);

            //顔の認識 小さい顔は除外
            using (var cascade = new CascadeClassifier("haarcascade_frontalface_default.xml")) {//カスケードのロード
                var mats = cascade.DetectMultiScale(grayImage, 1.1, 3, 0, new Size(80, 80))
                    .Select(rect => new Rect(rect.X, rect.Y, rect.Width, rect.Height)) //顔部分に注目したRectを作る
                    .Select(image.Clone) //切り抜いて画像化
                    .ToList(); //リスト化

                SaveImg(mats);
            }
        }


        private static int _imgNum;

        //画像保存
        private static void SaveImg(IEnumerable<Mat> mats) {
            Cv2.NamedWindow("image", WindowMode.AutoSize);
            var sb = new StringBuilder();

            foreach (var mat in mats) {
                //連番のファイルを作る
                sb.Append("Images\\")
                    .Append("image")
                    .AppendFormat("{0:D5}", _imgNum) //ゼロ埋め
                    .Append(".png");

                //保存
                Cv2.ImWrite(sb.ToString(), mat);
                _imgNum++;

                //ついでに切り抜いた画像を画面表示
                Cv2.ImShow("image", mat);
                Cv2.WaitKey(1);
            }
        }
    }
}