#pragma once
#include "data1.h"  // 引入全局常量

void printArray(int arr[][side]);
void printDoubleArray(double arr[side]);

void textF(int arr[][side], int n);
void textA(int arr[][side], int n);
void lengthcount(int islandF[][side], int islandA[][side], int n);

int y(int x);
int z(int x);

int checkA(int islandF[][side], int i, int j, int k, int& sum0);
int checkB(int islandF[][side], int i, int j, int k, int& sum0);
int checkM(int islandF[][side], int i, int j, int k, int& sum0);

int arrivalA(int islandF[][side], int i, int j, int k);
int arrivalB(int islandF[][side], int i, int j, int k);
int arrivalM(int islandF[][side], int i, int j, int k);

int choose(int islandF[][side], int islandA[][side], int i, int j, int k);

int moveA(int islandF[][side], int islandA[][side], double arrayEr[side], int ma, int na, int la, int mb, int nb, int lb);
int moveB(int islandF[][side], int islandA[][side], double arrayEr[side], int ma, int na, int la, int mb, int nb, int lb);
int moveM(int islandF[][side], int islandA[][side], int ma, int na, int la, int mb, int nb, int lb);

void energytestA(int islandF[side][side], int islandA[side][side], const double arrayEr[side], double& Energy, int i, int j, int k);
void energytestB(int islandF[side][side], int islandA[side][side], const double arrayEr[side], double& Energy, int i, int j, int k);
void globalenergy(int islandF[][side], int islandA[][side], const double arrayEr[side], int moveTime);

void countM(int islandF[][side], int islandA[][side], int& countA, int ma, int na, int la);

int cancelA(int islandF[][side], int i, int j, int k);
int cancelB(int islandF[][side], int i, int j, int k);
int cancelM(int islandF[][side], int i, int j, int k);

double generateRandomNumber();
int getRandomNumber(int min, int max);
