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
		str = s;
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

class List
{
	Link* pFirst;
	void Insert(double c, int d);
	void Cancellation();
public:
	List()
	{
		Link* p = new Link;
		p->coefficient = 0;
		p->degree = -1;
		p->pNext = nullptr;
		pFirst = p;
	}
	List(polynom_string _s);
	List(const List& l);
	List& operator=(const List& l);
	List& operator+=(const List& l);
	List operator+(const List& l);
	List operator*(const List& l);
	List MultConst(double c);
	double ValuePoint(double x, double y, double z);
	//void Insert(double c, int d);
	//void Cancellation();
	//void SetPolynom(polynom_string _s);
	void print();
	void badprint();
	~List()
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