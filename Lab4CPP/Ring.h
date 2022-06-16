#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

class Ring
{
	int inRadius;
	int outRadius;
	int xCenter;
	int yCenter;
public:
	Ring()
	{
		inRadius = 1;
		outRadius = 2;
		xCenter = 0;
		yCenter = 0;
	}
	Ring(int num1, int num2, int num3, int num4)
	{
		cout << "[1,3], [5,8] method used" << endl;
		int Cenlim1, Cenlim2, Radlim1, Radlim2;
		Cenlim1 = num1;
		Cenlim2 = num2;
		Radlim1 = num3;
		Radlim2 = num4;
		srand(time(NULL));
		srand(rand() * rand() * rand());
		inRadius = (double)rand() / RAND_MAX * ((Radlim2 + 1 - Radlim1) / 2) + Radlim1;
		outRadius = (double)rand() / RAND_MAX * ((Radlim2 - Radlim1) / 2 + 1) + (((Radlim2 + 1 - Radlim1) / 2) + Radlim1);
		xCenter = (double)rand() / RAND_MAX * (Cenlim2 - Cenlim1 + 1) + Cenlim1;
		yCenter = (double)rand() / RAND_MAX * (Cenlim2 - Cenlim1 + 1) + Cenlim1;
		
	}
	int ifPossible(int num1, int num2);
	Ring(string values)
	{
		int space1, space2, space3;
		cout << "1 2 3 4 method used" << endl;
		space1 = values.find(" ");
		space2 = values.find(" ", space1+1);
		space3 = values.find(" ", space2+1);
		xCenter = stoi(values.substr(0, space1));
		yCenter = stoi(values.substr(space1, space2));
		inRadius = stoi(values.substr(space2, space3));
		outRadius = stoi(values.substr(space3, values.size()));
	}

	int getinRadius()
	{
		return inRadius;
	}
	int getoutRadius()
	{
		return outRadius;
	}
	int getxCenter()
	{
		return xCenter;
	}
	int getyCenter()
	{
		return yCenter;
	}
	Ring operator++()
	{
		//++inRadius;
		inRadius = ifPossible(inRadius, outRadius);
		cout << "inplus" << endl;
		return *this;
	}
	Ring operator++(int notused)
	{
		//++outRadius;
		outRadius += 1;
		cout << "outplus" << endl;
		return *this;
	}
	Ring operator*=(int n)
	{
		//outRadius *= n;
		outRadius = outRadius * n;
		cout << "multiplying" << endl;
		return *this;
	}
	void displayValue()
	{
		cout << "Ring with center [" << xCenter << "," << yCenter << "]" << '\n';
		cout << "Radius inside: " << inRadius << ", Outside radius: " << outRadius << '\n';
	}
	void countWidth()
	{
		cout << "Width: " << outRadius-inRadius << '\n';
	}
};

Ring createRing(string num);
