// simple_cache.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
int cache_hits = 0;
class lnode
{
public:
	int index;
	int val;
	lnode *next;
	lnode(int a,int b)
	{
		index = a;
		val = b;
		next = NULL;
	}
};
class mmemory
{
private:
	int m[256];
public:
	mmemory()
	{
		for (int i = 0; i < 256; i++)
			m[i] = rand() % 500;
	}
	void m_write(int a, int v)
	{
		if (a > 255)
		{
			cout << "Memory limit exceeded" << endl;
		}
		else
			m[a] = v;
	}
	int m_read(int a)
	{
		if (a > 255)
			cout << "Memory limit exceeded" << endl;
		else
			return m[a];
	}
}m_mem;

class llist
{
private:
	lnode *head;
	int length;
public:
	llist()
	{
		head = NULL;
		length = 0;
	}
	void add_element(int a, int b, int set)
	{

		lnode *nnode= new lnode(a, b);
		if (head == NULL)
		{
			head = nnode;
		}
		else
		{
			nnode->next = head;
			head = nnode;
		}
		length++;
		if (length > 4)
		{
			lnode *cnode = head;
			while ((cnode->next)->next)
				cnode = cnode->next;
			int addr,val;
			addr = ((cnode->next->index) << 2) + set;
			val = cnode->next->val;
			m_mem.m_write(addr, val);
			free(cnode->next);
			cnode->next = NULL;
			length--;
		}
	}
	void print_list()
	{
		lnode *cnode = head;
		while (cnode)
		{
			cout << cnode->val << " -> ";
			cnode = cnode->next;
		}
		cout << "NULL " << endl;
	}
	int read_list(int i)
	{
		lnode *cnode = head;
		if (cnode == NULL)
			return NULL;
		if (cnode->index == i)
		{
			cache_hits++;
			return cnode->val;
		}
		while (cnode->next)
		{
			if ((cnode->next)->index == i)
			{
				cache_hits++;
				lnode *htnode = cnode->next;
				cnode->next = htnode->next;
				htnode->next = head;
				head = htnode;
				return htnode->val;
			}
			else
				cnode = cnode->next;
		}
		return NULL;
	}
	int write_list(int i,int v)
	{
		lnode *cnode = head;
		if (cnode == NULL)
			return NULL;
		if (cnode->index == i)
		{
			cnode->val = v;
			cache_hits++;
			return 1;
		}
		while (cnode->next)
		{
			if ((cnode->next)->index == i)
			{
				cache_hits++;
				lnode *htnode = cnode->next;
				cnode->next = htnode->next;
				htnode->next = head;
				head = htnode;
				htnode->val = v;
				return 1;
			}
			else
				cnode = cnode->next;
		}
		return 0;
	}

};

class s_cache
{
private:
	llist ls[4];
public:
	int read_memry(int address)
	{
		int index, set, ans;
		set = address & 3;
		index = (address & 252) >> 2;
		ans = ls[set].read_list(index);
		if (ans == NULL)
		{
			ans = m_mem.m_read(address);
			ls[set].add_element(index, ans, set);
			//cout << "R: Cache Miss "<< address << endl;
		}
		else
		{
			//cout << "R: Cache Hit "<< address << endl;
			
		}
		return ans;
	}
	void write_memry(int address, int val)
	{
		int index, set, ans;
		set = address & 3;
		index = (address & 252) >> 2;
		ans = ls[set].write_list(index, val);
		if (ans == 0)
		{
			//cout << "W: Cache Miss " << address << endl;
			ls[set].add_element(index, val, set);
		}
		else
		{
			//cout << "W: Cache Hit "<< address << endl;
		}
		//m_mem.m_write(address, val);
	}
}l1_cache;

int main()
{
	int tries = 10000;
	int address = 0;
	for (int i = 0; i < tries; i++)
	{
		address++;
		address = address % 16;
		if (address & 1)
			l1_cache.read_memry(address);
		else
			l1_cache.write_memry(address, rand() % 500);
		//cout <<"address " << i%10 << " " << l1_cache.read_memry( i%10 ) << endl;
	}
	cout << "Cache Hits - " << cache_hits << endl;
	cout << "Cache hit rate - " << (cache_hits / tries)*100 << endl;

	
	return 0;
}

