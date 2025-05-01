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

int arrivalA(int islandF[][side], int i, int j, int k) {

	int mm, nn;

	mm = y(i + arrayi[k]);
	nn = y(j + arrayj[k]);

	//(i,j)位置放上吸引分子，记为2，k取向近邻放上排斥分子，记为1
	islandF[y(i)][y(j)] = 2;
	islandF[mm][nn] = 1;

	return 0;
}


int arrivalB(int islandF[][side], int i, int j, int k) {

	int mm, nn, m, n, mmm, nnn;

	mm = y(i + arrayi[k]);
	nn = y(j + arrayj[k]);

	//(i,j)位置放上吸引分子，记为2，k取向近邻放上排斥分子，记为1
	islandF[i][j] = 2;
	islandF[mm][nn] = 1;

	//再放一对
	m = y(i + arrayi[z(k + 3)]);
	n = y(j + arrayj[z(k + 3)]);

	mmm = y(m + arrayi[z(k + 3)]);
	nnn = y(n + arrayj[z(k + 3)]);

	islandF[m][n] = 2;
	islandF[mmm][nnn] = 1;

	return 0;
}

int arrivalM(int islandF[][side], int i, int j, int k) {

	int ii, jj, iii, jjj;
	int m, n, m1, n1, mm, nn, mm1, nn1;

	ii = y(i + arrayi[k]);
	jj = y(j + arrayj[k]);

	iii = y(i + arrayi[z(k + 1)]);
	jjj = y(j + arrayj[z(k + 1)]);

	islandF[i][j] = islandF[ii][jj] = islandF[iii][jjj] = 3;

	//4*3个实际点，6对
	m = y(i + arrayii[k]);
	n = y(j + arrayjj[k]);

	m1 = y(m + arrayi[k]);
	n1 = y(n + arrayj[k]);

	islandF[m][n] = islandF[m1][n1] = 5;

	mm = y(i + arrayii[z(k + 3)]);
	nn = y(j + arrayjj[z(k + 3)]);

	mm1 = y(mm + arrayi[k]);
	nn1 = y(nn + arrayj[k]);

	islandF[mm][nn] = islandF[mm1][nn1] = 4;

	m = y(i + arrayii[z(k + 1)]);
	n = y(j + arrayjj[z(k + 1)]);

	m1 = y(m + arrayi[z(k + 1)]);
	n1 = y(n + arrayj[z(k + 1)]);

	islandF[m][n] = islandF[m1][n1] = 4;

	mm = y(i + arrayii[z(k + 4)]);
	nn = y(j + arrayjj[z(k + 4)]);

	mm1 = y(mm + arrayi[z(k + 1)]);
	nn1 = y(nn + arrayj[z(k + 1)]);

	islandF[mm][nn] = islandF[mm1][nn1] = 5;

	m = y(ii + arrayii[z(k + 2)]);
	n = y(jj + arrayjj[z(k + 2)]);

	m1 = y(m + arrayi[z(k + 2)]);
	n1 = y(n + arrayj[z(k + 2)]);

	islandF[m][n] = islandF[m1][n1] = 5;

	mm = y(ii + arrayii[z(k + 5)]);
	nn = y(jj + arrayjj[z(k + 5)]);

	mm1 = y(mm + arrayi[z(k + 2)]);
	nn1 = y(nn + arrayj[z(k + 2)]);

	islandF[mm][nn] = islandF[mm1][nn1] = 4;

	return 0;
}