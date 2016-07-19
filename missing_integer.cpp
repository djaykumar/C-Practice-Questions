// missing_integer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
int main()
{
	int *arr;
	int size;
	cout << "Enter size of array" << endl;
	cin >> size;
	arr = new int[size];
	cout << "Enter the numbers in ascending order" << endl;
	for (int i = 0; i < size; i++)
		cin >> arr[i];
	int diff;
	cout << "Missing Integers" << endl;
	for (int i = 0; i < size - 1; i++)
	{
		diff = arr[i + 1] - arr[i];
		if (diff > 1)
		{
			for (int j = 1; j < diff; j++)
				cout << arr[i] + j << "\t";
		}
	}
	cout << endl;
	return 0;
}

