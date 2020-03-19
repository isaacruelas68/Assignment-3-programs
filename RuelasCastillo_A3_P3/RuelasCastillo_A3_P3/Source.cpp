//ISAAC RUELAS CASTILLO ASSIGNMENT 3 PROBLEM 3
#include<iostream>
#include"Movies.h"
#include<cstring>
using namespace std;
 
int main()
{
	string movie[6] = { "Black Panther,PG-13         ","Avengers:Infinity War,PG-13","A  Wringkle  In  Time, PG  ","Ready  Player  One, PG-13   ","Red  Sparrow, R            ","The  Incredibles  2, G     " };
	Movies call;
	call.setMovie(movie);
	cout << "Here is your movie list:" << endl;
	for (int t = 0; t < 6; t++)
		cout <<call.getMovie(t) << " ";

	call.bubbleSort(6);
	cout << endl;
	cout << "Here is your New movie list organized alphabetically: " << endl;
	for (int p = 0; p < 6; p++)
		cout << call.getMovie(p)<<" ";




}