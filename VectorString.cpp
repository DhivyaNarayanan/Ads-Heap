#include"VectorString.h"
#include<cstdlib>
#include<string>

VectorString::VectorString() 
{
	maxsize = 20;
	len = 0;
	values = new std::string[maxsize];

}

VectorString::~VectorString()
{
	delete[]values;

}

void VectorString::push_back(std::string item)
{
	
	int nlen = len + 1;
	if (nlen == maxsize)
	{
		maxsize = maxsize * 2;
		//std::string *n = values;
		std::string *tmp = new std::string[maxsize];
		for(int i = 0; i < len; i++)
		{
			tmp[i] = values[i];
		}
		delete[] values;
		values = tmp;
	}
	values[len] = item;
	len++;

}

void VectorString::pop_back()
{
	if (len != 0)
	{

		int psize = len - 1;
		values[psize] = '\0';
		if (psize < maxsize / 2)
		{
			maxsize = maxsize / 2;
			std::string* tmp = new std::string[maxsize];
			for (int i = 0; i < psize; i++)
			{
				tmp[i] = values[i];
			}
			delete[] values;
			values = tmp;
		}
		len--;
	}
}

std::string VectorString::get(int index)
{
	return values[index];
}
void VectorString::set(int index, std::string item)
{
	values[index] = item;
}
size_t VectorString::size()
{
	return len;
}