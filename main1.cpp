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


int islandF[side][side] = { 0 };  //数组大小是side*side，但下标范围是[0,side-1]
int islandA[side][side] = { 0 };

double arrayEr[side] = { 0 };
double arrayE[side] = { 0 };

int i, j, k;    //原位置
int m, n, l;    //新位置
int sum, modi;

int moleculesPut, modulatorsPut;

int moveTime;  // 计数器

int main() {

    /**/
    /*初始化数组*/
    /**/

    for (int i = 0; i < side; ++i) {
        for (int j = 0; j <= i; ++j) {
            arrayE[i] += Er / (j + 1);  // 数组下标从0开始，所以这里使用 (j + 1)
        }
    }

    for (int i = 1; i < side; ++i) {
        for (int j = 0; j < i; ++j) {
            arrayEr[i] += arrayE[j];
        }
    }


    for (int i = 0; i < side; ++i) {
        for (int j = 0; j < side; ++j) {
            islandA[i][j] = 8;
        }
    }


    /**/
   /*地图上初始状态*/
    /**/
    
    //放调制器
    modulatorsPut = 0;

    while (1) {

        if (modulatorsPut == Moducycle) {
            break;
        }

        sum = 0;

        i = getRandomNumber(0, side-1);
        j = getRandomNumber(0, side-1);
        k = getRandomNumber(0, 5);

        checkM(islandF, i, j, k, sum);

        if (sum == 0) {

            arrivalM(islandF, i, j, k);
            islandA[i][j] = k;

            ++modulatorsPut;

        }

        if (modulatorsPut == Moducycle) {
            break;
        }

    }    

    //放分子
    moleculesPut = 0;

    while (1) {

        sum = 0;

        i = getRandomNumber(0, side - 1); //因为要表示的是坐标，使用下标来计算
        j = getRandomNumber(0, side - 1);
        k = getRandomNumber(0, 5);

        checkA(islandF, i, j, k, sum);

        if (sum == 0) {

            arrivalA(islandF, i, j, k);
            islandA[i][j] = k;

            ++moleculesPut;

        }

        if (moleculesPut == Mocycle) {
            break;
        }

    }


    //原始状态
    textF(islandF, 0);
    //textA(islandA, 0);
    lengthcount(islandF, islandA, 0);

    /**/
    /*MC跳跃过程*/
    /**/

    //计数器初始化
    moveTime = 0;

    while (1) {
        //随机获得一个有2号分子的位置
        while (1) {

            i = getRandomNumber(0, side - 1);
            j = getRandomNumber(0, side - 1);

            if (islandF[i][j] == 2) {
                k = islandA[i][j];
                break;
            }
        }

        //得到(i,j)坐标和k取向
        //检测(i,j)位置是否是二聚体,1为单体，2为二聚体
        modi = choose(islandF, islandA, i, j, k);

        if (modi == 1 ) {

            while (1) {

                //随机落点和取向
                m = getRandomNumber(0, side - 1);
                n = getRandomNumber(0, side - 1);
                l = getRandomNumber(0, 5);

                sum = 0;

                checkA(islandF, m, n, l, sum);
                //旧位置i,j,k,新位置m,n,l

                //符合空位条件，则检测能量条件
                if (sum == 0) {

                    if (moveTime % interval == 0) {
                        std::cout << "No. " << moveTime << std::endl;
                        //globalenergy(islandF, islandA, arrayEr, moveTime);
                    }
                    

                    moveA(islandF, islandA, arrayEr, i, j, k, m, n, l);
                    ++moveTime;

                    break;

                }

            }

        }
        else if (modi == 2) {

            while (1) {

                //随机找一个新的着陆地点
                m = getRandomNumber(0, side - 1);
                n = getRandomNumber(0, side - 1);
                l = getRandomNumber(0, 5);

                sum = 0;

                checkB(islandF, m, n, l, sum);

                //符合空位条件，则检测能量条件
                if (sum == 0) {

                    if (moveTime % interval == 0) {
                        std::cout << "No. " << moveTime << std::endl;
                        //globalenergy(islandF, islandA, arrayEr, moveTime);
                    }

                    moveB(islandF, islandA, arrayEr, i, j, k, m, n, l);
                    ++moveTime;

                    break;

                }
            }

        }

        //穿插modulator的跳跃
        if (moveTime % Mointerval == 0) {

            //找一个modulator标记
            while (1) {

                i = getRandomNumber(0, side - 1);
                j = getRandomNumber(0, side - 1);

                if (islandA[i][j] != 8 && islandF[i][j] == 3) {
                    k = islandA[i][j];
                    break;
                }
            }

            //撤销原分子位置对新选位置的影响
            cancelM(islandF, i, j, k);
            islandA[i][j] = 8;

            //找一个符合空位的新位置
            while (1) {

                //随机落点和取向
                m = getRandomNumber(0, side - 1);
                n = getRandomNumber(0, side - 1);
                l = getRandomNumber(0, 5);

                sum = 0;

                checkM(islandF, m, n, l, sum);

                if (sum == 0) {
                    //恢复原先分子位置
                    arrivalM(islandF, i, j, k);
                    islandA[i][j] = k;

                    moveM(islandF, islandA, i, j, k, m, n, l);
                    break;
                }

            }

        }

        if (moveTime % interval == 0) {
            int i;
            i = moveTime/interval;
            textF(islandF, i);
            //textA(islandA, i);
            lengthcount(islandF, islandA, i);
        }

        if (moveTime >= hoppingTime) {
            break;
        }

    }

    return 0;
}
