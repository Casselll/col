// col.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<string>
#include<vector>
#include<opencv2/features2d/features2d.hpp>
#include<opencv2/xfeatures2d.hpp>
#include<opencv2/xfeatures2d/nonfree.hpp>

using namespace std;
using namespace cv;



vector<vector<Mat> > input(string path)
{
	string folder_path = path;
	string rgb_folder_path = "path\\ref";
	string ref_folder_path = "path\\rgb";
	Mat imgpass,refimgpass;
	vector<string> rgb_file_names,ref_file_names;
	vector<Mat> rgb_img,ref_img;
	glob(rgb_folder_path, rgb_file_names);
	glob(ref_folder_path, ref_file_names);
	for (int i = 0; i < rgb_file_names.size(); i++)//考虑红外跟rgb怎么对齐,在文件夹下排序重命名
	{
		cout << rgb_file_names[i] << endl;
		imgpass = imread(rgb_file_names[i]); 
		rgb_img.push_back(imgpass);
	}
	for (int i = 0; i < ref_file_names.size(); i++)
	{
		cout << ref_file_names[i] << endl;
		refimgpass = imread(ref_file_names[i]);
		ref_img.push_back(refimgpass);
	}
	/*数据对齐*/
	vector < vector<Mat>> input;
	vector<Mat> img_pair;
	for (int i = 0; i < rgb_file_names.size(); i++)
	{
		img_pair.push_back(rgb_img[i]);
		img_pair.push_back(ref_img[i]);
		input.push_back(img_pair);//rgb和ref组成一个图像对，然后图像对堆叠成为input
	}
	return input;
}

int main()
{
    return 0;
}

