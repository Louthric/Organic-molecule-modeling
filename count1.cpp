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

void countM(int islandF[][side], int islandA[][side], int &countA, int i, int j, int k) {

	int m, n, mm, nn;
	int ii, jj;

	//三个方向
	m = y(i + arrayiii[k]);
	n = y(j + arrayjjj[k]);

	mm = y(m + arrayi[k]);
	nn = y(n + arrayj[k]);

	if (islandA[m][n] == z(k + 3) && islandA[mm][nn] == k) {
		countA++;
	}

	m = y(i + arrayiii[z(k + 4)]);
	n = y(j + arrayjjj[z(k + 4)]);

	mm = y(m + arrayi[z(k + 1)]);
	nn = y(n + arrayj[z(k + 1)]);

	if (islandA[m][n] == z(k + 4) && islandA[mm][nn] == z(k + 1)) {
		countA++;
	}

	ii = y(i + arrayi[k]);
	jj = y(j + arrayj[k]);

	m = y(ii + arrayiii[z(k + 2)]);
	n = y(jj + arrayjjj[z(k + 2)]);

	mm = y(m + arrayi[z(k + 2)]);
	nn = y(n + arrayj[z(k + 2)]);

	if (islandA[m][n] == z(k + 5) && islandA[mm][nn] == z(k + 2)) {
		countA++;
	}

}