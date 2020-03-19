//ISAAC RUELAS CASTILLO ASSIGNMENT 3 PROBLEM 4
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	char Reduction(int count);
	void Results(int total, int one, int two, int three, int four, int five, int six, int seven, int eight, int nine);
	
	string c;
	ifstream nums;

	int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0, seven = 0, eight = 0, nine = 0, total = 3295;
	void inputNumbers(int c, int& one, int& two, int& three, int& four, int& five, int& six, int& seven, int& eight, int& nine);
	nums.open("C:\\Users\\Isaac's PC\\Documents\\enrollments.txt");

	int counter = 0;
	while (getline(nums, c))
	{
		counter++;
		string grab = c.substr(0, 1);

		int num = stoi(grab);
		inputNumbers(num, one, two, three, four, five, six, seven, eight, nine);//this will send it to the function and create the counter
	}
	nums.close();
	
	cout << "the total is" << counter;
	Results(total, one, two, three, four, five, six, seven, eight, nine);
}


void inputNumbers(int c, int& one, int& two, int& three, int& four, int& five, int& six, int& seven, int& eight, int& nine)
{


	switch (c)
	{
	case 1:
		one++;
		break;
	case 2:
		two++;
		break;
	case 3:
		three++;
		break;
	case 4:
		four++;
		break;
	case 5:
		five++;
		break;
	case 6:
		six++;
		break;
	case 7:
		seven++;
		break;
	case 8:
		eight++;
		break;
	case 9:
		nine++;
		break;

	}
}

void Results(int total, int one, int two, int three, int four, int five, int six, int seven, int eight, int nine)
{

	cout << "one appeared " << one << " number of times the perent is: " << (double)one / (double)total << endl;
	cout << "two appeared " << two << " number of times the perent is: " << (double)two / (double)total << endl;
	cout << "three appeared " << three << " number of times the perent is: " << (double)three / (double)total << endl;
	cout << "four appeared " << four << " number of times the perent is: " << (double)four / (double)total << endl;
	cout << "five appeared " << five << " number of times the perent is: " << (double)five / (double)total << endl;
	cout << "six appeared " << six << " number of times the perent is: " << (double)six / (double)total << endl;
	cout << "seven appeared " << seven << " number of times the perent is: " << (double)seven / (double)total << endl;
	cout << "eight appeared " << eight << " number of times the perent is: " << (double)eight / (double)total << endl;
	cout << "nine appeared " << nine << " number of times the perent is: " << (double)nine / (double)total << endl;
}