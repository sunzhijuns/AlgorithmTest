#pragma once
template<typename T>
void shellSort(T arr[], int n) {
	int d = n / 3;
	while (d >= 1)
	{
		for (int i = d; i < n; i += d)
		{
			T value = arr[i];
			int j = i;
			for (; j > 0 && value < arr[j - d]; j -= d)
			{
				arr[j] = arr[j - d];
			}
			arr[j] = value;
		}

		d /= 2;

	}
}