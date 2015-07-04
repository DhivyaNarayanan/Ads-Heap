#include"ll_node.h"
#include"VectorString.h"
#include<string>
#include<cstdlib>
ll_node * front = NULL;
ll_node* back = NULL;
int ll_size = 0;

ll_node::ll_node()
{
	values = new VectorString();
	next = NULL;
}

void ll_node::setnodekey(int k)
{
	this->key = k;
}

void ll_node::setvaluesptr(IVectorString* vals)
{
	this->values = vals;
}
int ll_node::getnodekey()
{
	return this->key;
}

std::string ll_node::getnodeval(int in)
{
	return this->values->get(in);
}
IVectorString* ll_node::getvaluesptr()
{
	return this->values;
}
void ll_node::setnext(ll_node * nxt)
{
	this->next = nxt;
}
ll_node * ll_node::getnext()
{
	return this->next;
}
void ll_node::setval(std::string val)
{
	this->values->push_back(val);
}

