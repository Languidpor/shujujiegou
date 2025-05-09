/**
*  2023.3.14
*  题目描述：
*  按要求将1到10000之间的数打印输出。要求：
*  a)随机乱序；
*  b)不能重复；
*  c)全部输出，不能遗漏；
*  d)如果要用到数据容器，只能用数组。
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
		//冒泡算法随机交换位置
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