#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;
using namespace std;

int use_opencv() {
	string image_address = "C:/Users/GIGABYTE/Desktop/temporary/target1.bmp";
	Mat raw_image = imread(image_address,IMREAD_GRAYSCALE);
	CV_Assert(raw_image.data);
	Mat sub_image;

	int x = 300;
	int y = 300;
	int width = 300;
	int height = 300;
	int wrong_x = 230;
	int wrong_y = 240;
	int trans_x, trans_y;
	//make template
	Rect bounds(0, 0, raw_image.cols, raw_image.rows);
	Rect stand_r(x, y, width, height);
	Mat stand_roi = raw_image(stand_r & bounds);
	Mat stand_mean;
	Scalar stand_stddev;

	//initialization
	Rect com_r(wrong_x, wrong_y, width, height);
	Mat com_roi = raw_image(com_r & bounds);
	subtract(stand_roi, com_roi, sub_image);
	meanStdDev(sub_image, stand_mean, stand_stddev);

	//cross-correlation
	for (int i = 0; i <= 100; i += 10) {
		for (int j = 0; j <= 100; j += 10) {
			Mat com_mean;
			Scalar com_stddev;
			Rect com_r(wrong_x + i, wrong_y + j, width, height);
			Mat com_roi = raw_image(com_r & bounds);
			subtract(stand_roi, com_roi, sub_image);
			meanStdDev(sub_image, com_mean, com_stddev);
			imshow("running", sub_image);
			cout << "i : " << i << ", j : " << j << ",   ";
			for (int k = 0; k < 4; k++) {
				cout << k << " : " << com_stddev(k) << ", ";
			}
			cout << endl;
			//waitKey(0);
			if(com_stddev(0) <= stand_stddev(0)) {
				trans_x = i;
				trans_y = j;
				Rect trans_r(wrong_x + i, wrong_y + j, width, height);
				Mat stand_roi = raw_image(trans_r & bounds);
				stand_stddev = com_stddev;
			}
		}
	}
	
	//correct one
	Rect result_r(wrong_x + trans_x, wrong_y + trans_y, width, height);
	Mat result_roi = raw_image(result_r & bounds);

	cout << "transed x = " << trans_x << endl;
	cout << "transed y = " << trans_y << endl;

	for (int i = 0; i < 4; i++) {
		cout << i << " : " << stand_stddev(i) << endl;
	}

	imshow("correct one", result_roi);
	waitKey(0);
	

	return 0;
}