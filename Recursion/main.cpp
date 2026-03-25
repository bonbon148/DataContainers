#include<iostream>
using namespace std;

double Power(double a, int n);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	int a;
	cout << "¬ведите основание степени: "; cin >> a;
	cout << "¬ведите показатель степени: "; cin >> n;
	cout << Power(a, n) << endl;

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