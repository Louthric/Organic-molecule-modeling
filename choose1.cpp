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

int choose(int islandF[][side], int islandA[][side], int i, int j, int k) {

	int modi;
	int m, n;
	double r = generateRandomNumber();

	modi = 1;
	
	m = y(i + arrayi[z(k + 3)]);
	n = y(j + arrayj[z(k + 3)]);

	if (islandA[m][n] == z(k + 3)) {
		if (r <= poss) {
			modi = 2;
		}
	}
	else {
		modi = 1;
	}

	return modi;
}