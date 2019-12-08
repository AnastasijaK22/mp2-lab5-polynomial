#include <iostream>
#include "polynomial.h"

using namespace std;

int main()
{
	int a;
	//int b = 10;
	//b = pow(b, 2);
	//cout << b << endl;
	string s = "1+x1y2";
	polynom_string str(s);
	List pol(str);
	pol.print();
	cout << endl;
	//pol.Cancellation();
	List poly;
	poly = pol;
	cout << pol.ValuePoint(2, 2, 1) << endl;
	cin >> a;
}