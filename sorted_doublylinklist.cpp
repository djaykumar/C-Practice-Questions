// sorted_doublylinklist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

using namespace std;

struct node
{
	int value;
	node *next;
	node *prev;
};

void insert_node(node *head, int value)
{
	node *temp;
	if (!head)
	{
		head = (node *)malloc(sizeof(node));
		head->value = value;
	}
	else
	{
		if (value > head->value)
			insert_node(head->next, value);
		if (value < head->value)
		{
			temp = (node *)malloc(sizeof(node));

		}
	}
}
int main()
{
    return 0;
}

