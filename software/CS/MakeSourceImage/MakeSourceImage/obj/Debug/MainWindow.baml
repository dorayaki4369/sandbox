   M S B A M L   `   `   `  ????J  FMakeSourceImage, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null1clr-namespace:MakeSourceImageMakeSourceImage  5   	        MakeSourceImage.MainWindow   5   	   R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   /localclr-namespace:MakeSourceImage     5   	   -   5          ? Title$  
MainWindow??5   	   .??5
      ?  ? ColumnDefinitions 5   
   ?? 5      ?? 5      ?? 5      ?? 5      .+?5   
   ?? -   5         ??Name$ 
ColorImage??5      $??0??6$   $??0q?64   $??Stretch=?5      $??Stretch=?6.   ?? 5   
   -   5        $ 
DepthImage??5      $??1??6$   $??0q?64   $??Stretch=?5      $??Stretch=?6.   ? 5   
   $??2??6   $??0q?6   $??Stretch=?5      $??Stretch=?6-    ? RowDefinitions 5      ?? 5      ?? 5      .+?5      ?? -   5         ??Name$ 
SaveButton??5      $??画像保存??6)   $??0??68   $??0q?6E   $??Stretch=?5      $??Stretch=?63   5      ?? 5      -   5        $ DeleteImage??5      $??指定画像削除??6*   $??1??6;   $??0q?6H   $??Stretch=?5      $??Stretch=?63   5!      &   System.Windows.Controls.DataGrid  5"   
   -   5          Name$ DataGrid??5"      $??3??6%   $??0q?65   $??Stretch=?5#      $??Stretch=?61   5$      5%      