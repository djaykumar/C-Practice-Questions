// VersionCompare.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

class version
{
public:
	char* ver_string;
	int major = 0, minor = 0 , release = 0 , build = 0;
	version(char* str)
	{
		ver_string = str;
		sscanf_s(ver_string, "%d.%d.%d.%d", &major, &minor, &release, &build);
	}
};

int version_compare(version str1, version str2)
{
	if (str1.major == str2.major)
	{
		if (str1.minor == str2.minor)
		{
			if (str1.release == str2.release)
			{
				if (str1.build == str2.build)
					return 0;
				if (str1.build < str2.build)
					return -1;
				else
					return 1;
			}
			if (str1.release < str2.release)
				return -1;
			else
				return 0;
		}
		if (str1.minor < str2.minor)
			return -1;
		else
			return 1;
	}
	if (str1.major < str2.major)
		return -1;
	else
		return 1;
	
}

int main()
{
	version str1 ("Version 1 is 121.1.5");
	version str2("Version 2 is 121.1.5.0");
	cout << str1.ver_string << endl;
	//cout << "Major = " << str1.major << " Minor = " << str1.minor << " Release = " << str1.release << " Build = " << str1.build << endl;
	cout << "String Compare result " << version_compare(str1, str2) << endl;
    return 0;
}

