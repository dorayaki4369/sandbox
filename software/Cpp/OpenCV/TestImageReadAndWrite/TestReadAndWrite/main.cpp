#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;

int main(int argc, char *argv[])
{
	//�摜�ǂݍ���
	Mat Lenna = imread("E:\\Pictures\\�W���摜\\color\\Lenna.bmp", 1);
	if (Lenna.data == NULL) return -1;

	//�摜�����o��
	imwrite("image\\outputCpp.bmp", Lenna);

	return 0;
}