#pragma once

#include"Interfaces02.h"
#include<cstdlib>
#include<string>

class ll_node
{
	int key;
	IVectorString * values;
	ll_node *next;
public:
	
	ll_node();
	~ll_node(){}
	void setnodekey(int k);
	void setvaluesptr(IVectorString* vals);
	void setval(std::string val);
	int getnodekey();
	std::string getnodeval(int index);
	IVectorString* getvaluesptr();
	void setnext(ll_node * nxt);
	ll_node * getnext();
	
};