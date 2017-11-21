// AlgorithmTest.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
//#include<algorithm>
using namespace std;
void selectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[minIndex] > arr[j])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			swap(arr[minIndex], arr[i]);
		}
	}


}

int main()
{
	int arr[5] = { 1,2,3,1,2 };
	selectionSort(arr, 5);
	for (size_t i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");

	return 0;
}