#include "Movies.h"
#include<string>
#include <iostream>

Movies::Movies()
{}

void Movies::setMovie(std::string name[])
{
	for(int i=0;i<6;i++)
	m[i] = name[i];
	
}


	void Movies::bubbleSort(int n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j <= 1-i ; j++)
			{
				if (m[i][0] > m[i + 1][0])
				{
					swap(m[i], m[i + 1]);
					
				}
			}
		}
	}




void Movies::swap(std::string& a, std::string& b)
{
	char temp[sizeof(a)];

		for (int walk = 0; walk < a.size(); walk++)//copies a to temp
			temp[walk] = a[walk];

		for(int run=0;run<b.size();run++)//copies b to a
				a[run] = b[run];

		for(int sprint=0;sprint<a.size();sprint++)//copies temp to b
				b[sprint] = temp[sprint];
}

std::string Movies::getMovie(int index)
{ 
	
	return m[index];


}