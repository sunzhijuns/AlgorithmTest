// AlgorithmTest.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include"Student.h"
#include"SelectionSort.h"
#include"SortTestHelper.h"
//#include<algorithm>
using namespace std;


int main()
{
	int n = 10000;
	int *arr = SortTestHelper::generateRandomArray(n,0,10);
	SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
	delete[] arr;

	system("pause");

	return 0;
}