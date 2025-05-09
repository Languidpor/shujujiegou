/*
   Q2.Horner����
   ���ڼ������ʽf(x)=a0+a1*x+a2*x^2+����an*x^n��ֵ
   */

#include<iostream>
#include<vector>

int n, x;

using namespace std;

double fun(const vector<double>& a, int n, int x);

int main()
{
	cout << "����ʽ��������Ϊ��" << endl;
	cin >> n;
	cout << "����ʽÿһ���ϵ���ֱ�Ϊ��" << endl;
	vector<double> a(n + 1);
	for (int i = 0; i <= n; i++)
	{
		cin >> a[i];
	}
	cout << "�Ա���x��ֵΪ��" << endl;
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