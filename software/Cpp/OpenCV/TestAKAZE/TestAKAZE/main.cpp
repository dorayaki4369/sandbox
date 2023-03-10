#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	//ζΗέέ&\¦
	Mat image = imread(argv[1]);
	namedWindow("³ζ");
	imshow("³ζ", image);

	//detectorΆ¬
	Ptr<AKAZE> detector = AKAZE::create();

	//Α₯_o
	vector<KeyPoint> keypoints;
	detector->detect(image, keypoints);

	//Α₯_`ζ
	drawKeypoints(image, keypoints, image);
	namedWindow("descriptors");
	imshow("descriptors", image);
	imwrite("image\\AKAZE_image5.jpg", image);

	waitKey(0);
	destroyAllWindows();
	return 0;
}