// AlgorithmTest.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include"Student.h"
#include"SelectionSort.h"
#include"SortTestHelper.h"
#include"InsertionSort.h"
#include"ShellSort.h"
#include<algorithm>
#include"MergeSort.h"
#include"QuickSort.h"
using namespace std;

int main()
{
	int n = 1000000;
	int swapTimes = 100;
	//int *arr0 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
	int *arr0 = SortTestHelper::generateRandomArray(n,0,n);
	int *arr1 = SortTestHelper::copyIntArray(arr0, n);
	int *arr2 = SortTestHelper::copyIntArray(arr0,n);
	int *arr3 = SortTestHelper::copyIntArray(arr0, n);
	int *arr4 = SortTestHelper::copyIntArray(arr0, n);

	//SortTestHelper::testSort("selectionSort", selectionSort, arr0, n);
	//SortTestHelper::testSort("insertSort", insertSort, arr1, n);
	
	SortTestHelper::testSort("mergeSort", mergeSort, arr0, n);
	SortTestHelper::testSort("quickSort", quickSort, arr1, n);
	SortTestHelper::testSort("quickSort3Ways", quickSort3Ways, arr2, n);
	//SortTestHelper::testSort("quickSort1", quickSort1, arr3, n);
	//SortTestHelper::testSort("mergeSort2", mergeSort2, arr4, n);
	delete[] arr0;
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;

	int *a = new int[81];
	for (int i = 0; i < 81; i++)
	{
		a[i] = 81 - i;
	}
	SortTestHelper::testSort("mergeSort", mergeSort, a,81);
	SortTestHelper::printArray(a,81);
	delete[]a;
	system("pause");

	return 0;
}