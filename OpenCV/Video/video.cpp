#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main()
{
	std::string path = "/home/abraham/Downloads/video.mp4";

	cv::VideoCapture cpt(path);

	cv::Mat img;

	while(true)
	{	
		cpt.read(img);

		cv::imshow("Image", img);
		cv::waitKey(20);
	}

	return 0;
}
