#pragma once

#include"Interfaces02.h"
#include"ll_node.h"
#include<string>
#include<cstdlib>

class PriorityQueue_1 : public IPriorityQueue
{
	size_t queue_size;
	ll_node *front;
public:

	PriorityQueue_1()
	{
		queue_size = 0;
		front = NULL;

	}
	~PriorityQueue_1() {}
	void enqueue(IKeyValue * key_value);
	void merge(IPriorityQueue * input_queue);
	IVectorKeyValue * returnSorted();
	int lowestKey();
	IVectorString * lowestValues();
	void dequeue();
	ll_node * get_frnt();
	void set_frnt(ll_node * frnt);
	size_t size();
};