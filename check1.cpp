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

int checkA(int islandF[][side], int i, int j, int k, int &sum0) {

	int mm, nn;
	int p, q;

	mm = y(i + arrayi[k]);
	nn = y(j + arrayj[k]);

    //先检查[i][j]位置和k取向位置
    sum0 = sum0 + islandF[i][j] + islandF[mm][nn];

    if (sum0 != 0) {
        return sum0;
    }

    //检查4个近邻位置
    for (int h = -2; h <= 2; ++h) {
        if (h != 0) {
            p = y(mm + arrayi[z(k + h)]);
            q = y(nn + arrayj[z(k + h)]);
            sum0 += islandF[p][q];
            if (sum0 != 0) {
                return sum0;
            }
        }
    }

    
    //再检查2个近邻位置
    for (int h = -2; h <= 2; h += 4) {
        mm = y(i + arrayi[z(k + h)]);
        nn = y(j + arrayj[z(k + h)]);
        sum0 += islandF[mm][nn];
        if (sum0 != 0) {
            return sum0;
        }
    }

    return sum0;
}


int checkB(int islandF[][side], int i, int j, int k, int &sum0) {

    int m, n, mm, nn, mmm, nnn;
    int p, q;

    m = y(i + arrayi[z(k + 3)]);
    n = y(j + arrayj[z(k + 3)]);

    mm = y(i + arrayi[k]);
    nn = y(j + arrayj[k]);

    mmm = y(m + arrayi[z(k + 3)]);
    nnn = y(n + arrayj[z(k + 3)]);

    //先检查4个落点位置
    sum0 = sum0 + islandF[i][j] + islandF[m][n] + islandF[mm][nn] + islandF[mmm][nnn];

    if (sum0 != 0) {
        return sum0;
    }

    //检查（mm,nn)的4个近邻
    for (int h = -2; h <= 2; ++h) {
        if (h != 0) {
            p = y(mm + arrayi[z(k + h)]);
            q = y(nn + arrayj[z(k + h)]);
            sum0 += islandF[p][q];
            if (sum0 != 0) {
                return sum0;
            }
        }
    }

    //检查（i,j）的2个近邻
    p = y(i + arrayi[z(k + 2)]);
    q = y(j + arrayj[z(k + 2)]);
    sum0 += islandF[p][q];

    p = y(i + arrayi[z(k - 2)]);
    q = y(j + arrayj[z(k - 2)]);
    sum0 += islandF[p][q];

    if (sum0 != 0) {
        return sum0;
    }

    //检查（mmm,nnn）的4个近邻
    for (int h = -2; h <= 2; ++h) {
        if (h != 0) {
            p = y(mmm + arrayi[z(k + h)]);
            q = y(nnn + arrayj[z(k + h)]);
            sum0 += islandF[p][q];
            if (sum0 != 0) {
                return sum0;
            }
        }
    }

    return sum0;
}

int checkM(int islandF[][side], int i, int j, int k, int &sum0) {

    int ii, jj, iii, jjj;
    int m, n, m1, n1, mm, nn, mm1, nn1;

    ii = y(i + arrayi[k]);
    jj = y(j + arrayj[k]);

    iii = y(i + arrayi[z(k + 1)]);
    jjj = y(j + arrayj[z(k + 1)]);

    //4*3个实际点，6对
    m = y(i + arrayii[k]);
    n = y(j + arrayjj[k]);

    m1 = y(m + arrayi[k]);
    n1 = y(n + arrayj[k]);

    checkA(islandF, m, n, k, sum0);

    mm = y(i + arrayii[z(k + 3)]);
    nn = y(j + arrayjj[z(k + 3)]);

    mm1 = y(mm + arrayi[k]);
    nn1 = y(nn + arrayj[k]);

    checkA(islandF, mm, nn, k, sum0);

    m = y(i + arrayii[z(k + 1)]);
    n = y(j + arrayjj[z(k + 1)]);

    m1 = y(m + arrayi[z(k + 1)]);
    n1 = y(n + arrayj[z(k + 1)]);

    checkA(islandF, m, n, z(k + 1), sum0);

    mm = y(i + arrayii[z(k + 4)]);
    nn = y(j + arrayjj[z(k + 4)]);

    mm1 = y(mm + arrayi[z(k + 1)]);
    nn1 = y(nn + arrayj[z(k + 1)]);

    checkA(islandF, mm, nn, z(k + 1), sum0);

    m = y(ii + arrayii[z(k + 2)]);
    n = y(jj + arrayjj[z(k + 2)]);

    m1 = y(m + arrayi[z(k + 2)]);
    n1 = y(n + arrayj[z(k + 2)]);

    checkA(islandF, m, n, z(k + 2), sum0);

    mm = y(ii + arrayii[z(k + 5)]);
    nn = y(jj + arrayjj[z(k + 5)]);

    mm1 = y(mm + arrayi[z(k + 2)]);
    nn1 = y(nn + arrayj[z(k + 2)]);

    checkA(islandF, mm, nn, z(k + 2), sum0);

    return sum0;
}