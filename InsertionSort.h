#pragma once
#include<iostream>
//template<typename T>
//void insertSort(T arr[], int n) {
//	for (int i = 1; i < n; i++)
//	{
//		T value = arr[i];
//		int j = i;
//		for (; j > 0 && value < arr[j - 1]; j--)
//		{
//			arr[j] = arr[j - 1];
//		}
//		arr[j] = value;
//	}
//}

template<typename T>
void insertSort(T *arr,int n) {
	for (int i = 1; i < n; i++)
	{
		T value = *(arr+i);
		int j = i;
		for (; j > 0 && value < *(arr + j - 1); j--)
		{
			*(arr+j) = *(arr+j - 1);
		}
		*(arr+j) = value;
	}
}

// 对arr[l...r]范围的数组进行插入排序
template<typename T>
void insertionSort(T arr[], int l, int r) {

	for (int i = l + 1; i <= r; i++) {

		T e = arr[i];
		int j;
		for (j = i; j > l && arr[j - 1] > e; j--)
			arr[j] = arr[j - 1];
		arr[j] = e;
	}

	return;
}

template<typename T>
void insertSort(T arr[],int L, int R) {
	for (int i = L+1; i <=R; i++)
	{
		T value = arr[i];
		int j = i;
		for (; j > L && value < arr[j - 1]; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = value;
	}
}
template<typename T>
void insertSort1(T arr[], int n) {
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				std::swap(arr[j], arr[j - 1]);
			}
			else {
				break;
			}
		}
	}
}

template<typename T>
// 和insertSort没区别
void insertSort2(T arr[], int n) {
	for (int i = 1; i < n; i++)
	{
		T value = arr[i];
		int j = i;
		for (; j > 0; j--)
		{
			if (value < arr[j - 1])
			{
				arr[j] = arr[j - 1];
			}
			else {
				//arr[j] = value;
				break;
			}
		}
		arr[j] = value;
	}
}