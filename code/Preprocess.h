#pragma once

#include<iostream>
#include<string>
#include<opencv.hpp>
#include <cmath>
#include "cv.h"
#include "highgui.h"
#include<conio.h>

#define PI 3.1415926

using namespace std;
using namespace cv;

class Image {
	private:
		IplImage* Imgin;									//ָ������ͼ��
		IplImage* Imgout;									//ָ�������ͼ��
		int rows, cols;										//ͼ��Ŀ�͸�
		int horiCenter, vertCenter;							//��ת���ĵ�
		int rotateR;										//��ת�뾶                                
		char method ;										//��ֵ����,Ĭ��Ϊ�����
		double radius;										//������봦�����ĵľ���
		double rotateAngle ;								//���ĵ���ת�Ƕ�
		double beta;										//ת����
		char biggerOrSmaller;
		double ru, eps;										//ru�����Ŀ����룬eps��С��һ��ֵ
	public:
		Image() {											//���캯��
			Imgin = Imgout = NULL;
			rows = cols = 0;
			horiCenter = vertCenter = 0;
			rotateR = 0;
			method = '1';
			radius = rotateAngle = beta = 0;
		}
		~Image() {											//��������
			cvReleaseImage(&Imgin);                        
			cvReleaseImage(&Imgout);                      
		}
		bool ifreadFail();										//�Ƿ����ͼ��ʧ��
		void showInput();										//��ʾ����ͼ��
		void readImg(char *img);								//����ͼ��
		void selectMethod();									//ѡ���ֵ����
		void afterProc();										//�Ƿ񱣴洦����
		void nearest(double x, double y, int u, int v);			//����ڲ�ֵ
		void bilinear(double x, double y, int u, int v);		//˫���Բ�ֵ
		void bicubic(double x, double y, int u, int v);			//˫���β�ֵ
		void preRotate();										//��תԤ����	
		void rotate();											//��ת
		void preDistorsion();									//����Ԥ����
		void distorsion();										//����
		void TPS();												//TPS
		
};

struct ctrlPoint {										//���ص�,TPS�п��Ƶ㡢Ŀ���Ľṹ
	int row;											//����
	int col;											//����
};