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


int moveA(int islandF[][side], int islandA[][side], double arrayEr[side], int ma, int na, int la, int mb, int nb, int lb) {


	double energyA, energyB, energyDiff, poi;
	double r = generateRandomNumber();

	energytestA(islandF, islandA, arrayEr, energyA, ma, na, la);

	//重置islandF
	cancelA(islandF, ma, na, la);
	arrivalA(islandF, mb, nb, lb);

	//重置islandA
	islandA[ma][na] = 8;
	islandA[mb][nb] = lb;

	energytestA(islandF, islandA, arrayEr, energyB, mb, nb, lb);

	//判断
	energyDiff = energyB - energyA;
	energyDiff = exp(-energyDiff / (kB * Tc));

	if (energyDiff < 1.0) {
		poi = energyDiff;
	}
	else {
		poi = 1.0;
	}

	//不满足概率，取消本次跳跃
	if (r > poi) {

		//重置islandF
		cancelA(islandF, mb, nb, lb);
		arrivalA(islandF, ma, na, la);

		//重置islandA
		islandA[ma][na] = la;
		islandA[mb][nb] = 8;

	}

	return 0;
}


int moveB(int islandF[][side], int islandA[][side], double arrayEr[side], int ma, int na, int la, int mb, int nb, int lb) {


	int m, n;
	double energyA, energyB, energyDiff, poi;
	double r = generateRandomNumber();

	energytestB(islandF, islandA, arrayEr, energyA, ma, na, la);

	//重置islandF
	cancelB(islandF, ma, na, la);
	arrivalB(islandF, mb, nb, lb);

	//重置islandA
	islandA[ma][na] = 8;

	m = y(ma + arrayi[z(la + 3)]);
	n = y(na + arrayj[z(la + 3)]);

	islandA[m][n] = 8;


	islandA[mb][nb] = lb;

	m = y(mb + arrayi[z(lb + 3)]);
	n = y(nb + arrayj[z(lb + 3)]);

	islandA[m][n] = z(lb + 3);


	energytestB(islandF, islandA, arrayEr, energyB, mb, nb, lb);

	energyDiff = energyB - energyA;
	energyDiff = exp(-energyDiff / (kB * Tc));

	if (energyDiff < 1.0) {
		poi = energyDiff;
	}
	else {
		poi = 1.0;
	}

	//不满足概率，取消本次跳跃
	if (r > poi) {

		//重置islandF
		cancelB(islandF, mb, nb, lb);
		arrivalB(islandF, ma, na, la);

		//重置islandA
		islandA[ma][na] = la;
		islandA[mb][nb] = 8;

		m = y(ma + arrayi[z(la + 3)]);
		n = y(na + arrayj[z(la + 3)]);

		islandA[m][n] = z(la + 3);

		m = y(mb + arrayi[z(lb + 3)]);
		n = y(nb + arrayj[z(lb + 3)]);

		islandA[m][n] = 8;

	}

	return 0;
}


int moveM(int islandF[][side], int islandA[][side], int ma, int na, int la, int mb, int nb, int lb) {

	double poi, energyDiff;
	int countA, countB;
	double r = generateRandomNumber();

	countA = 0;
	countB = 0;

	countM(islandF, islandA, countA, ma, na, la);

	cancelM(islandF, ma, na, la);
	islandA[ma][na] = 8;

	arrivalM(islandF, mb, nb, lb);
	islandA[mb][nb] = lb;

	countM(islandF, islandA, countB, mb, nb, lb);

	energyDiff = -2 * Eb * (countB - countA);
	energyDiff = exp(-energyDiff / (kB * Tc));

	if (energyDiff < 1.0) {
		poi = energyDiff;
	}
	else {
		poi = 1.0;
	}

	if (r > poi) {
		cancelM(islandF, mb, nb, lb);
		islandA[mb][nb] = 8;

		arrivalM(islandF, ma, na, la);
		islandA[ma][na] = la;
	}

	return 0;
}