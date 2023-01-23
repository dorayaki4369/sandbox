using System;
using System.Collections.ObjectModel;
using System.Windows.Controls;
using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Prism.Regions;
using OpenCvSharp;

namespace ProcessingImage {
    public class OptionHolder : BindableBase {
        private static OptionHolder Instance { get; } = new OptionHolder();

        private ObservableCollection<Option> _options = new ObservableCollection<Option> {
            new Option("No Editting", img => img, true),
            new Option("Resize", img => {
                //指定サイズに拡大縮小する
                //Cv2.Resize(img,img,new Size(),200.0/img.Cols,200.0/img.Rows);
                //return img;
                return img[0,240,0,240];
            }),
            new Option("Rotate", img => {
                Cv2.Flip(img.T(),img,0);
                return img;
            }),
            new Option("Binalization", img => {
                Cv2.CvtColor(img,img,ColorConversionCodes.RGB2GRAY);
                Cv2.Threshold(img, img, 0, 255, ThresholdTypes.Binary | ThresholdTypes.Otsu);
                return img;
            }),
            new Option("Nega Posi", img => ~img),
            new Option("Edge", img => {
                var dst = new Mat();
                Cv2.Canny(img,dst,50,200);
                return dst;
            }),
            new Option("GrayScale", img => {
                Cv2.CvtColor(img,img,ColorConversionCodes.RGB2GRAY);
                return img;
            }),
            new Option("Contrast", img => {
                //ルックアップテーブルの作成
                const double a = 20.0;
                var lut = new byte[256];
                for (var i = 0; i < 256; i++) lut[i] = Convert.ToByte(255.0 / (1 + Math.Exp(-a * (i - 128 / 255))));
                
                //輝度値の置き換え処理
                Cv2.LUT(img, lut, img);

                return img;
            }),
            new Option("Gaussian Blur", img => {
                Cv2.GaussianBlur(img,img,new Size(11,11),10,10);
                return img;
            }),
            new Option("Median Blur", img => {
                Cv2.MedianBlur(img,img,11);
                return img;
            }),
            new Option("Bilateral Blur", img => {
                var dst = new Mat();
                Cv2.BilateralFilter(img,dst,11,40,200);
                return dst;
            }),
            new Option("Box Blur", img => {
                Cv2.BoxFilter(img,img,img.Type(),new Size(2,2), new Point(-1,-1), false);
                return img;
            }),
            new Option("Solt & Papper", img => img),
        };

        public ObservableCollection<Option> Options {
            get { return _options; }
            set { SetProperty(ref _options, value); }
        }

        private OptionHolder() {}

        public static OptionHolder GetInstance() {
            return Instance;
        }
    }
}