/**
*  Q1.��m����0,1,2,3,4,5,6,7,8,9��ɵ�һ��ʮλ�����������ֲ��ظ�������©����λ���ַ��㡣
*  ��m��ƽ�����У��������
*  ���磺1026753849=32043^2
*/

#include<iostream>
#include<math.h>

using namespace std;

bool fun(long long int n)
{
	// ��һ��ʮλ����ֵ�һ���ڴ�Ϊ10��������
	int a[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		a[i] = n / (pow(10, 9 - i));

		//ǿ������ת������double��ת��Ϊint�ͣ�ȷ������nΪlong long int��
		n = n % (int)(pow(10, 9 - i));
	}

	// �ж������е�Ԫ���Ƿ񶼻������
	int f = 1;
	for (int i = 0; i < 10; i++)
		for (int j = i + 1; j < 10; j++)
			if (a[i] == a[j])
				f = 0;
	if (f == 0)  return false;
    if (f == 1)  return true;
}

int main()
{
	// �����������ͱ���m���ں�������m*mʱ�õ��Ľ��ֵ���и�(�õ��Ľ��ֵ�������ͱ������ֵ)����Ҫ����long long int��
	long long int m;

	for (m = 31991; m < 99381; m++)
	{
		// n�ķ�ΧΪ1023456789~9876543210
		long long int n = m * m;
		if (fun(n))
			cout << n << " = " << m << " * " << m << endl;
	}

	return 0;
}