#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	//***************
	//画像を読み込む
	//***************
	Mat templateImage = imread("E:\\Pictures\\標準画像\\maya.jpg");
	Mat dstImage = imread("E:\\Pictures\\標準画像\\gochiusa.jpg");
	if (templateImage.data == NULL || dstImage.data == NULL)
	{
		cout << "画像ファイルが読み込めませんでした" << endl;
		return -1;
	}
	
	//グレイ画像に変換
	Mat t_gray;
	Mat d_gray;
	cvtColor(templateImage, t_gray, CV_BGR2GRAY);
	cvtColor(dstImage, d_gray, CV_BGR2GRAY);
	equalizeHist(t_gray, t_gray);
	equalizeHist(d_gray, d_gray);
	
	//****************************
	//キーポイント検出&特徴量記述
	//****************************
	//抽出された記述子のタイプ, 記述子サイズ, 記述子チャンネル, 閾値, オクターブ, オクターブレイヤー, 拡散率
	Ptr<Feature2D> detector = AKAZE::create();
	vector<KeyPoint> keypoints1, keypoints2;
	Mat descriptors1, descriptors2;
	detector->detectAndCompute(t_gray, noArray(), keypoints1, descriptors1);
	detector->detectAndCompute(d_gray, noArray(), keypoints2, descriptors2);

	//***********
	//マッチング
	//***********
	auto matchtype = detector->defaultNorm();
	BFMatcher matcher(matchtype);
	vector<vector<DMatch>> knnMatches;
	matcher.knnMatch(descriptors1, descriptors2, knnMatches, 2);

	//*************
	//対応点を絞る
	//*************
	const auto matchPar = .6f;	//対応点の閾値
	std::vector<DMatch> goodMatches;

	std::vector<Point2f> matchPoint1;
	std::vector<Point2f> matchPoint2;

	for (size_t i = 0; i < knnMatches.size(); i++)
	{
		auto dist1 = knnMatches[i][0].distance;
		auto dist2 = knnMatches[i][1].distance;

		//いい点を残す(最も類似する点と次に類似する点の類似度から)
		if (dist1 <= dist2 * matchPar)
		{
			goodMatches.push_back(knnMatches[i][0]);
			matchPoint1.push_back(keypoints1[knnMatches[i][0].queryIdx].pt);
			matchPoint2.push_back(keypoints2[knnMatches[i][0].trainIdx].pt);
		}
	}

	//ホモグラフィ行列の推定
	//ホモグラフィ(射影変換)とは? - 平面を射影変換を用いて別の平面に射影すること。パノラマ合成に使われる。
	//今回はホモグラフィー行列でテンプレートイメージの枠を対象イメージに合致させる。
	Mat masks;
	Mat Homo;
	if (matchPoint1.size() != 0 && matchPoint2.size() != 0)
	{
		Homo = findHomography(matchPoint1, matchPoint2, masks, RANSAC, 3.f);
	}

	//RANSACで使用された点のみ抽出
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
		//対象物体画像からコーナーを取得(対応物体が"検出"される)
		vector<Point2f> obj_corners(4);
		obj_corners[0] = Point2f(.0f, .0f);
		obj_corners[1] = Point2f(static_cast<float>(templateImage.cols), .0f);
		obj_corners[2] = Point2f(static_cast<float>(templateImage.cols), static_cast<float>(templateImage.rows));
		obj_corners[3] = Point2f(.0f, static_cast<float>(templateImage.rows));

		//シーンへの射影を推定
		vector<Point2f> scene_corners(4);
		perspectiveTransform(obj_corners, scene_corners, Homo);

		//コーナー間を線で結ぶ(シーン中のマップされた対象物体 - シーン画像)
		line(dstImage, scene_corners[0], scene_corners[1], Scalar(0, 255, 0), 4);
		line(dstImage, scene_corners[1], scene_corners[2], Scalar(0, 255, 0), 4);
		line(dstImage, scene_corners[2], scene_corners[3], Scalar(0, 255, 0), 4);
		line(dstImage, scene_corners[3], scene_corners[0], Scalar(0, 255, 0), 4);
	}
	//******
	//描画
	//******
	//特徴点の描画
	Mat matchImage;
	drawMatches(templateImage, keypoints1, dstImage, keypoints2, knnMatches, matchImage);
	namedWindow("マッチング結果");
	imshow("マッチング結果", matchImage);
	imwrite("image\\matchImage.jpg", matchImage);

	//良い特徴点の描画
	drawMatches(templateImage, keypoints1, dstImage, keypoints2, goodMatches, matchImage);
	namedWindow("マッチング結果(good)");
	imshow("マッチング結果(good)", matchImage);
	imwrite("image\\matchImage(good).jpg", matchImage);

	//インライアの対応点のみ描画
	drawMatches(templateImage, keypoints1, dstImage, keypoints2, inlierMatches, matchImage);
	namedWindow("マッチング結果(inlier)");
	imshow("マッチング結果(inlier)", matchImage);
	imwrite("image\\matchImage(inlier).jpg", matchImage);

	waitKey(0);
	destroyAllWindows();
	return 0;
}