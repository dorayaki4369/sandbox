//*******************
//注意!
//やっつけ仕事なので時々エラーが発生して停止するときがあります。すみません。
//原因が分かった方はお教え下さい。
//*******************

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <opencv2\opencv.hpp>
#include <Windows.h>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	int image_number = 0;

	//***************
	//画像を読み込み&カメラデバイスオープン
	//***************
	Mat src_image = imread("image\\lena.png");
	Mat frame, match_image;
	VideoCapture cap(0);	//0はPC内臓のカメラ、1以降はUSB接続されたカメラ
	if (src_image.data == NULL)
	{
		cout << "画像ファイルを開けませんでした" << endl;
		OutputDebugStringA("画像ファイルを開けませんでした\n");
		return -1;
	}
	if (!cap.isOpened())
	{
		cout << "カメラデバイスを開けませんでした" << endl;
		OutputDebugStringA("カメラデバイスを開けませんでした\n");
		return -1;
	}
	//動画書き込みクラスのインスタンス生成
	//VideoWriter writer("output.avi", CV_FOURCC_DEFAULT, 10, Size(640, 480), true);

	//***********
	//特徴量記述
	//***********
	//グレイ画像に変換(画像)
	Mat src_gray;
	cvtColor(src_image, src_gray, CV_BGR2GRAY);
	equalizeHist(src_gray, src_gray);

	//キーポイント検出&特徴量記述(画像)
	//抽出された記述子のタイプ, 記述子サイズ, 記述子チャンネル, 閾値, オクターブ, オクターブレイヤー, 拡散率
	Ptr<Feature2D> detector = ORB::create();
	vector<KeyPoint> keypoints1, keypoints2;
	Mat descriptors1, descriptors2;
	detector->detectAndCompute(src_gray, noArray(), keypoints1, descriptors1);

	for (;;)
	{
		//*************
		//コマンド入力
		//*************
		int key = waitKey(1);
		if (key == 113)			//qキーを押した場合抜ける
		{
			break;
		}
		else if (key == 115)	//sキーでスクショ
		{
			image_number++;
			stringstream name;
			name.str("");
			name << "img" << setw(3) << setfill('0') << image_number << ".jpg";
			imwrite(name.str(), frame);
		}

		//カメラからフレームを取得
		cap >> frame;

		//グレイスケールに変換(動画)
		Mat frame_gray, frame_bin;
		cvtColor(frame, frame_gray, CV_BGR2GRAY);
		equalizeHist(frame_gray, frame_gray);
		threshold(frame_gray, frame_bin, 0, 255, THRESH_BINARY | THRESH_OTSU); //閾値を自動で設定

		//キーポイント検出&特徴量記述(動画)
		detector->detectAndCompute(frame_bin, noArray(), keypoints2, descriptors2);

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
		vector<Point2f> matchPoint1;
		vector<Point2f> matchPoint2;

		vector<DMatch> goodMatches;
		const auto matchPar = .6f;	//対応点の閾値

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
		Mat homo;
		if (matchPoint1.size() != 0 && matchPoint2.size() != 0)
		{
			homo = findHomography(matchPoint1, matchPoint2, masks, RANSAC, 3.f);
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

		if (!homo.empty())
		{
			//対象物体画像からコーナーを取得(対応物体が"検出"される)
			vector<Point2f> obj_corners(4);
			obj_corners[0] = Point2f(.0f, .0f);
			obj_corners[1] = Point2f(static_cast<float>(src_image.cols), .0f);
			obj_corners[2] = Point2f(static_cast<float>(src_image.cols), static_cast<float>(src_image.rows));
			obj_corners[3] = Point2f(.0f, static_cast<float>(src_image.rows));

			//シーンへの射影を推定
			vector<Point2f> scene_corners(4);
			perspectiveTransform(obj_corners, scene_corners, homo);

			//コーナー間を線で結ぶ(シーン中のマップされた対象物体 - シーン画像)
			line(frame, scene_corners[0], scene_corners[1], Scalar(0, 255, 0), 4);
			line(frame, scene_corners[1], scene_corners[2], Scalar(0, 255, 0), 4);
			line(frame, scene_corners[2], scene_corners[3], Scalar(0, 255, 0), 4);
			line(frame, scene_corners[3], scene_corners[0], Scalar(0, 255, 0), 4);

			//******
			//描画
			//******
			////特徴点の描画
			//drawMatches(src_image, keypoints1, frame, keypoints2, knnMatches, match_image);
			//imshow("マッチング結果(default)", matchImage);

			////良い特徴点の描画
			//drawMatches(src_image, keypoints1, frame, keypoints2, goodMatches, match_image);
			//imshow("マッチング結果(good)", matchImage);

			//インライアの対応点のみ描画
			drawMatches(src_image, keypoints1, frame, keypoints2, inlierMatches, match_image);
			imshow("マッチング結果", match_image);
			continue;
		}

		//ホモグラフィー行列ができなかった場合
		drawMatches(src_image, keypoints1, frame, keypoints2, knnMatches, match_image);
		imshow("マッチング結果", match_image);

		//動画出力
		//writer << match_image;
	}
	destroyAllWindows();
	return 0;
}