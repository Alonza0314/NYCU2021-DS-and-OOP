#include<iostream>
#include<ctime>
#define max 500
using namespace std;

void merge_sort(int*, int);
void merge(int*, int*, int*, int, int);
void print_the_arr(int*, int);

void main()
{
	//genetate the array with 500 numbers
	int arr[max];
	int count = 0;
	while (count != max)
	{
		arr[count] = rand();
		count++;
	}
	int size = sizeof(arr) / sizeof(int);
	cout << "The random array:" << endl;
	print_the_arr(arr,size);
	cout << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << "~";
	}
	cout << endl;
	cout << "The sort array:" << endl;
	merge_sort(arr, size);
	print_the_arr(arr, size);
}

void merge_sort(int* arr, int size)
{
	if (size == 1)
	{
		return;
	}
	else
	{
		int left_size = size / 2 + size % 2;
		int right_size = size / 2;
		int* left = (int*)malloc(left_size * sizeof(int));
		int* right = (int*)malloc(right_size * sizeof(int));
		int left_count = 0;
		int right_count = 0;
		for (int i = 0; i < size; i++)
		{
			if (i % 2 == 0)
			{
				left[left_count] = arr[i];
				left_count++;
			}
			else
			{
				right[right_count] = arr[i];
				right_count++;
			}
		}
		merge_sort(left, left_size);
		merge_sort(right, right_size);
		merge(arr, left, right, left_size, right_size);
	}
}

void merge(int* arr, int* left, int* right, int size_left, int size_right)
{
	int count_left = 0;
	int count_right = 0;
	int count_arr = 0;

	while (count_left < size_left && count_right < size_right)
	{
		if (left[count_left] <= right[count_right])
		{
			arr[count_arr] = left[count_left];
			count_left++;
		}
		else
		{
			arr[count_arr] = right[count_right];
			count_right++;
		}
		count_arr++;
	}
	while (count_left < size_left)
	{
		arr[count_arr] = left[count_left];
		count_left++;
		count_arr++;
	}
	while (count_right < size_right)
	{
		arr[count_arr] = right[count_right];
		count_right++;
		count_arr++;
	}
}

void print_the_arr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i % 15 != 0 || i == 0)
		{
			cout << arr[i] << " \t";
		}
		else
		{
			cout << endl;
			cout << arr[i] << " \t";
		}
	}
}