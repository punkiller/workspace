// compositePattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>

// abstract base class for Graphics component
class Graphic{
public :
	virtual void print() = 0; 
};
// composite class for groups of graphical shapes / individual shapes / groups of groups
class Composite: public Graphic
{
	public:
		std::vector<Graphic *> shapeList; // list of shapes is stored in this vector
		void add(Graphic *g){
			shapeList.push_back(g);
		}
		void print(){
			for ( std::vector<Graphic *>::iterator itr = shapeList.begin(); itr != shapeList.end(); itr++)
				(*itr)->print();
		}
};
class square : public Graphic{
	int sideLength;
public:
	square(int x = 4){
		sideLength = x;
	}
	void print(){
		std::cout<<"\n A square of side = "<< sideLength;
	}
};

class rectangle: public Graphic{
	int len;
	int wid;
public:
	rectangle(int l=3, int b=2){
		len = l;
		wid = b;
	}
	void print(){
		std::cout<<"n a rectangle of len= "<<len<< "breadth = "<<wid;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	// creating 2 squares 1 rectangle
	square *s1 = new square(7);
	square *s2 = new square(8);
	rectangle *r1 = new rectangle(3,4);

	// creating 2 composites c1
	Composite *c1 = new Composite();
	Composite *c2 = new Composite();
	
	// c1 has a square and rectangle
	c1->add(s1);
	c1->add(r1);

	// c2 has only 1 square
	c2->add(s2);
	
	// invoke print() on a composite or a single object
	r1->print();
	c1->print();
	c2->print();
	
	return 0;
}

