/*
������o����v���O����
�R�}���h���C�������Ō��摜�ƌP���ς݃f�[�^�t�@�C�����w�肷��
*/
#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\objdetect\objdetect.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	//�摜�ǂݍ���&�\��
	Mat image = imread(argv[1]);
	namedWindow("���摜");
	imshow("���摜", image);

	//�O���C�摜�ɕϊ�
	//���R�ϊ������ق������s���x�͒x���Ȃ�
	//�猟�o�ł̓O���C�摜�ɕϊ������ق������x���悩����
	//�ڌ��o�ł͂ǂ���������悤�Ȑ��x�ɂȂ���
	Mat grayImage;
	cvtColor(image, grayImage, CV_BGR2GRAY);
	equalizeHist(grayImage, grayImage);
	namedWindow("�O���C�摜");
	imshow("�O���C�摜", grayImage);

	//�猟�o
	vector<Rect> faces;
	CascadeClassifier cascade(argv[2]);
	//���ʊ�ɂ���Č��o
	cascade.detectMultiScale(grayImage, faces, 1.1, 2, 2);

	//���ʂ�`��
	for (auto it = faces.begin(); it < faces.end(); ++it)
	{
		//��̍��W�����ƂɎl�p���g(�ԐF)��`��
		rectangle(image, it->tl(), it->br(), Scalar(0, 0, 255), 2, 8, 0);
	}
	namedWindow("Haar-Casc���o�摜(A-S)");
	imshow("Haar-Casc���o�摜(A-S)", image);
	imwrite(argv[3], image);

	waitKey(0);
	destroyAllWindows();
	return 0;
}