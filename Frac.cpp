#include "pch.h"
#include "Frac.h"


void Frac::Reduction() 
{
	int x = m; int y = n;
	m /= GetNod(x, y);
	n /= GetNod(x, y);
}

Frac& Frac::operator=(Frac &a)
{
	m = a.m; n = a.n;
	return *this;
}

Frac & Frac::operator+(Frac &a)
{
	Frac res(*this);
	res += a;
	return res;
}

void Frac::operator+=(Frac &a)
{
	if (n == a.n)
		m += a.m;
	else
	{
		int x = n;
		n *= a.n;
		m = (m * a.n) + (a.m * x);
	}
	Reduction();
}

void Frac::operator-=(Frac &a)
{
	if (n == a.n)
		m -= a.m;
	else
	{
		n *= a.n;
		m = (m * a.n) - (a.m * n);
	}
	Reduction();
}

Frac & Frac::operator-(Frac &a)
{
	Frac res(*this);
	res -= a;
	return res;
}

void Frac::operator*=(Frac &a)
{
	m *= a.m; n *= a.n;
	Reduction();
}

Frac & Frac::operator*(Frac &a)
{
	Frac res(*this);
	res *= a;
	return res;
}

void Frac::operator/=(Frac &a)
{
	//this *= a.Reverse();
	m = a.n*m; n = a.m*n;
	Reduction();
}

Frac & Frac::operator/(Frac &a)
{
	Frac res(*this);
	res /= a;
	return res;
}

Frac & Frac::operator++()
{
	m += n;
	return *this;
}

Frac Frac::operator++(int)
{
	Frac temp(*this);
	m += n;
	return temp;
}

Frac & Frac::operator--()
{
	m -= n;
	return *this;
}

Frac Frac::operator--(int)
{
	Frac temp(*this);
	m -= n;
	return temp;
}

Frac& Frac::operator-()
{
	Frac temp(*this);
	temp.m = -m;
	return temp;
}

bool Frac::operator==(Frac &a)
{
	if ((m == a.m) && (n == a.n))
		return 1;
	else return 0;
}

bool Frac::operator>(Frac &a)
{
	int xm = m * a.n;
	int ym = a.m*n;
	if (xm > ym)
		return 1;
	else return 0;
}

bool Frac::operator<(Frac &a)
{
	int xm = m * a.n;
	int ym = a.m*n;
	if (xm < ym)
		return 1;
	else return 0;
}

ostream& operator<< (ostream& os, const Frac &a)
{
	cout << endl;
	os << a.m << "/" << a.n << endl;
	return os;
}

istream& operator>> (istream& is, const Frac& a)
{
	is >> a.m;
	cout << "/";
	is >> a.n;
	return is;
}
Frac::~Frac()
{
}
