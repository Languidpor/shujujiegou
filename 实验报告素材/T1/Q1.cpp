/**
*  Q1.设m是由0,1,2,3,4,5,6,7,8,9组成的一个十位数，其中数字不重复、不遗漏，首位数字非零。
*  若m是平方数列，则输出。
*  例如：1026753849=32043^2
*/

#include<iostream>
#include<math.h>

using namespace std;

bool fun(long long int n)
{
	// 将一个十位数拆分到一个内存为10的数组中
	int a[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		a[i] = n / (pow(10, 9 - i));

		//强制类型转换，将double型转换为int型，确保变量n为long long int型
		n = n % (int)(pow(10, 9 - i));
	}

	// 判断数组中的元素是否都互不相等
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
	// 若仅创建整型变量m，在后续计算m*m时得到的结果值会有负(得到的结果值超出整型变量最大值)，故要创建long long int型
	long long int m;

	for (m = 31991; m < 99381; m++)
	{
		// n的范围为1023456789~9876543210
		long long int n = m * m;
		if (fun(n))
			cout << n << " = " << m << " * " << m << endl;
	}

	return 0;
}