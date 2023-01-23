/*
顔を検出するプログラム
コマンドライン引数で元画像と訓練済みデータファイルを指定する
*/
#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\objdetect\objdetect.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	//画像読み込み&表示
	Mat image = imread(argv[1]);
	namedWindow("元画像");
	imshow("元画像", image);

	//グレイ画像に変換
	//当然変換したほうが実行速度は遅くなる
	//顔検出ではグレイ画像に変換したほうが精度がよかった
	//目検出ではどちらも同じような精度になった
	Mat grayImage;
	cvtColor(image, grayImage, CV_BGR2GRAY);
	equalizeHist(grayImage, grayImage);
	namedWindow("グレイ画像");
	imshow("グレイ画像", grayImage);

	//顔検出
	vector<Rect> faces;
	CascadeClassifier cascade(argv[2]);
	//識別器によって検出
	cascade.detectMultiScale(grayImage, faces, 1.1, 2, 2);

	//結果を描画
	for (auto it = faces.begin(); it < faces.end(); ++it)
	{
		//顔の座標をもとに四角い枠(赤色)を描画
		rectangle(image, it->tl(), it->br(), Scalar(0, 0, 255), 2, 8, 0);
	}
	namedWindow("Haar-Casc検出画像(A-S)");
	imshow("Haar-Casc検出画像(A-S)", image);
	imwrite(argv[3], image);

	waitKey(0);
	destroyAllWindows();
	return 0;
}