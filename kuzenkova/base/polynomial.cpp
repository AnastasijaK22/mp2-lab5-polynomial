#include "polynomial.h"

bool polynom_string::isCorrect()
{
	return true;
}

List::List(polynom_string _s)
{
	Link* p = new Link;
	p->coefficient = 0;
	p->degree = -1;
	p->pNext = nullptr;
	pFirst = p;
	string s = _s.getstr() + "+";
	if (s[0] != '-')
		s = "+" + s;
	int length = s.length();
	int i = 0;
	while (i != (length - 1))
	{
		double c;
		if ((s[i + 1] == 'x') || (s[i + 1] == 'y') || (s[i + 1] == 'z'))
		{
			if (s[i] == '+')
				c = 1;
			else
				c = -1;
			i++;
		}
		else
		{
			string temp;
			int j = s.find_first_of("-+xyz", i + 1);
			while (i < j)
			{
				temp = temp + s[i];
				i++;
			}
			c = stof(temp);
		}
		int x = 0, y = 0, z = 0;
		for (int j = 0; j < 3; j++)
		{
			switch (s[i])
			{
			case 'x':
				x = s[i + 1] - '0';
				i += 2;
				break;
			case 'y':
				y = s[i + 1] - '0';
				i += 2;
				break;
			case 'z':
				z = s[i + 1] - '0';
				i += 2;
				break;
			}
		}
		int d = x * 10000 + y * 100 + z;
		Insert(c, d);
	}
	Cancellation();
}

List::List(const List& l)
{
	Link* p = new Link;
	pFirst = p;
	p->coefficient = 0;
	p->degree = -1;
	p->pNext = nullptr;
	Link* pp = l.pFirst->pNext;
	while (pp != nullptr)
	{
		p->pNext = new Link;
		p = p->pNext;
		p->coefficient = pp->coefficient;
		p->degree = pp->degree;
		p->pNext = nullptr;
		pp = pp->pNext;
	}
}

List& List::operator=(const List& l)
{
	if (this != &l)
	{
		Link* p = pFirst;
		p = p->pNext;
		pFirst->pNext = nullptr;
		while (p != nullptr)
		{
			Link* pp = p;
			p = pp->pNext;
			delete pp;
		}
		p = pFirst;
		Link* pp = l.pFirst->pNext;
		while (pp != nullptr)
		{
			p->pNext = new Link;
			p = p->pNext;
			p->coefficient = pp->coefficient;
			p->degree = pp->degree;
			p->pNext = nullptr;
			pp = pp->pNext;
		}
	}
	return *this;
}

void List::Insert(double c, int d)
{
	Link* p = new Link;
	p->coefficient = c;
	p->degree = d;
	Link* pp = pFirst;
	while (pp->pNext != nullptr)
	{
		Link* ppp = pp->pNext;
		if (d <= ppp->degree)
		{
			p->pNext = pp->pNext;
			pp->pNext = p;
			break;
		}
		pp = pp->pNext;
	}
	if (pp->pNext == nullptr)
	{
		pp->pNext = p;
		p->pNext = nullptr;
	}
}

void List::Cancellation()
{
	Link* p = pFirst;
	Link* pp = p->pNext;
	if (pp != nullptr)
	{
		while (pp->pNext != nullptr)
		{
			if (pp->degree == pp->pNext->degree)
			{
				Link* temp = pp->pNext;
				pp->coefficient += temp->coefficient;
				pp->pNext = temp->pNext;
				delete temp;
			}
			else
			{
				if (pp->coefficient != 0)
				{
					p = pp;
					pp = pp->pNext;
				}
				else
				{
					Link* temp = pp;
					p->pNext = temp->pNext;
					pp = pp->pNext;
					delete temp;
				}
			}
		}
		if (pp->coefficient == 0)
		{
			p->pNext = nullptr;
			delete pp;
		}
	}
	//здесь могла быть ваша реализация :)
}

