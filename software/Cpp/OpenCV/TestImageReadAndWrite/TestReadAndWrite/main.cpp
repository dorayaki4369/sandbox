#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;

int main(int argc, char *argv[])
{
	//‰æ‘œ“Ç‚İ‚İ
	Mat Lenna = imread("E:\\Pictures\\•W€‰æ‘œ\\color\\Lenna.bmp", 1);
	if (Lenna.data == NULL) return -1;

	//‰æ‘œ‘‚«o‚µ
	imwrite("image\\outputCpp.bmp", Lenna);

	return 0;
}