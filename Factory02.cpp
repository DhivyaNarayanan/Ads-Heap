#include "Factory02.h"
#include"KeyValue.h"
#include"PriorityQueue1.h"
#include"PriorityQueue_1.h"
#include"VectorKeyValue.h"
#include"VectorString.h"

Factory02::Factory02()
{
}

Factory02::~Factory02()
{
}
 
void * Factory02::create(std::string name)
{
  if(name == "IKeyValue1"){
    return new KeyValue();
  } else if(name == "IKeyValue2"){
    return new KeyValue();
  } else if(name == "IKeyValue3"){
    return new KeyValue();
  } else if(name == "IKeyValue4"){
    return new KeyValue();
  } else if(name == "IPriorityQueue1"){
    return new PriorityQueue1();
  } else if(name == "IPriorityQueue2"){
    return new PriorityQueue1();
  } else if(name == "IPriorityQueue3"){
    return new PriorityQueue1();
  } else if(name == "IPriorityQueue4"){
    return new PriorityQueue_1();
  } else {
    return NULL;
  }
}

extern "C" {

ObjectFactory * createObjectFactory(){
  return new Factory02();  
}

}
