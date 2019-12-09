#include <iostream>
#include "polynomial.h"

using namespace std;

int main()
{
	int a;
	string s;
	try 
	{
		cout << "Polynomial input rules:" << endl;
		cout << "1. Polynom degree < 10" << endl;
		cout << "Enter the polynom: ";
		cin >> s;
		polynom_string str1(s);
		Polynom pol(str1);
		//pol.print();
		cout << "Enter polynom to add: ";
		cin >> s;
		polynom_string str2(s);
		Polynom pol1(str2);
		Polynom result;
		result = pol + pol1;
		result.print();
		cout << endl << "Enter polynom to multiplication: ";
		cin >> s;
		polynom_string str3(s);
		Polynom pol2(str3);
		result = pol * pol2;
		result.print();
		double k;
		cout << endl << "Enter constant: ";
		cin >> k;
		result = pol.MultConst(k);
		result.print();
		cout << endl << "Enter the point: ";
		double x, y, z;
		cin >> x >> y >> z;
		cout << pol.ValuePoint(x, y, z);
	}
	catch (const char* b)
	{
		cout << b << endl;
	}
	cin >> a;
}