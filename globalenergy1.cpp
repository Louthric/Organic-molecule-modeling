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

void globalenergy(int islandF[][side], int islandA[][side], const double arrayEr[side], int moveTime) {
	
	int lpq;
	int t;
	int mm, nn;
	int length[side + 1] = { 0 };
	int nba;
	double energyR, energyA, allenergy;

	energyR = 0.0;
	energyA = 0.0;
	allenergy = 0.0;

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

	for (int h = 1; h <= side; ++h) {
		energyR = energyR + length[h] * arrayEr[h - 1] / h;
	}

	//吸引，肩并肩
	for (int h = 1; h <= side; ++h) {
		energyA = energyA + length[h] * (h-1) * Ea/ h;
	}
	
	nba = 0;

	//吸引，头碰头
	for (int p = 0; p <= side - 1; ++p) {
		for (int q = 0; q <= side - 1; ++q) {
			if (islandF[p][q] == 2) {
				lpq = islandA[p][q];
				mm = y(p + arrayi[z(lpq + 3)]);
				nn = y(q + arrayj[z(lpq + 3)]);
				if (islandA[mm][nn] == z(lpq + 3)) {
					++nba;
				}
			}
		}
	}

	energyA += nba * Ea;
	
	int totalcount = 0;

	//吸引，连接modulator
	for (int p = 0; p <= side - 1; ++p) {
		for (int q = 0; q <= side - 1; ++q) {
			if (islandF[p][q] == 3 && islandA[p][q] != 8) {
				int count = 0;
				lpq = islandA[p][q];
				countM(islandF, islandA, count, p, q, lpq);
				totalcount += count;
			}
		}
	}

	energyA += totalcount * 2 * Eb;

	allenergy = energyR - energyA;

	ofstream fs;
	fs.open(("D:\\mc_simu_receiver\\program1\\AAAenergyLine.txt"), ios::app);
	
	fs << moveTime << "\t" << allenergy << endl;

	fs.close();
}