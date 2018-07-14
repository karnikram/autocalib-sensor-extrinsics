#include <core_gui/CCalibFromLinesGui.h>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <mrpt/obs/CObservation3DRangeScan.h>

using namespace mrpt::obs;

CCalibFromLinesGui::CCalibFromLinesGui(CObservationTreeModel *model, std::vector<std::vector<int>> &sync_obs_indices) :
    m_model(model)
	
{
}

CCalibFromLinesGui::~CCalibFromLinesGui()
{
}

void CCalibFromLinesGui::extractLines()
{
	CObservationTreeItem *root_item, *tree_item;
	CObservation3DRangeScan::Ptr obs_item;

	//testing with the first item alone
	root_item = m_model->getRootItem();
	obs_item = std::dynamic_pointer_cast<CObservation3DRangeScan>(root_item->child(0)->child(0)->getObservation());

	cv::Mat image = cv::cvarrToMat(obs_item->intensityImage.getAs<IplImage>());
	// std::vector<cv::Vec4i> segments = runSegmentation(image);
}

std::vector<cv::Vec4i> CCalibFromLinesGui::runSegmentation(const cv::Mat &image)
{

//	int low_threshold = 150;
//	int ratio = 3;
//	int kernel_size = 3;

//	cv::Mat canny_image;

//	cv::Canny(image, canny_image, low_threshold, low_threshold * ratio, kernel_size);

//	std::vector<cv::Vec2f> lines;
//	std::vector<cv::Vec4i> segments;

//	cv::HoughLines(canny_image, lines, 1, CV_PI, low_threshold);

//	double rho, theta;
//	double cos_theta, sin_theta;
//	double m, c, c_max;

//	int x, y, xf, yf;

//	for(size_t n(0); n < lines.size(); n++)
//	{
//		if(lines[n][0] < 0)
//		{
//			rho = -lines[n][0];
//			theta = lines[n][1] - CV_PI;
//		}

//		else
//		{
//			rho = lines[n][0];
//			theta = lines[n][1];
//		}

//		if (rho == 0 && theta == 0)
//			continue;

//		if (fabs(theta) < 0.00001)
//		{
//			x = xf = static_cast<int>(rho + 0.5);
//			y = 0;
//			yf = canny_image.rows - 1;
//		}

//		else
//		{
//			cos_theta = cos(theta);
//			sin_theta = sin(theta);
//			m = -cos_theta / sin_theta;
//			c = rho * (sin_theta - m * cos_theta);

//			if (c >= 0)
//			{
//				if (c < canny_image.rows)
//				{
//					x = 0;
//					y = static_cast<int>(c);
//				}
//				else
//				{
//					y = canny_image.rows - 1;
//					x = static_cast<int>((y - c) / m);
//				}
//			}

//			else
//			{
//				x = static_cast<int>(-c / m);
//				y = 0;
//			}

//			c_max = m * (canny_image.cols - 1) + c;
//			if (c_max >= 0)
//			{
//				if (c_max < canny_image.rows)
//				{
//					xf = canny_image.cols - 1;
//					yf = static_cast<int>(c_max);
//				}

//				else
//				{
//					yf = canny_image.rows - 1;
//					xf = static_cast<int>((yf - c) / m);
//				}
//			}
//			else
//			{
//				xf = static_cast<int>(-c / m);
//				yf = 0;
//			}

//		}

//		// Bresenham algorithm

//		bool onSegment = false;
//		int memory;
//		int memoryX = 0, memoryY = 0;
//		int xPrev = 0, yPrev = 0;
//		size_t nbPixels = 0;

//		int w = xf - x;
//		int h = yf - y;
//		int dx1, dy1, dx2, dy2 = 0;

//		int longest, shortest;
//		int numerator;

//		if (w < 0)
//		{
//			longest = -w;
//			dx1 = -1;
//			dx2 = -1;
//		}
//		else
//		{
//			longest = w;
//			dx1 = 1;
//			dx2 = 1;
//		}

//		if (h < 0)
//		{
//			shortest = -h;
//			dy1 = -1;
//		}

//		else
//		{
//			shortest = h;
//			dy1 = 1;
//		}

//		if (longest <= shortest)
//		{
//			memory = longest;
//			longest = shortest;
//			shortest = memory;
//			dx2 = 0;
//			if (h < 0)
//			{
//				dy2 = -1;
//			}

//			else
//			{
//				dy2 = 1;
//			}
//		}

//		numerator = longest / 2;

//		for (int i(0); i <= longest; ++i)
//		{
//			if (onSegment)
//			{
//				if (canny_image.at<char>(y, x) == 0 || i == longest)
//				{
//					onSegment = false;
//					if (nbPixels >= low_threshold)
//					{
//						segments.push_back(cv::Vec4i(memoryX, memoryY, xPrev, yPrev));
//					}
//				}

//				else
//				{
//					++nbPixels;
//				}
//			}
//			else if (canny_image.at<char>(y, x) != 0)
//			{
//				onSegment = true;
//				nbPixels = 0;
//				memoryX = x;
//				memoryY = y;
//			}

//			xPrev = x;
//			yPrev = y;

//			numerator += shortest;

//			if(numerator >= longest)
//			{
//				numerator -= longest;
//				x += dx1;
//				y += dy1;
//			}

//			else
//			{
//				x += dx2;
//				y += dy2;
//			}
//		}
//	}

//	return segments;
}