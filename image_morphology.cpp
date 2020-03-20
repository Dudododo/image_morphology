#include <iostream>
#include <opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	cv::Mat img = imread("coin.png", 0);
	cv::Mat img1, img2;

	//二值化
	threshold(img, img1, 0, 255, THRESH_OTSU);
	imshow("otsu", img1);

	//创建结构元素
	Mat kernel = getStructuringElement(MORPH_CROSS, Size(3, 3));

	//腐蚀
	erode(img1, img2, kernel);
	imshow("erode", img2);

	//膨胀
	dilate(img1, img2, kernel);
	imshow("dilate", img2);

	//开运算
	morphologyEx(img1, img2, MORPH_OPEN, kernel);
	imshow("open", img2);

	//闭运算
	morphologyEx(img1, img2, MORPH_CLOSE, kernel);
	imshow("close", img2);

	waitKey(0);
	return 0;
}

