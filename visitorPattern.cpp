// visitorPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
#include<stdio.h>
#include<iostream>
class element{
	virtual void accept(class visitor &v) = 0;
};

class bread : public element{
public:
	void accept(visitor &v);
	std::string breadfunc(){return "bread";}
};
class onion : public element{
public:
	void accept ( visitor &v);
	std::string onionfunc(){ return "onion";}
};

class visitor{
public: virtual void visit( bread *e) = 0;
		virtual void visit( onion *e) = 0;
};
void bread::accept( visitor &v){
	v.visit(this);
}
void onion::accept( visitor &v){
	v.visit(this);
}

class eatvisitor : public visitor{
	void visit( bread * e){
	std::cout<<"\n eat "<<e->breadfunc();
	}
	void visit( onion * e){
	std::cout<<"\n eat "<<e->onionfunc();
	}
};

class beatvisitor : public visitor{
	void visit( bread * e){
		std::cout<<"\n beat "<<e->breadfunc();
	}
	void visit( onion * e){
		std::cout<<"\n beat "<<e->onionfunc();
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	eatvisitor e;
	beatvisitor b;
	bread *x = new bread();
	onion *y = new onion();
	x->accept(e);
	y->accept(b);
	x->accept(b);
	y->accept(e);
	int stopx;
	std::cin>>stopx;
	return 0;
}

