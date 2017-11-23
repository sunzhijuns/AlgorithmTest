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
using namespace std;


int main()
{
	int n = 1000000;
	//int *arr0 = SortTestHelper::generateNearlyOrderedArray(n,1000);
	int *arr0 = SortTestHelper::generateRandomArray(n,0,n);
	int *arr1 = SortTestHelper::copyIntArray(arr0, n);
	int *arr2 = SortTestHelper::copyIntArray(arr0,n);
	int *arr3 = SortTestHelper::copyIntArray(arr0, n);

	//SortTestHelper::testSort("selectionSort", selectionSort, arr0, n);
	//SortTestHelper::testSort("insertSort", insertSort, arr1, n);
	
	SortTestHelper::testSort("mergeSort", mergeSort, arr0, n);
	SortTestHelper::testSort("mergeSort1", mergeSort1, arr1, n);
	SortTestHelper::testSort("mergeSort", mergeSort, arr2, n);
	SortTestHelper::testSort("mergeSort2", mergeSort2, arr3, n);
	delete[] arr0;
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	int *a = new int[81];
	for (int i = 0; i < 81; i++)
	{
		a[i] = 81 - i;
	}
	SortTestHelper::testSort("mergeSort2", mergeSort2, a,81);
	SortTestHelper::printArray(a,81);
	delete[]a;
	system("pause");

	return 0;
}