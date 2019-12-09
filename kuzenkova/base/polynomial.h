#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include <string>
#include <iostream>

using namespace std;

class polynom_string
{
	string str;
public:
	polynom_string(string s)
	{
		for (int i = 0; i < s.length(); i++)
			if (s[i] != ' ')
				str += s[i];
		if (!isCorrect())
			throw "Wrong polynom";
	}
	bool isCorrect();
	string getstr() const
	{
		return str;
	}
};

struct Link
{
	Link* pNext;
	double coefficient;
	int degree;
};

class Polynom
{
	Link* pFirst;
	void Insert(double c, int d);
	void Cancellation();
public:
	Polynom()
	{
		Link* p = new Link;
		p->coefficient = 0;
		p->degree = -1;
		p->pNext = nullptr;
		pFirst = p;
	}
	Polynom(polynom_string _s);
	Polynom(const Polynom& l);
	Polynom& operator=(const Polynom& l);
	Polynom& operator+=(const Polynom& l);
	Polynom operator+(const Polynom& l);
	Polynom operator*(const Polynom& l);
	Polynom MultConst(double c);
	double ValuePoint(double x, double y, double z);
	//void Insert(double c, int d);
	//void Cancellation();
	//void SetPolynom(polynom_string _s);
	void print();
	void badprint();
	~Polynom()
	{
		while (pFirst != nullptr)
		{
			Link* p = pFirst;
			pFirst = p->pNext;
			delete p;
		}
	}
};
#endif