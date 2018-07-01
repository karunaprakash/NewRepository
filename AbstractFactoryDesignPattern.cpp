#include <iostream>
using namespace std;
#define SIMPLE true
// Comments addedas part of Branch_Dev2
//Jira 102
class Shape
{
	public:
	virtual void displayItem() =0;
};

class Circle : public Shape
{
	public:
	void displayItem() { cout<<"Circle "<<endl;}
};

class Circle1 : public Shape
{
	public:
	void displayItem() { cout<<"Circle1 "<<endl;}
};

class Square : public Shape
{
	public:
	void displayItem() { cout<<"Square "<<endl;}
};

class Rectangle : public Shape
{
	public:
	void displayItem() { cout<<"Rectangle "<<endl;}
};


class IFactory
{
	public:
	virtual Shape* CreateCurvedInsance() = 0;
	virtual Shape* CreateStraightInsance() = 0;
};

class SimpleShapeFactory : public IFactory
{
	public:
	Shape* CreateCurvedInsance()
	{
		return new Circle();
	}
	Shape* CreateStraightInsance()
	{
		return new Square();
	}
};

class RobustShapeFactory : public IFactory
{
	public:
	Shape* CreateCurvedInsance()
	{
		return new Circle1();
	}
	Shape* CreateStraightInsance()
	{
		return new Rectangle();
	}
};

int main() {
	IFactory* FactoryPtr =NULL;
	#ifndef SIMPLE
	   FactoryPtr = new SimpleShapeFactory();
	#elif ROBUST
	   FactoryPtr = new RobustShapeFactory();
	#endif
	Shape* sp[3];
	if ( FactoryPtr )
	{
		sp[0]= FactoryPtr->CreateCurvedInsance();
		sp[1]= FactoryPtr->CreateStraightInsance();
		sp[2]= FactoryPtr->CreateCurvedInsance();
	}
	
	for ( int i = 0; i<3 ;i++)
		sp[i]->displayItem();
	
	return 0;
}