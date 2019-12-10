#include <iostream>
#include "polynomial.h"

using namespace std;

int main()
{
	int a;
	string s;
	cout << "Polynomial input rules:" << endl;
	cout << "1. 0 < x, y, z degrees < 10 (integer)" << endl;
	cout << "2. Do not enter capital letters" << endl;
	cout << "   X1Y2Z4 - :(  bad, very bad" << endl;
	cout << "   x1y2z4 - :)  you cool" << endl;
	cout << "3. You must write degree!!!" << endl;
	cout << "   xyz - bad, x1y1z1 - good" << endl;
	cout << "4. Double through point" << endl;
	cout << "   3,5x1 - no, 3.5x1 - yes" << endl;
	cout << "5. Please, dont write rubbish :)" << endl;
	try 
	{
		cout << "Enter the polynom: ";
		cin >> s;
		polynom_string str1(s);
		Polynom pol(str1);
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
		cout << ":(" << endl;
	}
	cin >> a;
}