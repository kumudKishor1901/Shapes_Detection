#include<iostream>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void getContours(Mat imgDilate, Mat img) {
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDilate, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	vector<vector<Point>> cornerPoint(contours.size());
	vector<Rect> boundRect(contours.size());
	string objType;
	for (int i = 0; i < contours.size(); i++) {
		int area = contourArea(contours[i]);
		cout << area << endl;
		if (area >= 1000) {

			float perimeter = arcLength(contours[i], true);
			approxPolyDP(contours[i], cornerPoint[i], 0.02 * perimeter, true);
			cout << cornerPoint[i] << endl;
			boundRect[i] = boundingRect(cornerPoint[i]);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 250, 0), 2);
			drawContours(img, cornerPoint, i, Scalar(250, 0, 250), 1);

			int objCorner = (int)cornerPoint[i].size();
			if (objCorner == 3) { objType = "Triangle"; }
			else if (objCorner == 4) {
				float aspectRatio = (float)boundRect[i].width / boundRect[i].height;
				if (aspectRatio > 0.92 && aspectRatio < 1.2) {
					objType = "square";
				}
				else {
					objType = "Rectangle";
				}
			}
			else if (objCorner > 4) { objType = "Circle"; }

			putText(img, objType, Point(boundRect[i].x, boundRect[i].y - 5), FONT_HERSHEY_SIMPLEX, 0.3, Scalar(250, 0, 0), 1);

		}


	}
}

int main() {
	Mat img, imgGray, imgBlur, imgCanny, imgDilate;
	string path = "Resources/shapes.png";
	img = imread(path);
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 5, 0);
	Canny(imgGray, imgCanny, 50, 150);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	dilate(imgCanny, imgDilate, kernel);
	getContours(imgDilate, img);

	imshow("img", img);
	//imshow("imgDilate", imgDilate);
	//imshow("imgCanny", imgCanny);

	waitKey(0);


	return 0;
}