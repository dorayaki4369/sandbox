using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Input;
using System.Windows.Media;
using MahApps.Metro.Controls;
using Microsoft.Practices.Prism.Mvvm;

namespace ProcessingImage {
    /// <summary>
    /// SettingWindow.xaml の相互作用ロジック
    /// </summary>
    public partial class SettingWindow : MetroWindow, IView {
        public SettingWindow() {
            InitializeComponent();
        }

        private void CloseThisWindow(object sender, RoutedEventArgs e) {
            Close();
        }

        private void FinishSoftware(object sender, RoutedEventArgs e) {
            Application.Current.Shutdown();
        }

        private void UIElement_OnMouseLeftButtonUp(object sender, MouseButtonEventArgs e) {
            var ListBox = sender as ListBoxItem;
            var option = (Option)ListBox.DataContext;
            Console.WriteLine(option.Name);

            MenuToggleButton.IsChecked = false;
        }
    }
}
