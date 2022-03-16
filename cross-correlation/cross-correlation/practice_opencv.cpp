#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;
using namespace std;
/*
int main() {
	//이미지 주소 문자열로 저장
	string filelocation = "C:/Users/GIGABYTE/Desktop/temporary/target.bmp";
	string filelocation2 = "C:/Users/GIGABYTE/Desktop/temporary/target2.bmp";
	//이미지 불러오기
	Mat target = imread(filelocation, IMREAD_GRAYSCALE);
	Mat target2 = imread(filelocation2, IMREAD_GRAYSCALE);

	//괄호 안의 문장이거짓이면 에러가 발생하여 프로그램 종료, 이미지 예외 처리
	CV_Assert(target.type() == CV_8UC1);
	CV_Assert(target.data);
	CV_Assert(target2.data);

	//나중에 사용할 함수 matchTemplate

	Mat m1(3,6, CV_8UC1, Scalar(30));
	Mat submatrix;
	Mat mask(m1.size(),CV_8UC1);
	Rect rect(Point(3, 0), Size(3, 3));
	mask(rect).setTo(1);
	
	subtract(m1, mask, submatrix, mask);
	cout << "submatrix = " << endl << submatrix << endl;


	//출력
	cout << "행렬 좌표 (100,100) 화소 값" << endl;
	
	//이미지 출력
	imshow("target", target);
	imshow("target2", target2);
	waitKey(0);


	//이제부터 다른 프로그램

	Mat image1 = imread("C:/Users/GIGABYTE/Desktop/temporary/target1.bmp", IMREAD_GRAYSCALE);
	Mat image2 = imread("C:/Users/GIGABYTE/Desktop/temporary/target2.bmp", IMREAD_GRAYSCALE);
	CV_Assert(image1.data);
	CV_Assert(image2.data);
	Mat sub_image2, sub_image3, resize_image;

	int x = 300;
	int y = 300;
	int width = 300;
	int height = 300;
	Mat mean2, stddev2;
	Mat mean3, stddev3;
	Rect bounds1(0, 0, image1.cols, image1.rows);
	Rect bounds2(0, 0, image2.cols, image2.rows);
	Rect r1(x, y, width, height);
	Rect r2(x+150, y, width, height);
	Mat roi1 = image1(r1 & bounds1);
	Mat roi2 = image2(r2 & bounds2);
	Mat roi3 = image2(r1 & bounds2);
	
	subtract(roi1, roi2, sub_image2);
	subtract(roi1, roi3, sub_image3);
	meanStdDev(sub_image2, mean2, stddev2);
	meanStdDev(sub_image3, mean3, stddev3);

	cout << stddev2 << endl << stddev3 << endl;

	imshow("sub_cropped image", sub_image2);
	imshow("sub_cropped image2", sub_image3);
	imshow("sub_image", image1);
	waitKey(0);
	return 0;
}
*/