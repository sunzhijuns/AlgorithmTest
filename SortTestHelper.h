#pragma once

#include<iostream>
#include<ctime>
#include<cassert>
using namespace std;
namespace SortTestHelper {
	//随机数组arr[n] 属于 [rangeL, rangeR]
	int* generateRandomArray(int n, int rangeL, int rangeR) {
		assert(rangeL <= rangeR);
		int *arr = new int[n];
		srand(time(NULL));
		for (int i = 0; i < n; i++)
		{
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		}
		return arr;
	}
	int *copyIntArray(int arr[],int n) {
		int*arrCopy = new int[n];
		copy(arr,arr+n,arrCopy);
		return arrCopy;
	}
	template<typename T>
	void printArray(T arr[], int n) {
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}
	template<typename T>
	bool isSorted(T arr[], int n) {
		for (int i = 0; i < n-1; i++)
		{
			if (arr[i] > arr[i+1])
			{
				return false;
			}
		}
		return true;
	}
	template<typename T>
	void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();
		assert(isSorted(arr,n));
		cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
		return;
	} 

}