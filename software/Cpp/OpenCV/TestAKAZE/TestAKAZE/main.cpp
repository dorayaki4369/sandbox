#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	//�摜�ǂݍ���&�\��
	Mat image = imread(argv[1]);
	namedWindow("���摜");
	imshow("���摜", image);

	//detector����
	Ptr<AKAZE> detector = AKAZE::create();

	//�����_���o
	vector<KeyPoint> keypoints;
	detector->detect(image, keypoints);

	//�����_�`��
	drawKeypoints(image, keypoints, image);
	namedWindow("descriptors");
	imshow("descriptors", image);
	imwrite("image\\AKAZE_image5.jpg", image);

	waitKey(0);
	destroyAllWindows();
	return 0;
}