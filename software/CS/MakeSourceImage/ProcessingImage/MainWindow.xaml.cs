using System.IO;
using System.Linq;
using System.Windows;
using MahApps.Metro.Controls;
using Microsoft.Practices.Prism.Mvvm;
using DataFormats = System.Windows.DataFormats;
using DragDropEffects = System.Windows.DragDropEffects;
using DragEventArgs = System.Windows.DragEventArgs;
using Forms = System.Windows.Forms;

namespace ProcessingImage {
    /// <summary>
    /// MainWindow.xaml の相互作用ロジック
    /// </summary>
    public partial class MainWindow : MetroWindow, IView {
        public MainWindow() {
            InitializeComponent();
        }

        /**
         *  Drag And Drop
         */
        private void SourceListDrop(object sender, DragEventArgs e) {
            var files = e.Data.GetData(DataFormats.FileDrop) as string[];

            if (files == null) return;
            foreach (var s in files) {
                AddDirectryPath(s);
            }

            ScrollViewer.ScrollToRightEnd();
        }

        private void SourceListPreviewDragOver(object sender, DragEventArgs e) {
            e.Effects = e.Data.GetDataPresent(DataFormats.FileDrop, true)
                ? DragDropEffects.Copy
                : DragDropEffects.None;
            e.Handled = true;
        }

        /**
         * Browse
         */
        private void SourceListBrowse(object sender, RoutedEventArgs e) {
            var dialog = new Forms.FolderBrowserDialog {
                Description = @"Select a directry containing images."
            };

            if (dialog.ShowDialog() != Forms.DialogResult.OK) return;
            AddDirectryPath(dialog.SelectedPath);

            ScrollViewer.ScrollToRightEnd();
        }

        //ディレクトリパスをSourceListへ追加する。ただし、同じ要素を持つ場合は追加しない。
        //ファイルへのパスの場合は何もしない。
        private void AddDirectryPath(string directryPath) {
            if (File.Exists(directryPath)) return;

            var sList = (DataContext as MainWinVM)?.PathList;
            //同じものがなかった場合追加
            if ((bool) !sList?.Any(x => x.Equals(directryPath))) {
                sList.Add(directryPath);
            }
        }

        /**
         * Delete
         */
        private void SourceListDelete(object sender, RoutedEventArgs e) {
            if (SourceList.SelectedIndex == -1) return;
            (DataContext as MainWinVM)?.PathList.RemoveAt(SourceList.SelectedIndex);
        }

        private void OpenSettingWindow(object sender, RoutedEventArgs e) {
            var win = new SettingWindow {DataContext = new SettingWinVM()};

            win.Show();
        }

        /**
         * Browse
         */
        private void OutputDirectryBrowse(object sender, RoutedEventArgs e) {
            var dialog = new Forms.FolderBrowserDialog {
                Description = @"Select a output image directry."
            };

            if (dialog.ShowDialog() != Forms.DialogResult.OK) return;
            var vm = DataContext as MainWinVM;
            if (vm != null) vm.OutputDirectryName.Value = dialog.SelectedPath;
        }
    }
}