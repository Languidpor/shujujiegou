/*
   Q2.Horner法则
   用于计算多项式f(x)=a0+a1*x+a2*x^2+……an*x^n的值
   */

#include<iostream>
#include<vector>

int n, x;

using namespace std;

double fun(const vector<double>& a, int n, int x);

int main()
{
	cout << "多项式的最大次数为：" << endl;
	cin >> n;
	cout << "多项式每一项的系数分别为：" << endl;
	vector<double> a(n + 1);
	for (int i = 0; i <= n; i++)
	{
		cin >> a[i];
	}
	cout << "自变量x的值为：" << endl;
	cin >> x;

	cout << "f(" << x << ") = " << fun(a, n, x) << endl;

	return 0;
}

double fun(const vector<double> &a, int n, int x)
{
	double poly = 0;
	for (int i = n; i >= 0; i--)
	{
		poly = x * poly + a[i];
	}
	return poly;
}