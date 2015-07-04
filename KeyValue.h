#include "Interfaces02.h"
#include<string>
#include<cstdlib>

class KeyValue : public IKeyValue
{
	int key;
	std::string value;
public:
	KeyValue(){}
	~KeyValue(){}
	void setKey(int key);
	void setValue(std::string value) ;
	int getKey();
	std::string getValue();
};