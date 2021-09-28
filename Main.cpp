/*
Natalia Kellerman
C++ 2021
Due: Wednesday, September 29th
Lab 3 User and File IO
Write an interactive C++ program that computes and outputs the mean and
population standard deviation of a set of four integers that are inputted
by a file called “inMeanStd.dat”
*/

#include <iostream>
#include <cmath>
#include <fstream> 

//return_type FunctionName(int num1, int num2, int num3, int num4);
float findMean(int num1, int num2, int num3, int num4);
float findStandardDev(float mean, int num1, int num2, int num3, int num4);

using namespace std;
int main()
{
	cout << "Choose four integer values, one on each line:" << endl;

	/*declaring the integers.I think laying out the code like this makes it so there would be one
	integer on each line so that's why it is set up like this. In the output now each integer will be
	input on a different line by the user and that is how the program will know which number is which*/

	int num1;
	int num2;
	int num3;
	int num4;
	int n = 4;

	cin >> num1 >> num2 >> num3 >> num4;

	// calculate the mean

	float user_mean = findMean(num1, num2, num3, num4);

	cout << "The Mean of the four values is: " << user_mean << endl;

	// calculate the standard deviation
	/* I did not know what standard deviation is becuase I have not takn stats so this formula
	in the code I found online from Chegg*/

	float user_sdv;
	user_sdv = findStandardDev(user_mean, num1, num2, num3, num4);

	cout << "The Standard Deviation of the four values is: " << findStandardDev(user_mean, num1, num2, num3, num4) << endl << endl << endl;

	ifstream infile;
	infile.open("outMeanStd.dat”");

	int input1, input2, input3, input4;
	infile >> input1;
	infile >> input2;
	infile >> input3;
	infile >> input4;

	cout << "The numbers pulled from the file are: " << endl << input1 << endl << input2 << endl << input3 << endl << input4 << endl << endl;

	//mean of numbers pulled from file
	float file_mean = findMean(input1, input2, input3, input4);

	cout << "The mean of these four values is: " << file_mean << endl;

	//standard deviation of numbers pulled from file
	float file_sdv;
	file_sdv = findStandardDev(file_mean, input1, input2, input3, input4);

	cout << "The Standard Deviation of these four values is: " << file_sdv << endl;

	return 0;
}

float findMean(int num1, int num2, int num3, int num4) {
	return (num1 + num2 + num3 + num4) / (4 * 1.0);
}

float findStandardDev(float mean, int num1, int num2, int num3, int num4) {
	float sdev;
	sdev = pow((num1 - mean), 2) + pow((num2 - mean), 2) + pow((num3 - mean), 2) + pow((num4 - mean), 2);
	sdev = sdev / (3);
	sdev = sqrt(sdev);

	return sdev;
}



