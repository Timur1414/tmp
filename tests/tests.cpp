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
		std::cout<<"ConcretePrototype copy ..."<<std::endl;
	}
	~ConcretePrototype(){

	}
	virtual Prototype* Clone() const{
		return new ConcretePrototype(*this);
	}
};

TEST(Prototype_tests, test3) {
    std::ostringstream oss;
    std::streambuf* cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    Prototype* p = new ConcretePrototype();
    Prototype* p1 = p->Clone();

    std::cout.rdbuf(cout_streambuf);
    EXPECT_EQ(oss.str(), "ConcretePrototype copy ...\n");
}
