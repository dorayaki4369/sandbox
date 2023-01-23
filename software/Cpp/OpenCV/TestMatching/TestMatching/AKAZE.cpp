#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	//***************
	//�摜��ǂݍ���
	//***************
	Mat templateImage = imread("E:\\Pictures\\�W���摜\\maya.jpg");
	Mat dstImage = imread("E:\\Pictures\\�W���摜\\gochiusa.jpg");
	if (templateImage.data == NULL || dstImage.data == NULL)
	{
		cout << "�摜�t�@�C�����ǂݍ��߂܂���ł���" << endl;
		return -1;
	}
	
	//�O���C�摜�ɕϊ�
	Mat t_gray;
	Mat d_gray;
	cvtColor(templateImage, t_gray, CV_BGR2GRAY);
	cvtColor(dstImage, d_gray, CV_BGR2GRAY);
	equalizeHist(t_gray, t_gray);
	equalizeHist(d_gray, d_gray);
	
	//****************************
	//�L�[�|�C���g���o&�����ʋL�q
	//****************************
	//���o���ꂽ�L�q�q�̃^�C�v, �L�q�q�T�C�Y, �L�q�q�`�����l��, 臒l, �I�N�^�[�u, �I�N�^�[�u���C���[, �g�U��
	Ptr<Feature2D> detector = AKAZE::create();
	vector<KeyPoint> keypoints1, keypoints2;
	Mat descriptors1, descriptors2;
	detector->detectAndCompute(t_gray, noArray(), keypoints1, descriptors1);
	detector->detectAndCompute(d_gray, noArray(), keypoints2, descriptors2);

	//***********
	//�}�b�`���O
	//***********
	auto matchtype = detector->defaultNorm();
	BFMatcher matcher(matchtype);
	vector<vector<DMatch>> knnMatches;
	matcher.knnMatch(descriptors1, descriptors2, knnMatches, 2);

	//*************
	//�Ή��_���i��
	//*************
	const auto matchPar = .6f;	//�Ή��_��臒l
	std::vector<DMatch> goodMatches;

	std::vector<Point2f> matchPoint1;
	std::vector<Point2f> matchPoint2;

	for (size_t i = 0; i < knnMatches.size(); i++)
	{
		auto dist1 = knnMatches[i][0].distance;
		auto dist2 = knnMatches[i][1].distance;

		//�����_���c��(�ł��ގ�����_�Ǝ��ɗގ�����_�̗ގ��x����)
		if (dist1 <= dist2 * matchPar)
		{
			goodMatches.push_back(knnMatches[i][0]);
			matchPoint1.push_back(keypoints1[knnMatches[i][0].queryIdx].pt);
			matchPoint2.push_back(keypoints2[knnMatches[i][0].trainIdx].pt);
		}
	}

	//�z���O���t�B�s��̐���
	//�z���O���t�B(�ˉe�ϊ�)�Ƃ�? - ���ʂ��ˉe�ϊ���p���ĕʂ̕��ʂɎˉe���邱�ƁB�p�m���}�����Ɏg����B
	//����̓z���O���t�B�[�s��Ńe���v���[�g�C���[�W�̘g��ΏۃC���[�W�ɍ��v������B
	Mat masks;
	Mat Homo;
	if (matchPoint1.size() != 0 && matchPoint2.size() != 0)
	{
		Homo = findHomography(matchPoint1, matchPoint2, masks, RANSAC, 3.f);
	}

	//RANSAC�Ŏg�p���ꂽ�_�̂ݒ��o
	vector<DMatch> inlierMatches;
	for (auto i = 0; i < masks.rows; i++)
	{
		uchar* inlier = masks.ptr<uchar>(i);
		if (inlier[0] == 1)
		{
			inlierMatches.push_back(goodMatches[i]);
		}
	}

	if (!Homo.empty())
	{
		//�Ώە��̉摜����R�[�i�[���擾(�Ή����̂�"���o"�����)
		vector<Point2f> obj_corners(4);
		obj_corners[0] = Point2f(.0f, .0f);
		obj_corners[1] = Point2f(static_cast<float>(templateImage.cols), .0f);
		obj_corners[2] = Point2f(static_cast<float>(templateImage.cols), static_cast<float>(templateImage.rows));
		obj_corners[3] = Point2f(.0f, static_cast<float>(templateImage.rows));

		//�V�[���ւ̎ˉe�𐄒�
		vector<Point2f> scene_corners(4);
		perspectiveTransform(obj_corners, scene_corners, Homo);

		//�R�[�i�[�Ԃ���Ō���(�V�[�����̃}�b�v���ꂽ�Ώە��� - �V�[���摜)
		line(dstImage, scene_corners[0], scene_corners[1], Scalar(0, 255, 0), 4);
		line(dstImage, scene_corners[1], scene_corners[2], Scalar(0, 255, 0), 4);
		line(dstImage, scene_corners[2], scene_corners[3], Scalar(0, 255, 0), 4);
		line(dstImage, scene_corners[3], scene_corners[0], Scalar(0, 255, 0), 4);
	}
	//******
	//�`��
	//******
	//�����_�̕`��
	Mat matchImage;
	drawMatches(templateImage, keypoints1, dstImage, keypoints2, knnMatches, matchImage);
	namedWindow("�}�b�`���O����");
	imshow("�}�b�`���O����", matchImage);
	imwrite("image\\matchImage.jpg", matchImage);

	//�ǂ������_�̕`��
	drawMatches(templateImage, keypoints1, dstImage, keypoints2, goodMatches, matchImage);
	namedWindow("�}�b�`���O����(good)");
	imshow("�}�b�`���O����(good)", matchImage);
	imwrite("image\\matchImage(good).jpg", matchImage);

	//�C�����C�A�̑Ή��_�̂ݕ`��
	drawMatches(templateImage, keypoints1, dstImage, keypoints2, inlierMatches, matchImage);
	namedWindow("�}�b�`���O����(inlier)");
	imshow("�}�b�`���O����(inlier)", matchImage);
	imwrite("image\\matchImage(inlier).jpg", matchImage);

	waitKey(0);
	destroyAllWindows();
	return 0;
}