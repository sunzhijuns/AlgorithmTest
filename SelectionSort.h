#pragma once
#include<iostream>
template<typename T>
void selectionSort(T arr[], int n) {
	for (int i = 0; i < n - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j]<arr[minIndex])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			std::swap(arr[minIndex], arr[i]);
		}
	}
}
