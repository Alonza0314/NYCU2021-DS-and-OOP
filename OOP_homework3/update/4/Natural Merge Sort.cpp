#include<iostream>
#include<ctime>
#define test 500
using namespace std;
void print_array(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i == 0 || i % 10 == 0)
		{
			cout << endl << arr[i] << " ";
		}
		else
		{
			cout << arr[i] << " ";
		}
	}
	cout << endl;
}
int check_array(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			return 0;
		}
	}
	return 1;
}
bool check_test(int* arr)
{
	for (int i = 0; i < test; i++)
	{
		if (arr[i] == 0)
		{
			return false;
		}
	}
	return true;
}
int get_index(int* arr, int* brr, int num)
{
	int count = 0;
	brr[count++] = 0;
	for (int i = 1; i < num; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			brr[count++] = i;
		}
	}
	return count;
}
void merge(int* arr, int first_index, int second_index, int boundary)
{
	int num = boundary - first_index;
	int* temp = (int*)malloc(num * sizeof(int));
	int second = second_index;
	int index = 0;
	//cout array
	/*cout << "Array :" << endl;
	for (int i = first_index; i < boundary; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;*/
	for (int first = first_index; first < second_index; first++)
	{
		while (second < boundary)
		{
			//cout << "second < boundary = " << second << "<" << boundary << endl;
			if (arr[second] < arr[first])
			{
				//cout << "arr[second] < arr[first] = " << arr[second] << "<" << arr[first] << endl;
				temp[index] = arr[second];
				//cout << "second temp[" << index << "] = " << temp[index] << endl;
				index++;
				second++;
			}
			else
			{
				break;
			}
		}
		temp[index] = arr[first];
		//cout << " first temp[" << index << "] = " << temp[index] << endl;
		index++;
	}
	/*cout << "Temp:";
	print_array(temp, index);
	cout << "~~~~~~~~~~~~" << endl;*/
	for (int i = 0; i < index; i++)
	{
		arr[first_index++] = temp[i];
	}
}
void natural_merge_sort(int *arr,int num)
{
	int* index_arr = (int*)malloc((num + 1) * sizeof(int));
	int count = get_index(arr, index_arr, num);
	index_arr[count++] = num;
	//cout index_arr
	/*cout << "count = " << count << endl;
	cout << "index_arr:" << endl;
	print_array(index_arr, count);
	system("pause");*/
	while (count > 2)
	{
		int size = count;
		int index = 0;
		for (int i = 0; i < count; i += 2)
		{
			index_arr[index++] = index_arr[i];
			if (i + 2 < count)
			{
				merge(arr, index_arr[i], index_arr[i + 1], index_arr[i + 2]);
			}
		}
		//cout index_arr
		/*cout << "count = " << count << endl;
		cout << "index_arr:" << endl;
		print_array(index_arr, count);
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;*/
		if (count % 2 == 0)
		{
			index_arr[index++] = num;
		}
		count = index;
	}
}

void main()
{
	/*int count = 0;
	int arrarr[test];
	while (count != test)
	{
		cout << "The " << count + 1 << " test." << endl;
		int num = rand() % 101;
		int* arr = (int*)malloc(num * sizeof(int));
		for (int i = 0; i < num; i++)
		{
			arr[i] = rand() % 101;
		}
		cout << "Array with " << num << " random numbers:";
		print_array(arr, num);
		natural_merge_sort(arr, num);
		cout << endl;
		cout << "Array after sorted:";
		print_array(arr, num);
		cout << endl;
		arrarr[count] = check_array(arr, num);
		count++;
	}
	if (check_test(arrarr))
	{
		cout << "Correct~~~~~~~~~~~~~" << endl;
	}
	else
	{
		cout << "Wrong!!!!!!!!!!!!!!!!!!!!" << endl;
	}*/

	srand(time(NULL));
	int num = rand() % 101;
	int* arr = (int*)malloc(num * sizeof(int));
	for (int i = 0; i < num; i++)
	{
		arr[i] = rand() % 101;
	}
	cout << "Array with " << num << " random numbers:";
	print_array(arr, num);
	natural_merge_sort(arr, num);
	cout << endl;
	cout << "Array after sorted:";
	print_array(arr, num);
	cout<<endl;
	if (check_array)
	{
		cout << "Sorted~" << endl;
	}
	else
	{
		cout << "Wrong!" << endl;
	}
}