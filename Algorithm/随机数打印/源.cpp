/**
*  2023.3.14
*  ��Ŀ������
*  ��Ҫ��1��10000֮�������ӡ�����Ҫ��
*  a)�������
*  b)�����ظ���
*  c)ȫ�������������©��
*  d)���Ҫ�õ�����������ֻ�������顣
*/

#include<cstdio>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

const int MaxNum = 1e4 + 10;
int first_array[MaxNum], second_array[MaxNum];

int main()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10000; ++i)
		first_array[i] = i + 1;
	int index, tmp, rest = 10000;
	for (int i = 0; i < 10000; ++i)
	{
		index = rand() % rest;
		//ð���㷨�������λ��
		second_array[i] = first_array[index];
		tmp = first_array[index];
		first_array[index] = first_array[rest - 1];
		first_array[rest - 1] = tmp;
		rest--;
	}
	for (int i = 0; i < 10000; ++i)
		cout << second_array[i] << endl;
	return 0;
}