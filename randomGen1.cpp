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

// 随机实数生成函数
double generateRandomNumber() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);
    return dis(gen);
}

// 随机整数生成函数
int getRandomNumber(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}