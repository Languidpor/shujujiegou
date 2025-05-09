/**
* ����: ƽ��ʮλ��
* �� 0~9 �� 10 �����ֲ��ظ�������©, ������ɺܶ� 10 λ��.
* ������Ҳ�кܶ�ǡ����ƽ����(������ n^2).
* ���� 1026753849=32043^2
* ����������С��һ��ƽ����.
* ���ҳ�����������ƽ����
* -----------------------------------------
*
*>  Idea 1.
-- �� 1023456789 ��ʼ(��Ȼ��Ϊ��֪ 1026753849 ����С��ƽ����, ���Դ��������ʼ),
-- ö�ٵ� 9876543210, i.e., x\in[1026753849, 9876543210]
-- �ж������Ƿ��ظ�, ���� 0--9 ��ʮ�����ֹ���, ���ظ�.
    check whether x is consisted by the ten digits 0,1,2,...,9.
-- �� y=int(sqrt(x)), �ж� y*y==x? ���ж� x �Ƿ�Ϊƽ����.
-- ������ϣ����Ҫ�õ� sqrt()����

*>  Idea 2.
--  �� y\in [31992,99380],  since

in> sqrt(1023456789)
out> 31991.511202

in> sqrt(9876543210)
out> 99380.799001

--  ���� x=y*y
--  �ж� x �Ƿ�ǡ���� 0~9 ��ʮ�����ֹ���.

*** NOTE:
ʹ�� int �ǲ�����.

int             -2147483648 ~ +2147483647   (4 Bytes)
unsigned int    0 ~ 4294967295    (4 Bytes)
long == int
long long       -9223372036854775808 ~ +9223372036854775807    (8 Bytes)
*/

#include <iostream>
#include <set>

using namespace std;

bool valid(long long x);

int main()
{
    cout << "We will output the biggest number which consisted just by the ten digits 0--9." << endl;

    long long x;
    int _count=0;
    for(long long y=31992; y<99381; y++)
    {
        x=y*y;
        if(valid(x))
        {
            _count++;
            cout << x << "==" << y << "^2" << endl;
        }
    }

    cout<<"------------------------------"<<endl;
    cout<<"Total: "<<_count<<" square numbers"<<endl;

    return 0;
}

//���� x �Ƿ�ǡ���� 0~9 ��ʮ�����ֹ���.
//�����õ��� c++ �е� set ����. set ������ƽ�������ʵ��, �����Ч��Ϊ O(log N).
bool valid(long long x)
{
    if(x==0)
    {
        return false;
    }

    set<long long> s;

    while(x)
    {
        int d = x%10; // d �� x �����һ������
        s.insert(d);
        x /= 10;
    }

    return s.size()==10;
}

