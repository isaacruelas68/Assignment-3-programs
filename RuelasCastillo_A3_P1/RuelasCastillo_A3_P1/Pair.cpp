#include "Pair.h"


Pair::Pair() 
{
	this->num1 = 0;
	this->num2 = 0;
}
Pair::Pair(int num1, int num2) 
{
	this->num1 = num1;
	this->num2 = num2;
}
int Pair::get1()
{
	return num1;
}
int Pair::get2()
{
	return num2;
}
Pair operator+(const Pair& e1, const Pair& e2)
{
	Pair newPair;
	newPair.num1 = e1.num1 + e2.num1;
	newPair.num2 = e1.num2 + e2.num2;
	return newPair;
}
Pair operator+(int otherNum, Pair& a)
{
	Pair newPair(a.num1, a.num2);
	newPair.num1 = otherNum + a.num1;
	newPair.num2 = otherNum + a.num2;
	return newPair;
}

Pair operator+(Pair&t,int otherNum)
{
	Pair newPair(t.num1, t.num2);
	newPair.num1 = t.num1+otherNum;
	newPair.num2 = t.num2+otherNum;
	return newPair;
}



