#include"VectorKeyValue.h"
#include<cstdlib>
#include<string>

VectorKeyValue::VectorKeyValue()
{
	maxsize = 20;
	len = 0;
	keyvalueptr = new IKeyValue*[maxsize];
}
VectorKeyValue::~VectorKeyValue()
{
	delete[] keyvalueptr;
}
void VectorKeyValue::push_back(IKeyValue * item)
{
	int nlen = len + 1;
	if (nlen == maxsize)
	{
		maxsize = maxsize * 2;
		//std::string *n = values;
		IKeyValue* *tmp = new IKeyValue*[maxsize];
		for (int i = 0; i < len; i++)
		{
			tmp[i] = keyvalueptr[i];
		}
		delete[] keyvalueptr;
		keyvalueptr = tmp;
	}
	keyvalueptr[len] = item;
	len++;
}

void VectorKeyValue::pop_back()
{
	if (len != 0)
	{

		int psize = len - 1;
		keyvalueptr[psize] = '\0';
		if (psize < maxsize / 2)
		{
			maxsize = maxsize / 2;
			IKeyValue** tmp = new IKeyValue*[maxsize];
			for (int i = 0; i < psize; i++)
			{
				tmp[i] = keyvalueptr[i];
			}
			delete[] keyvalueptr;
			keyvalueptr = tmp;
		}
		len--;
	}
}
IKeyValue * VectorKeyValue::get(int index)
{
	return keyvalueptr[index];
}
void VectorKeyValue::set(int index, IKeyValue * item)
{
	keyvalueptr[index] = item;
}
size_t VectorKeyValue::size()
{
	return len;
}