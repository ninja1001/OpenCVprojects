#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

int main()
{
	std::string path = "/home/abraham/Downloads/mario.png";

	cv::Mat img=cv::imread(path);

	cv::Mat imgGray,imgBlur,imgCanny,imgDil,imgErode;

	cv::resize(img,img,cv::Size(500,500));      
    cv::resize(img,imgGray,cv::Size(500,500));
    cv::resize(img,imgBlur,cv::Size(500,500));
    cv::resize(img,imgCanny,cv::Size(500,500));
    cv::resize(img,imgDil,cv::Size(500,500));

	cv::cvtColor(img,imgGray,cv::COLOR_BGR2GRAY);
	cv::GaussianBlur(img, imgBlur, cv::Size(3,3),3,0);
	cv::Canny(imgBlur, imgCanny, 25,75);

	cv::Mat kernel = getStructuringElement(cv::MORPH_RECT, cv::Size(5,5));
	cv::dilate(imgCanny, imgDil, kernel);

	cv::imshow("Image",img);
	cv::imshow("Image Gray", imgGray);
	cv::imshow("Image Blur", imgBlur);
	cv::imshow("Image Canny", imgCanny);
	cv::imshow("Image Dilation", imgDil);

	cv::waitKey(0);

	return 0;
}
