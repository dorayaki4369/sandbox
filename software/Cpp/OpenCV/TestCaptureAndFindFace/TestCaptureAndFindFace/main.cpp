#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	int image_number = 0;
	Mat frame1, gray_image1;
	Mat frame2, gray_image2;


	//カメラデバイスオープン
	VideoCapture cap1(0);	//0はPC内臓のカメラ、1以降はUSB接続されたカメラ
	//VideoCapture cap2(1);
	if (!cap1.isOpened()) return -1;
	//if (!cap2.isOpened()) return -1;
	
	//識別器読み込み
	CascadeClassifier cascade("haarcascade_frontalface_alt.xml");

	//動画書き込みクラスのインスタンス生成
	//VideoWriter writer1("output1.avi", CV_FOURCC_DEFAULT, 10, Size(640, 480), true);
	//VideoWriter writer2("output2.avi", CV_FOURCC_DEFAULT, 10, Size(640, 480), true);

	while (1)
	{
		//********************
		//画像キャプチャ&変換
		//********************
		//カメラからフレームを取得
		cap1 >> frame1;
		//cap2 >> frame2;

		//グレイスケールに変換
		cvtColor(frame1, gray_image1, CV_BGR2GRAY);
		equalizeHist(gray_image1, gray_image1);
		//imshow("Gray Monitor", gray_image1);

		//cvtColor(frame2, gray_image2, CV_BGR2GRAY);
		//equalizeHist(gray_image2, gray_image2);
		//imshow("Gray Monitor", gray_image2);

		//*******
		//顔検出
		//*******
		vector<Rect> faces1;
		//vector<Rect> faces2;
		cascade.detectMultiScale(gray_image1, faces1, 1.1, 2, 2);
		//cascade.detectMultiScale(gray_image2, faces2, 1.1, 2, 2);

		//*****
		//描画&出力
		//*****
		//顔の周りに枠を描画
		std::vector<cv::Rect>::const_iterator it1 = faces1.begin();
		for (; it1 != faces1.end(); ++it1)
		{
			rectangle(frame1, it1->tl(), it1->br(), Scalar(0, 0, 255), 2, 8, 0);
		}
		imshow("Monitor1", frame1);

		//std::vector<cv::Rect>::const_iterator it2 = faces2.begin();
		//for (; it2 != faces2.end(); ++it2)
		//{
		//	rectangle(frame2, it2->tl(), it2->br(), Scalar(0, 0, 255), 2, 8, 0);
		//}
		//imshow("Monitor", frame2);

		//動画出力
		//writer1 << frame1;
		//writer2 << frame2;

		//*************
		//コマンド入力
		//*************
		int key = waitKey(1);
		if (key == 113)			//qキーを押した場合抜ける
		{
			break;
		}
		else if (key == 115)	//sキーでスクショ
		{
			image_number++;
			stringstream name;
			name.str("");
			name << "img" << setw(3) << setfill('0') << image_number << ".jpg";
			imwrite(name.str(), frame2);
		}
	}
	cv::destroyAllWindows();
	return 0;
}