#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>  // 用于设置输出格式
#include <cstdlib>  // 包含用于伪随机数生成的头文件
#include "data1.h"  // 引入全局常量
#include "voidFunctions1.h"
#include <cmath>
#include <random>

using namespace std;

void energytestA(int islandF[side][side], int islandA[side][side], const double arrayEr[side], double &Energy, int i, int j, int k) {

	int nba;
	int nbm;
	int mm, nn, mm2, nn2;
	int lpq;
	int t;
	int length[side + 1] = {0};//下标范围是[0,side]

	//初始化
	nba = 0;
	nbm = 0;

	//吸引 1，肩并肩
	for (int h = 0; h <= 3; h += 3) {

		mm = y(i + arrayii[z(k + h)]);
		nn = y(j + arrayjj[z(k + h)]);

		if (islandA[mm][nn] == k) {
			nba += 1;
		}

	}
	
	//吸引 2
	mm = y(i + arrayi[z(k + 3)]);
	nn = y(j + arrayj[z(k + 3)]);

	if (islandA[mm][nn] == z(k+3)) {
		nba += 2;
	}

	//吸引 3 调制器
	for (int h = 0; h <= 3; h += 3) {

		mm = y(i + arrayii[z(k + h)]);
		nn = y(j + arrayjj[z(k + h)]);

		mm2 = y(mm + arrayi[k]);
		nn2 = y(nn + arrayj[k]);

		if (islandF[mm][nn] == 5 && islandF[mm2][nn2] == 4) {
			nbm += 1;
		}

	}



	//排斥
	//对于所有的2号分子

	for (int p = 0; p <= side - 1; ++p) {
		for (int q = 0; q <= side - 1; ++q) {
			if (islandF[p][q] == 2) {
				lpq = islandA[p][q];

				//当前选中（p,q）分子，它的取向为lpq

				t = 1;

				for (int h = 0; h <= 3; h += 3) {

					mm = y(p + arrayii[z(lpq + h)]);
					nn = y(q + arrayjj[z(lpq + h)]);

					while (islandA[mm][nn] == lpq) {

						++t;

						mm = y(mm + arrayii[z(lpq + h)]);
						nn = y(nn + arrayjj[z(lpq + h)]);

					}

				}

				++length[t];

			}

		}

	}

	//总能量计算，注意重复计算
	for (int h = 1; h <= side; ++h) {
			Energy = Energy + length[h] * arrayEr[h - 1] / h;
	}

	//最终能量等于排斥能-吸引能
	Energy = Energy - (Ea * nba) - (Eb * nbm);

}


void energytestB(int islandF[side][side], int islandA[side][side], const double arrayEr[side], double &Energy, int i, int j, int k) {

	int nba, nbm;
	int mm, nn;
	int m, n;
	int mm2, nn2;
	int lpq;
	int t;
	int length[side + 1] = { 0 };

	//初始化
	nba = 0;
	nbm = 0;

	//吸引 1，肩并肩
	for (int h = 0; h <= 3; h += 3) {

		mm = y(i + arrayii[z(k + h)]);
		nn = y(j + arrayjj[z(k + h)]);

		if (islandA[mm][nn] == k) {
			nba += 1;
		}

	}

	//吸引 2，肩并肩
	m = y(i + arrayi[z(k + 3)]);
	n = y(j + arrayj[z(k + 3)]);

	for (int h = 0; h <= 3; h += 3) {

		mm = y(m + arrayii[z(k + h)]);
		nn = y(n + arrayjj[z(k + h)]);


		if (islandA[mm][nn] == z(k + 3)) {
			nba += 1;
		}

	}

	//吸引 3，调制器，如果1个符合了，那么2个都符合
	for (int h = 0; h <= 3; h += 3) {

		mm = y(i + arrayii[z(k + h)]);
		nn = y(j + arrayjj[z(k + h)]);

		mm2 = y(mm + arrayi[k]);
		nn2 = y(nn + arrayj[k]);

		if (islandF[mm][nn] == 5 && islandF[mm2][nn2] == 4) {
			nbm += 2;
		}

	}


	//排斥
	//对于所有的2号分子

	for (int p = 0; p <= side - 1; ++p) {
		for (int q = 0; q <= side - 1; ++q) {
			if (islandF[p][q] == 2) {
				lpq = islandA[p][q];

				//当前选中（p,q）分子，它的取向为lpq

				t = 1;

				for (int h = 0; h <= 3; h += 3) {

					mm = y(p + arrayii[z(lpq + h)]);
					nn = y(q + arrayjj[z(lpq + h)]);

					while (islandA[mm][nn] == lpq) {

						++t;

						mm = y(mm + arrayii[z(lpq + h)]);
						nn = y(nn + arrayjj[z(lpq + h)]);

					}

				}

				++length[t];

			}

		}

	}

	//总能量计算，注意重复计算
	for (int h = 1; h <= side; ++h) {
			Energy = Energy + length[h] * arrayEr[h - 1] / h;
	}


	//最终能量等于排斥能-吸引能
	Energy = Energy - (Ea * nba) - (Eb * nbm);


}
