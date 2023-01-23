#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//���ʊ�
//�^����ꂽ�摜���������o���A�g������
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
	//�摜�ǂݍ���
	Mat image = imread("E:\\Pictures\\�W���摜\\color\\Lenna.bmp", 1);
	if (image.data == NULL) return -1;

	//�t�@�C�����ǂݍ���
	string filename = "haarcascade_fullbody.xml";

	//���F�������A�g����������
	Mat detectFaceImage = detectFaceInImage(image, filename);

	//�\��
	imshow("detect face", detectFaceImage);
	waitKey(0);

	return 0;
}