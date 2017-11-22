// AlgorithmTest.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include"Student.h"
#include"SelectionSort.h"
#include"SortTestHelper.h"
#include"InsertionSort.h"
#include"ShellSort.h"
//#include<algorithm>
using namespace std;
// 我们的第一版bubbleSort
template<typename T>
void bubbleSort(T arr[], int n) {

	bool swapped;

	do {
		swapped = false;
		for (int i = 1; i < n; i++)
			if (arr[i - 1] > arr[i]) {
				swap(arr[i - 1], arr[i]);
				swapped = true;

			}

		// 优化, 每一趟Bubble Sort都将最大的元素放在了最后的位置
		// 所以下一次排序, 最后的元素可以不再考虑
		n--;

	} while (swapped);
}


// 我们的第二版bubbleSort,使用newn进行优化
template<typename T>
void bubbleSort2(T arr[], int n) {

	int newn; // 使用newn进行优化

	do {
		newn = 0;
		for (int i = 1; i < n; i++)
			if (arr[i - 1] > arr[i]) {
				swap(arr[i - 1], arr[i]);

				// 记录最后一次的交换位置,在此之后的元素在下一轮扫描中均不考虑
				newn = i;
			}
		n = newn;
	} while (newn > 0);
}


int main()
{
	int n = 10000;
	//int *arr0 = SortTestHelper::generateNearlyOrderedArray(n,1000);
	int *arr0 = SortTestHelper::generateRandomArray(n,0,n);
	int *arr1 = SortTestHelper::copyIntArray(arr0, n);
	int *arr2 = SortTestHelper::copyIntArray(arr0,n);
	int *arr3 = SortTestHelper::copyIntArray(arr0, n);

	SortTestHelper::testSort("selectionSort", selectionSort, arr0, n);
	SortTestHelper::testSort("insertSort", insertSort, arr1, n);
	SortTestHelper::testSort("bubbleSort", bubbleSort, arr2, n);
	SortTestHelper::testSort("bubbleSort2", bubbleSort2, arr3, n);
	delete[] arr0;
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	system("pause");

	return 0;
}