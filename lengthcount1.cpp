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

void lengthcount(int islandF[][side], int islandA[][side], int n) {

	int l, t;
	int mm, nn;
	int mmm, nnn;
	int lengthcount[side + 1] = { 0 };

	

	for (int m = 0; m <= side - 1; ++m) {
		for (int n = 0; n <= side - 1; ++n) {

			if (islandF[m][n] == 2) {
				l = islandA[m][n];

				mm = y(m + arrayi[z(l + 3)]);
				nn = y(n + arrayj[z(l + 3)]);

				if (islandA[mm][nn] == z(l + 3)) {

					t = 1;

					for (int h = 0; h <= 3; h += 3) {
						mm = y(m + arrayii[z(l + h)]);
						nn = y(n + arrayjj[z(l + h)]);
						mmm = y(mm + arrayi[z(l + 3)]);
						nnn = y(nn + arrayj[z(l + 3)]);

						while ((islandA[mm][nn] == l) && (islandA[mmm][nnn] == z(l + 3))) {
							++t;
							mm = y(mm + arrayii[z(l + h)]);
							nn = y(nn + arrayjj[z(l + h)]);
							mmm = y(mm + arrayi[z(l + 3)]);
							nnn = y(nn + arrayj[z(l + 3)]);
						}

					}
					++lengthcount[t];

				}

			}

		}

	}

	for (int h = 1; h <= side; ++h) {
		lengthcount[h] = lengthcount[h] / (2*h);
	}

	ofstream fs;
	fs.open(("D:\\mc_simu_receiver\\program1\\length" + to_string(n) + ".txt"), ios::out);

	for (int i = 1; i <= side; ++i) {
			fs << lengthcount[i] << " ";
				fs << endl;
	}

	fs.close();

}