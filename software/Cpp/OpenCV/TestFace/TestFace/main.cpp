#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//識別器
//与えられた画像から顔を検出し、枠をつける
Mat detectFaceInImage(Mat &image, string &cascadeFile)
{
	CascadeClassifier cascade;
	cascade.load(cascadeFile);

	std::vector<Rect> faces;
	cascade.detectMultiScale(image, faces, 1.1, 3, 0, Size(20, 20));

	for (int i = 0; i < faces.size(); i++)
	{
		rectangle(image, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), Scalar(200, 0, 0), 3, CV_AA);
	}
	return image;
}

int main(int argc, char *argv[])
{
	//画像読み込み
	Mat image = imread("E:\\Pictures\\標準画像\\color\\Lenna.bmp", 1);
	if (image.data == NULL) return -1;

	//ファイル名読み込み
	string filename = "haarcascade_fullbody.xml";

	//顔を認識させ、枠をつけさせる
	Mat detectFaceImage = detectFaceInImage(image, filename);

	//表示
	imshow("detect face", detectFaceImage);
	waitKey(0);

	return 0;
}