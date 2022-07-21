#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

int main()
{
	float width = 250;
	float height = 350;

	cv::Mat matrix;
	cv::Mat imgWarp;

	std::string path = "/home/abraham/Downloads/img.jpg";

	cv::Mat img = cv::imread(path);

	cv::Point2f src[4] = { {529,142},{771,190},{405,395},{674,457} };
	cv::Point2f dst[4] = { {0.0f,0.0f},{width,0.0f},{0.0f,height},{width,height} };

	matrix = cv::getPerspectiveTransform(stc, dst);
	cv::warpPerspective(img,imgWarp,matrix,Point(width,height));

	imshow("Image",imgWarp);
	
	cv::waitKey(0);

	return 0;
}