/*
void List::SetPolynom(polynom_string _s)
{
	string s = _s.getstr() + "+";
	if (s[0] != '-')
		s = "+" + s;
	int length = s.length();
	int i = 0;
	while (i != (length - 1))
	{
		double c;
		if ((s[i + 1] == 'x') || (s[i + 1] == 'y') || (s[i + 1] == 'z'))
		{
			if (s[i] == '+')
				c = 1;
			else
				c = -1;
			i++;
		}
		else
		{
			string temp;
			int j = s.find_first_of("-+xyz", i + 1);
			while (i < j)
			{
				temp = temp + s[i];
				i++;
			}
			c = stof(temp);
		}
		int x = 0, y = 0, z = 0;
		for (int j = 0; j < 3; j++)
		{
			switch (s[i])
			{
			case 'x':
				x = s[i + 1] - '0';
				i += 2;
				break;
			case 'y':
				y = s[i + 1] - '0';
				i += 2;
				break;
			case 'z':
				z = s[i + 1] - '0';
				i += 2;
				break;
			}
		}
		int d = x * 10000 + y * 100 + z;
		(*this).Insert(c, d);
	}
	(*this).Cancellation();
}
*/

void List::print()
{
	Link* p = pFirst;
	p = p->pNext;
	string s;
	while (p != nullptr)
	{
		int x = p->degree / 10000;
		int y = (p->degree % 10000) / 100;
		int z = p->degree % 100;
		if (p->coefficient > 0)
			s = s + "+";
		if ((x + y + z) != 0)
		{
			if ((p->coefficient != -1) && (p->coefficient != 1))
				s += to_string(p->coefficient);
			else
				if (p->coefficient == -1)
					s = s + "-";
		}
		else
			s += to_string(p->coefficient);
		if (x != 0)
		{
			s += "x";
			s += to_string(x);
		}
		if (y != 0)
		{
			s += "y";
			s += to_string(y);
		}
		if (z != 0)
		{
			s += "z";
			s += to_string(z);
		}
		//cout << p->coefficient << 'x' << x << 'y' << y << 'z' << z;
		p = p->pNext;
	}
	if (s.length() == 0)
		s = "0";
	if (s[0] == '+')
		s.erase(0, 1);
	cout << s;
}

void List::badprint()
{
	Link* p = pFirst;
	while (p != nullptr)
	{
		cout << p->coefficient << ' ' << p->degree << endl;
		p = p->pNext;
	}
}

List& List::operator+=(const List& l)
{
	Link* p = l.pFirst->pNext;
	while (p != nullptr)
	{
		Insert(p->coefficient, p->degree);
		p = p->pNext;
	}
	Cancellation();
	return *this;
}

List List::operator+(const List& l)
{
	List temp(*this);
	temp += l;
	return temp;
}

List List::operator*(const List& l)
{
	List temp;
	Link* p = pFirst->pNext;
	while (p != nullptr)
	{
		Link* pp = l.pFirst->pNext;
		while (pp != nullptr)
		{
			temp.Insert(p->coefficient * pp->coefficient, p->degree + pp->degree);
			pp = pp->pNext;
		}
		temp.Cancellation();
		p = p->pNext;
	}
	return temp;
}

List List::MultConst(double c)
{
	List temp(*this);
	Link* p = temp.pFirst->pNext;
	while (p != nullptr)
	{
		p->coefficient *= c;
		p = p->pNext;
	}
	temp.Cancellation();
	return temp;
}

double List::ValuePoint(double x, double y, double z)
{
	double result = 0;
	Link* p = pFirst->pNext;
	while (p != nullptr)
	{
		int sx = p->degree / 10000;
		int sy = (p->degree % 10000) / 100;
		int sz = p->degree % 100;
		double temp = pow(x, sx) * pow(y, sy) * pow(z, sz);
		result += temp * p->coefficient;
		p = p->pNext;
	}
	return result;
}