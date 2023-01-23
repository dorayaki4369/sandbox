#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	//画像読み込み&表示
	Mat image = imread(argv[1]);
	namedWindow("元画像");
	imshow("元画像", image);

	//detector生成
	Ptr<AKAZE> detector = AKAZE::create();

	//特徴点抽出
	vector<KeyPoint> keypoints;
	detector->detect(image, keypoints);

	//特徴点描画
	drawKeypoints(image, keypoints, image);
	namedWindow("descriptors");
	imshow("descriptors", image);
	imwrite("image\\AKAZE_image5.jpg", image);

	waitKey(0);
	destroyAllWindows();
	return 0;
}