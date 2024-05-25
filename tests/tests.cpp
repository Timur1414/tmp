#include <gtest/gtest.h>
#include <gmock/gmock.h>

class Prototype{
public:
	virtual ~Prototype(){

	}
	virtual Prototype* Clone() const = 0;
protected:
	Prototype(){

	}
};
class ConcretePrototype:public Prototype{
public:
	ConcretePrototype(){

	}
	ConcretePrototype(const ConcretePrototype& cp){
		*this = cp;	
		cout<<"ConcretePrototype copy ..."<<endl;
	}
	~ConcretePrototype(){

	}
	virtual Prototype* Clone() const{
		return new ConcretePrototype(*this);
	}
};

