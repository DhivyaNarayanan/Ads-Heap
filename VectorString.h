#include"Interfaces02.h"
#include<cstdlib>
#include<string>

class VectorString : public IVectorString
{
	int maxsize;
	size_t len;
	std::string * values;

public:
	VectorString();
	~VectorString();
	void push_back(std::string item);
	void pop_back();
	std::string get(int index);
	void set(int index, std::string item);
	size_t size();
};

