#include <iostream>
#include <string>
#include <locale.h> 
#include <windows.h>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2\opencv.hpp>

using namespace std;


int main()
{
	int tus;
	cv::Mat ekran(640,640,CV_8UC3),temp,araekran;
	ekran = cv::Scalar(0, 0, 0);
	ekran.copyTo(araekran);
	cv::namedWindow("labirent", cv::WINDOW_AUTOSIZE);
	cv::Point pt1(0, 0);
	cv::Point pt2(15, 15);
	cv::Point l1pt1(80, 0), l1pt2(80, 600);
	cv::Point l2pt1(160,40), l2pt2(160,640);
	cv::Point l3pt1(240,0), l3pt2(240,300);
	cv::Point l4pt1(240,340), l4pt2(240,640);
	cv::Point l5pt1(320,40), l5pt2(320,600);
	cv::Point finispt1(400, 300), finispt2(440, 340);
	cv::Point textpt(460, 320),textpt2(50,50);
	system("color c");

	cv::rectangle(ekran, finispt1, finispt2, cv::Scalar(255, 255, 255), -1);
	cv::putText(ekran, "Finish", textpt, cv::FONT_HERSHEY_COMPLEX, 0.8, cv::Scalar(255, 255, 0));
	cv::line(ekran, l1pt1, l1pt2, cv::Scalar(0, 0, 255), 1);
	cv::line(ekran, l2pt1, l2pt2, cv::Scalar(0, 0, 255), 1);
	cv::line(ekran, l3pt1, l3pt2, cv::Scalar(0, 0, 255), 1);
	cv::line(ekran, l4pt1, l4pt2, cv::Scalar(0, 0, 255), 1);
	cv::line(ekran, l5pt1, l5pt2, cv::Scalar(0, 0, 255), 1);

	cv::putText(araekran, "Well Done Level 1 Complate", textpt2, cv::FONT_HERSHEY_COMPLEX, 0.8, cv::Scalar(100, 255, 200));
	



	ekran.copyTo(temp);
	while (true)
	{




		cv::rectangle(ekran, pt1, pt2, cv::Scalar(0, 255, 0), -1,cv::LINE_8,0);
		char a = cv::waitKey(50);
		tus = (int)a;
		switch ((int)a)
		{
		case 119:
			if (pt1.y == 0) {
				break;
			}
			else {
				pt1.y-=5;
				pt2.y-=5;
			}
			break;
		case 97:
			if (pt1.x == 0) {
				break;
			}
			else {
				pt1.x-= 5;
				pt2.x-= 5;
			}
			break;
		case 115:
			if (pt2.y == 640) {
				break;
			}
			else {
				pt1.y+= 5;
				pt2.y+= 5;
			}
			break;
		case 100:
			if (pt2.x == 640) {
				break;
			}
			else {
				pt1.x+= 5;
				pt2.x+= 5;
			}
			break;

		default:
			system("cls");
			break;
		}

		if (pt1.x == 80 || pt2.x == 80) {
			if (pt1.y >= 0 && pt1.y <= 600) {
				pt1.x = 0;
				pt1.y = 0;
				pt2.x = 15;
				pt2.y = 15;
			}
			else if (pt2.y >= 0 && pt2.y <= 600) {
				pt1.x = 0;
				pt1.y = 0;
				pt2.x = 15;
				pt2.y = 15;
			}
		}

		if (pt1.x == 160 || pt2.x == 160) {
			if (pt1.y >= 40 && pt1.y <= 640) {
				pt1.x = 0;
				pt1.y = 0;
				pt2.x = 15;
				pt2.y = 15;
			}
			else if (pt2.y >= 40 && pt2.y <= 640) {
				pt1.x = 0;
				pt1.y = 0;
				pt2.x = 15;
				pt2.y = 15;
			}
		}

		if (pt1.x == 240 || pt2.x == 240) {
			if ((pt1.y >= 0 && pt1.y <= 300)|| (pt1.y >= 340 && pt1.y <= 640)) {
				pt1.x = 0;
				pt1.y = 0;
				pt2.x = 15;
				pt2.y = 15;
			}
			else if ((pt2.y >= 0 && pt2.y <= 300) || (pt2.y >= 340 && pt2.y <= 640)) {
				pt1.x = 0;
				pt1.y = 0;
				pt2.x = 15;
				pt2.y = 15;
			}
		}

		if (pt1.x == 320 || pt2.x == 320) {
			if (pt1.y >= 40 && pt1.y <= 600) {
				pt1.x = 0;
				pt1.y = 0;
				pt2.x = 15;
				pt2.y = 15;
			}
			else if (pt2.y >= 40 && pt2.y <= 600) {
				pt1.x = 0;
				pt1.y = 0;
				pt2.x = 15;
				pt2.y = 15;
			}
		}



		if (pt1.x >= 400 && pt1.x <= 440 && pt2.x >= 400 && pt2.x <= 440 && pt1.y >= 300 && pt1.y <= 340 && pt2.y >= 300 && pt2.y <= 340) {
			araekran.copyTo(ekran);
		}



		cv::imshow("labirent", ekran);
		if (a == 27) {
			break;
		}
		temp.copyTo(ekran);
	}


}
