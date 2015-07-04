#include"Interfaces02.h"
#include<string>
#include<cstdlib>

class VectorKeyValue : public IVectorKeyValue
{
	int maxsize;
	size_t len;
	IKeyValue ** keyvalueptr;
public:
	VectorKeyValue();
	~VectorKeyValue();
	void push_back(IKeyValue * item);
	void pop_back();
	IKeyValue * get(int index);
	void set(int index, IKeyValue * item);
    size_t size();
};