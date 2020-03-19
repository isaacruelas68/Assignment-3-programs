#pragma once

#include<string>
class Code
{
public:
	Code();
	std::string Encoder(int zipCode);//turns the code to a string
	int Decoder(std::string message);//turns the barcode into the 5 digit zipcode
	//constructors
	Code(int code);
	Code(std::string code);

private:
	std::string message;
	int zipCode;
};

