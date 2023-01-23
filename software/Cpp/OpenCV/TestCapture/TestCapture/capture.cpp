#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	int image_number = 0;

	//�J�����f�o�C�X�I�[�v��
	VideoCapture cap1(0);//0��PC�����̃J�����A1�ȍ~��USB�ڑ����ꂽ�J����
	VideoCapture cap2(1);
	if (!cap1.isOpened() || !cap2.isOpened()) return -1;

	while (1)
	{
		Mat frame1;
		Mat frame2;
		cap1 >> frame2;	//�J��������t���[�����擾
		cap2 >> frame1;

		imshow("Monitor1", frame1);
		imshow("Monitor2", frame2);

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
			imwrite(name.str(), frame1);
		}
	}
	destroyAllWindows();
	return 0;
}