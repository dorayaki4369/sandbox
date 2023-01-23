using System;
using System.Windows.Media;
using Microsoft.Practices.Prism.Mvvm;
using OpenCvSharp;

namespace ProcessingImage {
    public class Option : BindableBase {
        public string Name { get; set; }

        //MainWindowでチェックボックスがオンになっているか。
        private bool _isChecked;

        public bool IsChecked {
            get { return _isChecked; }
            set { SetProperty(ref _isChecked, value); }
        }

        public Func<Mat, Mat> ConvertImageFunc { get; set; }

        //大抵の状況でcheckはfalseに設定するのでデフォルト引数とした。
        public Option(string name,Func<Mat, Mat> convertImageFunc, bool isChecked = false) {
            Name = name;
            ConvertImageFunc = convertImageFunc;
            IsChecked = isChecked;
        }
    }
}