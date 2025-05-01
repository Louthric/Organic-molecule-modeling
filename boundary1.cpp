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

//返回值映射至[0,side-1]
int y(int x) {

    if (x < 0) {
        return x + side;
    }
    else if ((x >= 0) && (x <= side-1)) {
        return x;
    }
    else {  // x > side-1
        return x - side;
    }

}


//返回值映射至[0,5]
int z(int x) {
    if (x < 0) {
        return x + 6;
    }
    else if ((x >= 0) && (x <= 5)) {
        return x;
    }
    else {  // x > 5
        return x - 6;
    }
}