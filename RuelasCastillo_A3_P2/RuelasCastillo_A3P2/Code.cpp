#include "Code.h"
#include<string>
#include<iostream>

Code::Code()
{
}
Code::Code(std::string code)
{
	message = code;
	

}



 Code::Code(int code)
{
	zipCode = code;
	
}

 int Code::Decoder(std::string message)
 {
	 int decode[5];
	 int num1 = NULL, num2 = NULL, total, counter = 0,paste=0,hold=0,tempInt,index=1,size=5;
	 char temp[5];
	 char c[sizeof(message)];//this bit of code creates the char array that holds the string code
	 message.copy(c, message.size() + 1);//copies the string into the array c
	 c[message.size()] = '\0';


	 for (int run = 0; run < 5; run++)//this runs five times and breaks the 25 char word into sections
	 {
		 for (int zero = 0; zero < size; zero++)//this saves copy to a temp array
		 {
			 temp[zero] = c[index];
			 index++;
		 }


		 if (temp[0] == '1')
		  num1 = 7;

		 if (temp[1] == '1' && num1 != NULL)
			 num2 = 4;
		 else if(temp[1] == '1' && num1 == NULL)
			 num1 = 4;

		 if (temp[2] == '1' && num1 != NULL)
			 num2 = 2;
		 else if(temp[2] == '1' && num1 == NULL)
			 num1 = 2;

		 if (temp[3] == '1' && num1 != NULL)
			 num2 = 1;
		 else if (temp[3] == '1' && num1 == NULL)
			 num1 = 1;

		 if (temp[4] == '1')
			 num2 = 0;

		 total = num1 + num2;
		 if (total == 11)
			 total = 0;
		 decode[counter] = total;
		 counter++;

		
		/* hold = paste + total;
		 paste = hold * 10;*/
		 num1 = NULL;
		 num2 = NULL;

	 }
	// std::cout << paste;
	 for (int t = 0; t < 5; t++)
	 {
		 hold = paste + decode[t];
		 paste = hold * 10;
	 }
	 return hold;
 }

 std::string Code::Encoder(int zipCode)
 {
	 std::string zero,one,two,three,four,five,six,seven,eight,nine;
	 int num,counter=1;
	 int holder=0;
	 int finel=0;
	 char arr[27];
	 //these are the start and ends
	 arr[0] = '1';
	 arr[26] = '1';

	 while (zipCode != 0)//this while loop flips the number backwards Ex:99504->40599
	 {
		 num = zipCode % 10;
		 holder = finel + num;
		 finel = holder * 10;
		 zipCode = zipCode /10;//chopping block
	 }
	 while (holder != 0)
	 {
		 num = holder % 10;
		 switch (num)
		 {
		 case 0:
			 zero = "11000";
			 for (int i = 0; i < 5; i++)
			 {
				 arr[counter] = zero[i];
				 counter++;
			 }
			 holder = holder / 10;
			 break;
		 case 1:
			 one = "00011";
			 for (int i = 0; i < 5; i++)
			 {
				 arr[counter] = one[i];
				 counter++;
			 }
			 holder = holder / 10;
			 break;
		 case 2:
			 two = "00101";
			 for (int i = 0; i < 5; i++)
			 {
				 arr[counter] = two[i];
				 counter++;
			 }
			 holder = holder / 10;
			 break;
		 case 3:
			 three = "00110";
			 for (int i = 0; i < 5; i++)
			 {
				 arr[counter] = three[i];
				 counter++;
			 }
			 holder = holder / 10;
			 break;
		 case 4:
			 four = "01001";
			 for (int i = 0; i < 5; i++)
			 {
				 arr[counter] = four[i];
				 counter++;
			 }
			 holder = holder / 10;
			 break;
		 case 5:
			 five = "01010";
			 for (int i = 0; i < 5; i++)
			 {
				 arr[counter] = five[i];
				 counter++;
			 }
			 holder = holder / 10;
			 break;
		 case 6:
			 six = "01100";
			 for (int i = 0; i < 5; i++)
			 {
				 arr[counter] = six[i];
				 counter++;
			 }
			 holder = holder / 10;
			 break;
		 case 7:
			 seven = "10001";
			 for (int i = 0; i < 5; i++)
			 {
				 arr[counter] = seven[i];
				 counter++;
			 }
			 holder = holder / 10;
			 break;
		 case 8:
			 eight = "10010";
			 for (int i = 0; i < 5; i++)
			 {
				 arr[counter] = eight[i];
			 counter++;
			}
			 holder = holder / 10;
			 break;
		 case 9:
			 nine = "10100";
			 for (int i = 0; i < 5; i++)
			 {
				 arr[counter] = nine[i];
				 counter++;
			 }
			 holder = holder / 10;
			 break;
		 default:
			std::cout << "we dont know what happened ERROR ERROR DESTROY DESTROY MALFUNCTION IN 5.... 4.... 3... 2... 1.... FAJSFIJsdhasdkdhkIOQWVICh cHWFCHOF";
		 }

	 }


	 return arr;
 }
