//ISAAC RUELAS CASTILLO ASSIGNMENT 3 PROBLEM 2
#include<iostream>
#include"Code.h"
using namespace std;

int main()
{
	string code="110100101000101011000010011";
	string codes;
	cout << "the code is 110100101000101011000010011 ";
	int zip;
	Code send;
	zip=send.Decoder(code);
	cout << "the message decoded is: "<<endl;
	cout << zip;
	cout << "the message encoded is: " << endl;
	codes = send.Encoder(zip);
	for (int run = 0; run < sizeof(code)-1; run++)
		cout << codes[run];
	
}