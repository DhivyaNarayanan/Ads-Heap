#include"KeyValue.h"
#include<string>
#include<cstdlib>

void KeyValue::setKey(int key)
{
	this->key = key;
}
void KeyValue::setValue(std::string value)
{
	this->value = value;
}
int KeyValue::getKey()
{
	return this->key;
}
std::string KeyValue::getValue()
{
	return this->value;
}
