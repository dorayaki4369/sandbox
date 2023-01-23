#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;

int main(int argc, char *argv[])
{
	//画像読み込み
	Mat Lenna = imread("E:\\Pictures\\標準画像\\color\\Lenna.bmp", 1);
	if (Lenna.data == NULL) return -1;

	//画像書き出し
	imwrite("image\\outputCpp.bmp", Lenna);

	return 0;
}