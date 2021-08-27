#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void change(int arr[],int a, int b) //数组arr，交换下标分别为a和b的值
{
	int temp;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void BSort(int arr[], int size) //冒泡排序
{
	int i, j;
	int temp = 0;
	for (i = 0; i < size -1; i++)
	{
		for (j = 0; j < size -i-1 ; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = 0;
				change(arr, j, j + 1);
			}
		}
	}

}

void QuickSort(int arr[],int left,int right) //快速排序
{
	int pivot = arr[left];
	if (left > right)
	{
		return; 
	}
	int L = left, R = right;

	while (L != R)
	{
		while (arr[R] >= pivot && L < R)
		{
			R--;
		}
		while (arr[L] <= pivot && L < R)
		{
			L++;
		}
		if (L < R)
		{
			change(arr, L, R);
		}

	}
	change(arr, left, L);
	QuickSort(arr, left, L - 1);
	QuickSort(arr, L + 1, right);
}















void main()
{
	srand((unsigned)time(NULL) );
	int arr[100000];
	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand();
	}
	//BSort(arr, size);
	QuickSort(arr, 0, size - 1);
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", arr[i]);
	}
}

