// Substring_palindromes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cout << "Enter String" << endl;
	cin >> str;
	int len = str.length();
	bool *tab;
	tab = new bool[len*len];
	for (int i = 0; i < len; i++)
		*(tab + i*len + i) = 1;

	for (int i = 0; i < len; i++)
	{
		if (str[i] == str[i + 1])
			*(tab + i*len + i + 1) = 1;
	}
	int k;
	for (int i = 3; i < len; i++)
	{
		for (int j = 0; j < (len - i + 1); j++)
		{
			k = j + i - 1;
			if (*(tab + (j + 1)*len + (k - 1)) == 1 && str[j] == str[k])
				*(tab + j*len + k) = 1;
		}
	}

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (*(tab + i*len + j) == 1)
				cout << str.substr(i, j - i + 1) << endl;
		}
	}
    return 0;
}

