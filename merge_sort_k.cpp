// merge_sort_k.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class node
{
public:
	int val;
	node *next;
	node(int a)
	{
		val = a;
		next = NULL;
	}
};

class l_list
{
public:
	node *head;
	l_list()
	{
		head = NULL;
	}
	void add_element(int a)
	{
		node *nnode= new node(a);
		if (head == NULL)
		{
			head = nnode;
			return;
		}
		if (a <= head->val)
		{
			nnode->next = head;
			head = nnode;
			return;
		}
		node * cnode=head;
		while (cnode->next != NULL)
		{
			if (cnode->next->val > a)
				break;
			cnode = cnode->next;
		}
		nnode->next = cnode->next;
		cnode->next = nnode;
	}
	void print_list()
	{
		node *cnode = head;
		while (cnode)
		{
			cout << cnode->val << "->";
			cnode = cnode->next;
		}
		cout << "NULL" << endl;
	}
};

void merge(l_list *l1, l_list *l2)
{
	node *c1, *c2,*n,*p;
	c1 = l1->head;
	c2 = l2->head;
	p = NULL;
	while (c2 != NULL)
	{
		if (c2->val > c1->val)
			break;
		else
			p = c2;
			c2 = c2->next;
	}
	if (p != NULL)
	{
		l1->head = l2->head;
		p->next=c1;
		l2->head = c2;
	}
	if (c2 == NULL)
		return;
	while (c1 != NULL && c2 != NULL)
	{
		if (c1->val < c2->val)
		{
			p = c1;
			c1 = c1->next;
		}
		else
		{
			n = c2->next;
			p->next = c2;
			p = c2;
			c2->next = c1;
			c2 = n;
		}
	}
	if (c1 == NULL)
		p->next = c2;
	l2->head = NULL;
}
int main()
{
	int a[] = { 3,4,1,2,6,8,9 };
	int b[] = { 7,5,10,14,13 };
	l_list l1,l2,*p,*q;
	for (int i = 0; i < 7; i++)
	{
		l1.add_element(a[i]);
	}
	l1.print_list();
	for (int i = 0; i < 5; i++)
	{
		l2.add_element(b[i]);
	}
	l2.print_list();
	p = &l1;
	q = &l2;
	merge(q, p);
	q->print_list();
    return 0;
}

