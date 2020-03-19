//ISAAC RUELAS CASTILLO ASSIGNMENT 3 PROBLEM 1
#include <iostream>
#include "Pair.h"
using namespace std;
int main()
{
	Pair p1(5, 10);
	Pair p2(1, 2);
	// Outputs 5 and 10
	cout << p1.get1() << " " << p1.get2() << endl;
	// Outputs 1 and 2
	cout << p2.get1() << " " << p2.get2() << endl;

	Pair p3 = p2 + p1;//you can flip p2 and p1 and it will still work
	// Outputs 6 and 12
	cout << p3.get1() << " " << p3.get2() << endl;
	p3 = p3 + 2 ;//the p3=2+p3 doesnt work becuase the operator does not match the operands in other words, the object on the left hand side doesnt match the pair type since
	//2 is a type int. plus its not a global or a friend of the PAIR class so we have to overload the operator+ in order to match the order of parameters.
	// Outputs 8 and 14
	cout << p3.get1() << " " << p3.get2() << endl;
}