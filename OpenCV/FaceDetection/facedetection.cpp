#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>

int main()
{
	std::string path = "/home/abraham/Downloads/img.jpeg";
	cv::Mat img = cv::imread(path);
	
	cv::resize(img, img, cv::Size(600,500));

	cv::CascadeClassifier faceCascade;
	faceCascade.load("/home/abraham/Downloads/face.xml");

	std::vector<cv::Rect> faces;
	faceCascade.detectMultiScale(img, faces, 1.1, 10);

	for(int i = 0; i < faces.size();++i)
	{
		cv::rectangle(img, faces[i].tl(), faces[i].br(), cv::Scalar(255,0,255),3);
	}

	cv::imshow("Image", img);

	cv::waitKey(0);
	
	return 0;
}
