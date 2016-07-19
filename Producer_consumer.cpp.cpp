// Queue_mt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>


using namespace std; 
mutex q_lock;

class Queue
{
public:
	vector<int> A;
	void enqueue(int a)
	{
		A.insert(A.begin(), a);
	}
	int dequeue()
	{
		int ans;
		ans = A.back();
		A.pop_back();
		return ans;
	}
	bool isempty()
	{
		return A.empty();
	}
	bool isfull()
	{
		return A.size() == 5;
	}
}Buffer;

void add_to_buffer()
{
	int i;
	for (i = 0; i < 10; i++)
	{
		q_lock.lock();
		while (Buffer.isfull())
		{
			q_lock.unlock();
			q_lock.lock();
		}
		cout << "inserting " << i << endl;
		Buffer.enqueue(i);
		q_lock.unlock();
	}
}

void consume_from_buffer()
{
	int i;
	for (i = 0; i < 10; i++)
	{
		q_lock.lock();
		while (Buffer.isempty())
		{
			q_lock.unlock();
			q_lock.lock();
		}
		cout << Buffer.dequeue() << endl;
		q_lock.unlock();
	}
}

int main()
{
	thread p(add_to_buffer);
	thread c(consume_from_buffer);
	p.join();
	c.join();
    return 0;
}

