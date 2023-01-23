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


	//�J�����f�o�C�X�I�[�v��
	VideoCapture cap1(0);	//0��PC�����̃J�����A1�ȍ~��USB�ڑ����ꂽ�J����
	//VideoCapture cap2(1);
	if (!cap1.isOpened()) return -1;
	//if (!cap2.isOpened()) return -1;
	
	//���ʊ�ǂݍ���
	CascadeClassifier cascade("haarcascade_frontalface_alt.xml");

	//���揑�����݃N���X�̃C���X�^���X����
	//VideoWriter writer1("output1.avi", CV_FOURCC_DEFAULT, 10, Size(640, 480), true);
	//VideoWriter writer2("output2.avi", CV_FOURCC_DEFAULT, 10, Size(640, 480), true);

	while (1)
	{
		//********************
		//�摜�L���v�`��&�ϊ�
		//********************
		//�J��������t���[�����擾
		cap1 >> frame1;
		//cap2 >> frame2;

		//�O���C�X�P�[���ɕϊ�
		cvtColor(frame1, gray_image1, CV_BGR2GRAY);
		equalizeHist(gray_image1, gray_image1);
		//imshow("Gray Monitor", gray_image1);

		//cvtColor(frame2, gray_image2, CV_BGR2GRAY);
		//equalizeHist(gray_image2, gray_image2);
		//imshow("Gray Monitor", gray_image2);

		//*******
		//�猟�o
		//*******
		vector<Rect> faces1;
		//vector<Rect> faces2;
		cascade.detectMultiScale(gray_image1, faces1, 1.1, 2, 2);
		//cascade.detectMultiScale(gray_image2, faces2, 1.1, 2, 2);

		//*****
		//�`��&�o��
		//*****
		//��̎���ɘg��`��
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

		//����o��
		//writer1 << frame1;
		//writer2 << frame2;

		//*************
		//�R�}���h����
		//*************
		int key = waitKey(1);
		if (key == 113)			//q�L�[���������ꍇ������
		{
			break;
		}
		else if (key == 115)	//s�L�[�ŃX�N�V��
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