#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>


using namespace cv;
using namespace std;

int main() {
	//road image
	string image_address = "C:/Users/GIGABYTE/Desktop/temporary/target1.bmp";
	Mat image = imread(image_address, IMREAD_GRAYSCALE);
	CV_Assert(image.data);

	//image information
	int image_x = 1840;
	int image_y = 1840;
	// the value whati determine
	int x = 520;
	int y = 643;
	//template size
	int width = 200;
	int height = 200;
	//initialization max value
	int greatest_value = 255;
	
	//make template
	Rect bounds(0, 0, image.cols, image.rows);
	Rect temp_r(x, y, width, height);
	Mat temp_original = image(temp_r & bounds);
	Mat temp;
	temp_original.copyTo(temp); 
	
	//image pointer initialization
	uchar* temp_p = temp.data;
	uchar* com_start_p = image.data;
	uchar* com_p;

	//declare value what we looking
	int sub_average = 0;
	int min_sub_average = greatest_value;
	int trans_x;
	int trans_y;

	//cross correlation - comparison
	for (int i = 0; i < image_y - height; i += 1) {
		for (int j = 0; j < image_x - width; j += 1) {
			com_p = com_start_p + (image_x * i + j);
			sub_average = 0;
			for (int k = 0; k < height; k++) {
				for (int l = 0; l < width; l++) {
					unsigned char n1 = *(temp_p + width * k + l);
					unsigned char n2 = *(com_p + image_x * k + l);
					sub_average += abs((int)n1 - (int)n2);
				}
			}
			sub_average /= height;
			sub_average /= width;
			if (sub_average < min_sub_average) {
				min_sub_average = sub_average;
				trans_x = j;
				trans_y = i;
			}
			/*
			//matching process show
			cout << "sub_average = " << sub_average << endl;
			Rect result_r2(i, j, width, height);
			Mat result2 = image(result_r2 & bounds);
			imshow("it's what i looking for", temp);
			imshow("its what i found", result2);
			waitKey(0);
			*/
		}
	}

	//print value what we are looking for
	cout << "min_sub_average = " << min_sub_average << endl;
	cout << "transed x = " << trans_x << endl;
	cout << "transed y = " << trans_y << endl;
	
	//show images
	Rect result_r(trans_x, trans_y, width, height);
	Mat result = image(result_r & bounds);
	imshow("it's what i looking for", temp);
	imshow("its what i found", result);
	waitKey(0);

	return 0;
}