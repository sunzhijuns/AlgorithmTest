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

template<typename T>
// [L, R] 只少两个
int __partition1(T arr[], int L, int R) {
	int q = rand() % (R - L + 1) + L;
	swap(arr[L], arr[q]);

	int j = L;
	for (int i = L+1; i <=R; i++)
	{
		if (arr[i] >=arr[L])
		{
			continue;
		}
		else {
			swap(arr[j+1],arr[i]);
			j++;
		}

	}
	swap(arr[j], arr[L]);

	return j;
}

template<typename T>
void __quickSort1(T arr[], int L, int R) {
	if (L >= R)
	{
		return;
	}
	//[L,R]
	int q = __partition1(arr, L, R);
	__quickSort1(arr, L, q - 1);
	__quickSort1(arr, q + 1, R);
}

template<typename T>
void quickSort1(T arr[], int n) {
	__quickSort1(arr, 0, n - 1);
}



template<typename T>
// [L, R] 只少两个
int __partition2(T arr[], int L, int R) {
	int q = rand() % (R - L + 1) + L;
	swap(arr[L],arr[q]);

	int j = L;
	T value = arr[L];
	for (int i = L+1; i <=R; i++)
	{
		if (arr[i] < value)
		{
			swap(arr[j + 1], arr[i]);
			j++;
		}

	}
	swap(arr[j], arr[L]);
	return j;
}



template<typename T>
// [L, R] 只少两个
int __partition(T arr[], int L, int R) {
	int q = rand() % (R - L + 1) + L;
	swap(arr[L], arr[q]);

	T value = arr[L];
	int i = L + 1;
	int j = R;
	while (true)//i<=j) // 不可以i<j;
	{
		while (arr[i] < value)
		{
			i++;
		}
		while (arr[j] > value)
		{
			j--;
		}
		if (i>j) // 不可以i>=j
		{
			break;
		}
		swap(arr[i],arr[j]);
		i++;
		j--;

	}
	//for (int i = L + 1; i <= R; i++)
	//{
	//	if (arr[i] < value)
	//	{
	//		swap(arr[j + 1], arr[i]);
	//		j++;
	//	}

	//}
	swap(arr[j], arr[L]);
	return j;
}

template<typename T>
void __quickSort(T arr[], int L, int R) {
	if (R-L<30)
	{
		insertSort(arr+L, R-L+1);
		return;
	}
	//[L,R]
	int q = __partition(arr, L, R);
	__quickSort(arr, L, q - 1);
	__quickSort(arr, q + 1, R);
}




template<typename T>
// [L, R] 只少两个
int* __partition3(T arr[], int L, int R) {
	int random = rand() % (R - L + 1) + L;
	swap(arr[L], arr[random]);

	T value = arr[L];
	int  LT= L;
	int GT = R+1;
	int i = L + 1;
	while(i <= R)
	{
		if (arr[i] == value)
		{
			i++;
		}
		else if (arr[i] < value)
		{
			LT++;
			swap(arr[LT], arr[i]);
			i++;
		}
		else if (arr[i] > value)
		{
			GT--;
			swap(arr[GT], arr[i]);
		}
	}
	swap(arr[LT], arr[L]);
	int res[2] = {LT - 1,GT};
	return res;
}

template<typename T>
void __quickSort3(T arr[], int L, int R) {
	if (R - L<30)
	{
		insertionSort(arr,L, R);
		return;
	}
	//[L,R]
	/*int* q = __partition3(arr, L, R);*/
	int random = rand() % (R - L + 1) + L;
	swap(arr[L], arr[random]);

	T value = arr[L];
	int  LT = L;
	int GT = R + 1;
	int i = L + 1;
	while (i < GT)
	{
		if (arr[i] == value)
		{
			i++;
		}
		else if (arr[i] < value)
		{
			LT++;
			swap(arr[LT], arr[i]);
			i++;
		}
		else// if (arr[i] > value)
		{
			GT--;
			swap(arr[GT], arr[i]);
		}
	}
	swap(arr[LT], arr[L]);



	__quickSort3(arr, L, LT-1);
	__quickSort3(arr, GT, R);
}

template<typename T>
void quickSort(T arr[], int n) {
	srand(time(NULL));
	__quickSort3(arr, 0, n - 1);
}

int main()
{
	int n = 1000000;
	int swapTimes = 100;
	int *arr0 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
	//int *arr0 = SortTestHelper::generateRandomArray(n,0,10);
	int *arr1 = SortTestHelper::copyIntArray(arr0, n);
	int *arr2 = SortTestHelper::copyIntArray(arr0,n);
	int *arr3 = SortTestHelper::copyIntArray(arr0, n);
	int *arr4 = SortTestHelper::copyIntArray(arr0, n);

	//SortTestHelper::testSort("selectionSort", selectionSort, arr0, n);
	//SortTestHelper::testSort("insertSort", insertSort, arr1, n);
	
	SortTestHelper::testSort("mergeSort", mergeSort, arr0, n);
	SortTestHelper::testSort("quickSort", quickSort, arr1, n);
	//SortTestHelper::testSort("mergeSort", mergeSort, arr2, n);
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
	SortTestHelper::testSort("quickSort", quickSort, a,81);
	SortTestHelper::printArray(a,81);
	delete[]a;
	system("pause");

	return 0;
}