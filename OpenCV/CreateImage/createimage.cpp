#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main()
{
	cv::Mat img(512,512, CV_8UC3, cv::Scalar(255,255,255));

	cv::circle(img,cv::Point(256,256), 155, cv::Scalar(0,69,255),cv::FILLED);

	cv::putText(img, "Abraham's Workshop", cv::Point(137,262), cv::FONT_HERSHEY_DUPLEX, 0.5, cv::Scalar(255,255,255),2);

	cv::imshow("Image", img);

	cv::waitKey(0);

	return 0;
}
