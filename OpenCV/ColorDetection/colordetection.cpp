#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

int main()
{
	cv::Mat imgHSV;
	cv::Mat mask;
	cv::Mat img;
	
	int hmin = 0;
	int hmax = 0;
	int vmin = 0;
	int vmax = 0;
	int smin = 0;
	int smax = 0;

	std::string path = "/home/abraham/Downloads/mario.png";

	img = cv::imread(path);
	
	cv::resize(img, img, cv::Size(500,500));
    cv::resize(img, imgHSV, cv::Size(500,500));
    cv::resize(img, mask, cv::Size(500,500));
	
	cv::cvtColor(img, imgHSV, cv::COLOR_BGR2HSV);

	cv::namedWindow("Trackbars", (500,500));
	cv::createTrackbar("HMIN", "Trackbars", &hmin, 255);
	cv::createTrackbar("HMAX", "Trackbars", &hmax, 255);
	cv::createTrackbar("SMIN", "Trackbars", &smin, 255);
	cv::createTrackbar("SMAX", "Trackbars", &smax, 255);
	cv::createTrackbar("VMIN", "Trackbars", &vmin, 255);
	cv::createTrackbar("VMAX", "Trackbars", &vmax, 255);

	while(true)
	{			
		cv::Scalar lower(hmin, smin, vmin);
    	cv::Scalar upper(hmax, smax, vmax);
							
		cv::inRange(imgHSV, lower, upper, mask);

		cv::imshow("Image", img);
		cv::imshow("Image HSV", imgHSV);
		cv::imshow("Image Mask", mask);

		cv::waitKey(1);
	}
	
	return 0;
}
