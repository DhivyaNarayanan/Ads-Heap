#include"PriorityQueue_1.h"
#include"VectorKeyValue.h"
#include"VectorString.h"
#include"KeyValue.h"
#include<cstdlib>
#include<string>

void PriorityQueue_1::enqueue(IKeyValue * key_value)
{
	ll_node * nn = new ll_node();
	int nkey = key_value->getKey();
	std::string nval = key_value->getValue();
	if (front == NULL)
	{
		nn->setnodekey(nkey);
		nn->setval(nval);
		nn->setnext(NULL);
		queue_size++;
		front = nn;

	}
	else
	{
		int fkey = front->getnodekey();
		if (nkey < fkey)
		{
			nn->setnext(front);
			nn->setnodekey(nkey);
			nn->setval(nval);
			front = nn;
			queue_size++;
		}
		else if (nkey >= fkey)
		{
			ll_node* prev = NULL;
			ll_node * temp = front;

			while (temp != NULL)
			{
				int tkey = temp->getnodekey();
				if (nkey == tkey)
				{
					temp->setval(nval);
					break;
				}
				else if (nkey > tkey)
				{
					if (temp->getnext() == NULL)
					{
						temp->setnext(nn);
						nn->setnext(NULL);
						nn->setnodekey(nkey);
						nn->setval(nval);

						queue_size++;
						break;
					}
					else
					{
						prev = temp;
						temp = temp->getnext();
					}
				}
				else if (nkey < tkey)
				{
					prev->setnext(nn);
					nn->setnext(temp);
					nn->setnodekey(nkey);
					nn->setval(nval);
					queue_size++;
					break;
				}
			} // eof while
		} //eof else if
	}// eof else
}
void PriorityQueue_1::dequeue()
{
	ll_node * temp;
	temp = front;
	front = front->getnext();
	temp->setnext(NULL);
	queue_size--;
}

ll_node* PriorityQueue_1::get_frnt()
{
	return this->front;
}


void PriorityQueue_1::set_frnt(ll_node *frnt)
{
	this->front = frnt;
}

void PriorityQueue_1::merge(IPriorityQueue * input_queue)
{
	/*ll_node * tmp;
	ll_node* prev = NULL;
	tmp = ((PriorityQueue1*)input_queue)->get_frnt();
	IKeyValue * kv = NULL;
	while (tmp != NULL)
	{

		int in_key = tmp->getnodekey();
		IVectorString * in_valsptr = tmp->getvaluesptr();
		int val_size = in_valsptr->size();
		std::string in_val = in_valsptr->get(0);
		kv = new KeyValue();
		kv->setKey(in_key);
		kv->setValue(in_val);
		this->enqueue(kv);

		prev = tmp;
		tmp = tmp->getnext();
		prev->setnext(NULL);

	}*/
	ll_node * temp = ((PriorityQueue_1*)input_queue)->get_frnt();
	if (temp->getnodekey() <= this->front->getnodekey())
	{
		int k = temp->getnodekey();
		IVectorString * v = temp->getvaluesptr();
		this->front->setnodekey(k);
		this->front->setvaluesptr(v);
	}
}
IVectorKeyValue * PriorityQueue_1::returnSorted()
{
	IVectorKeyValue * mv = new VectorKeyValue();
	IKeyValue *kv = NULL;
	ll_node * tmp = front;
	while (tmp != NULL)
	{
		int tkey = tmp->getnodekey();
		int tvsize = tmp->getvaluesptr()->size();
		for (int i = 0; i < tvsize; i++)
		{
			std::string tval = tmp->getnodeval(i);
			kv = new KeyValue();
			kv->setKey(tkey);
			kv->setValue(tval);
			mv->push_back(kv);
		}
		tmp = tmp->getnext();
	}
	return mv;

}
int PriorityQueue_1::lowestKey()
{
	int lowkey;
	ll_node * frnt = front;
	lowkey = frnt->getnodekey();
	return lowkey;
}

IVectorString * PriorityQueue_1::lowestValues()
{
	IVectorString * tmp;
	ll_node*frnt = front;
	tmp = frnt->getvaluesptr();
	return tmp;
}

size_t PriorityQueue_1::size()
{
	return queue_size;
}