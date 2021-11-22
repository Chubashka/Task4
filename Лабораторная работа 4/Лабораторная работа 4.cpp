#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

double sumN(double, double, double&);
double sumE(double, double, double&);

int main()
{
	char s;
	do
	{
		system("cls");
		setlocale(LC_ALL, "RUS");
		cout << "Задание 1" << endl;
		double n; //число слагаемых в частичной сумме
		double x, last, sum, func, c; // Значение аргумента, последнее слагаемое, частичная сумма, значение функции, для проверки на целое число 
		do
		{
			cout << "Введите число слагаемых: " << endl;
			cin >> n;
		    c = n - int(n);
		} while (n < 0 || c > 0);
		do
		{
			cout << "Введите значение аргумента меньше 1: " << endl;
			cin >> x;
		} while (x >= 1);
		func = 1 / sqrt(1 - x * x);
		sum = sumN(n, x, last);
		cout << "Точное значение функции = " << func << endl;
		cout << "Частичная сумма ряда = " << sum << endl;
		cout << "Абсолютная погрешность = " << fabs(func - sum) << endl;
		cout << "Последнее слагаемое = " << last << endl;

		cout << "Задание 2" << endl;
		double E;
		do
		{
			cout << "Введите значение аргумента меньше 1: " << endl;
			cin >> x;
		} while (x >= 1);
		cout << "Задайте погрешность: ";
		cin >> E;
		sum = sumE(x, E, n);
		func = 1 / sqrt(1 - x * x);
		cout << "Точное значение функции = " << func << endl;
		cout << "Частичная сумма ряда с выбранной погрешностью = " << sum << endl;
		cout << "Был использовано при подсчете " << n << " члена ряда" << endl;
		sum = sumE(x, E / 10, n);
		cout << "Частичная сумма ряда c точностью, большей в 10 раз, чем указанная = " << sum << endl;
		cout << "Был использовано при подсчете " << n << " члена ряда" << endl;
		cout << "Запустить повторно задачу (y/n)";
		cin >> s;
	} while (s == 'y');
	system("pause");
}

double sumN(double n, double x, double &last)
{
	last = 1;
	double sum = last;
	double l = -1; // для наращивания числителя
	double t = -2; // для наращивания знаменатиля
	for (double i = 1; i < n; ++i)
	{
		++l;
		t = t + 2;
		double r; // Отношение i к (i-1)
		r = (i + l) * x * x / (t + 2);
		last *= r;
		sum += last;
	}
	return sum;
}

double sumE(double x, double E, double &n)
{
	double last = 1;
	double sum = last;
	double l = -1; // для наращивания числителя
	double t = -2; // для наращивания знаменатиля
	for (n = 1; fabs(last) > E; ++n)
	{
		++l;
		t = t + 2;
		double r; // Отношение i к (i-1)
		r = (n + l) * x * x / (t + 2);
		last *= r;
		sum += last;
	}
	return sum;
}