// LABARECT.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "Frac.h"

int main()
{
	Frac a(2,3);
	Frac b(2,4);
	Frac c(5);
	Frac d(9, 4);
	int x=d.GetInt();
	double y = d.GetReal();
	Frac e;
	e = --c;
	cout << e<<endl;
	e = -c;
	++c;
	d = c / a;
	a *= b;
	cout << a;
	
}

