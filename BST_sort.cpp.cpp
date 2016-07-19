// BST_sort.cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct BST_node
{
	 int value = NULL;
	 BST_node *left = NULL;
	 BST_node *right = NULL;
};

void BST_insert(BST_node *head, int value)
{
	if (head->value == NULL)
	{
		head->value = value;
		return;
	}
	else
	{
		if (value < head->value)
		{
			if(head->left == NULL)
				head->left = new BST_node[1];
			BST_insert(head->left, value);
		}
		if (value > head->value)
		{
			if(head->right == NULL)
				head->right = new BST_node[1];
			BST_insert(head->right, value);
		}
	}
	return;
}

int verify_BST(BST_node *head)
{
	static int prev;
	if (head->left != NULL)
	{
		if (!verify_BST(head->left))
			return 0;
	}
	if (head->value < prev)
		return 0;
	else
	{
		prev = head->value;
			if (head->right != NULL)
			{
				if (!verify_BST(head->right))
					return 0;
			}
		return 1;
	}
	
}

int min_node(BST_node *head)
{
	if (head->left != NULL)
		return min_node(head->left);
	else
		return head->value;
}

void print_BST(BST_node *head)
{
	if (head->value != NULL)
	{
		cout << "Head is " << head->value << endl;
		cout << "Left is" << endl;
		print_BST(head->left);
		cout << "Right is" << endl;
		print_BST(head->right);
	}
}

void preorder(BST_node *head)
{
//	if (head->value != NULL)
		cout << head->value << "\t";
	if (head->left != NULL)
		preorder(head->left);
	if (head->right != NULL)
		preorder(head->right);
}

void inorder(BST_node *head)
{
	if (head->left != NULL)
		inorder(head->left);
	//if (head->value != NULL)
		cout << head->value << "\t";
	if (head->right != NULL)
		inorder(head->right);	
}

void postorder(BST_node *head)
{
	if (head->left != NULL)
		postorder(head->left);
	if (head->right != NULL)
		postorder(head->right);
	//if (head->value != NULL)
		cout << head->value << "\t";
}


int main()
{
	int arr[10] = { 3,5,7,4,8,6,11,2,10,21 };
	BST_node *head;
	head = new BST_node[1];
	for (int i = 0; i < 10; i++)
	{
		BST_insert(head, arr[i]);
	}
	//print_BST(head);
	preorder(head);
	cout << endl;
	inorder(head);
	cout << endl;
	postorder(head);
	cout << endl;
	cout << "BST verfied" << verify_BST(head) << endl; 
	cout << "BST Min node " << min_node(head);
    return 0;
}

