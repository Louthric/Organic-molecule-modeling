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


//用于检查当前数组,写代码的时候用来检查的，实际不运行
void printArray(int arr[][side]) {

    for (int i = 0; i < side; ++i) {
        for (int j = 0; j < side; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void printDoubleArray(double arr[side]) {
	for (int i = 0; i < side; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << endl;
}


//将arr数组打到txt里去
void textF(int arr[][side], int n) {


	ofstream fs;
	fs.open(("D:\\mc_simu_receiver\\program1\\result" + to_string(n) + ".txt"), ios::out);

	for (int i = 0; i < side; ++i) {


		for (int j = 0; j < side; ++j) {


			fs << arr[i][j] << " ";
			if (j == side - 1) {
				fs << endl;
			}
		}
	}
	fs.close();
}

void textA(int arr[][side], int n) {


	ofstream fs;
	fs.open(("D:\\mc_simu_receiver\\program1\\direct" + to_string(n) + ".txt"), ios::out);

	for (int i = 0; i < side; ++i) {


		for (int j = 0; j < side; ++j) {


			fs << arr[i][j] << " ";
			if (j == side - 1) {
				fs << endl;
			}

		}
	}
	fs.close();
}

