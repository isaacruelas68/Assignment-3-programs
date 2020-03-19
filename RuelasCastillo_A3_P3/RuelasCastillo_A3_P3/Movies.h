#pragma once
#include<string>
class Movies
{
public:
	Movies();
	std::string getMovie(int index);
	std::string getRating();
	void bubbleSort( int n);
	void swap(std::string& a , std::string& b);
	void setMovie(std::string movie[6]);
	void setRating(std::string rating);

private:
	std::string m[6];
	int counter=0;
};

