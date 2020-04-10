#pragma once
#include <iostream>

using namespace std;
class Frac
{
	int m;
	int n;
public:
	Frac() { m = 0; n = 1; }
	Frac(int a) { m = a; n = 1; }
	Frac(int a, int b) {
		m = a; n = b;
		CheckZero();
		Reduction();
	}
	Frac(const Frac & a) {
		m = a.m; 
	n = a.n; 
	}
	int GetNum() {return m;}
	int GetDenom() { return n; }
	int GetInt() { return (m / n); }
	void Reverse() { int temp; temp = m; m = n; n = temp; }
	void CheckZero() { if (n == 0) throw 1; }
	double GetReal() { return (static_cast<double>(m) / n); }
	int GetNod(int a,int b) {
		if (b == 0) 
			return a;
		else 
			return GetNod(abs(b), abs(a) % abs(b));
	}
	void Reduction();
	Frac& operator=(Frac &a);
	Frac & operator+(Frac &a);
	void operator+=(Frac &a);
	Frac & operator-(Frac &a);
	Frac & operator*(Frac &a);
	Frac & operator/(Frac &a);
	void operator-=(Frac &a);
	void operator*=(Frac &a);
	void operator/=(Frac &a);
	Frac &operator++();
	Frac operator++(int);
	Frac &operator--();
	Frac operator--(int);
	Frac &operator-();
	bool operator==(Frac &a);
	bool operator!=(Frac &a) { return !(*this == a); }
	bool operator>(Frac &a);
	bool operator>=(Frac &a) { return !(*this < a); }
	bool operator<(Frac &a);
	bool operator<=(Frac &a) { return !(*this > a); }
	friend ostream& operator<< (ostream& os, const Frac& a);
	friend istream& operator>> (istream& is, const Frac& a);
	~Frac();
};

