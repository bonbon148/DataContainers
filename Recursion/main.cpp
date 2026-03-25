#include<iostream>
using namespace std;

double Power(double a, int n);
void Fibonacci(int n, int a = 0, int b = 1);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	int a;
	//cout << "¬ведите основание степени: "; cin >> a;
	//cout << "¬ведите показатель степени: "; cin >> n;
	//cout << Power(a, n) << endl;
	cout << "¬ведите предел р€да ‘ибоначчи: "; cin >> n;
	Fibonacci(n, 22, 33);
	cout << endl;

	main();
}


double Power(double a, int n)
{
	return n == 0 ? 1 : n > 0 ? a * Power(a, n - 1) : 1 / Power(a, -n);
	//if (n == 0)return 1;
	//else if (n > 0)return a * Power(a, n - 1);
	//else return 1 / Power(a, -n);
	//else return 1 / a * Power(a, n + 1);
}

void Fibonacci(int n, int a, int b)
{
	if (a > n)return;
	cout << a << "\t";
	Fibonacci(n, b, a + b);
}