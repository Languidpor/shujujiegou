/**
* 标题: 平方十位数
* 由 0~9 这 10 个数字不重复、不遗漏, 可以组成很多 10 位数.
* 这其中也有很多恰好是平方数(即形如 n^2).
* 比如 1026753849=32043^2
* 就是其中最小的一个平方数.
* 请找出所有这样的平方数
* -----------------------------------------
*
*>  Idea 1.
-- 从 1023456789 开始(当然因为已知 1026753849 是最小的平方数, 可以从这个数开始),
-- 枚举到 9876543210, i.e., x\in[1026753849, 9876543210]
-- 判断数字是否不重复, 即由 0--9 这十个数字构成, 无重复.
    check whether x is consisted by the ten digits 0,1,2,...,9.
-- 令 y=int(sqrt(x)), 判断 y*y==x? 即判断 x 是否为平方数.
-- 但我们希望不要用到 sqrt()函数

*>  Idea 2.
--  令 y\in [31992,99380],  since

in> sqrt(1023456789)
out> 31991.511202

in> sqrt(9876543210)
out> 99380.799001

--  计算 x=y*y
--  判断 x 是否恰好由 0~9 这十个数字构成.

*** NOTE:
使用 int 是不够的.

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

//检验 x 是否恰好由 0~9 这十个数字构成.
//这里用到了 c++ 中的 set 容器. set 容器由平衡二叉树实现, 插入的效率为 O(log N).
bool valid(long long x)
{
    if(x==0)
    {
        return false;
    }

    set<long long> s;

    while(x)
    {
        int d = x%10; // d 是 x 的最后一个数字
        s.insert(d);
        x /= 10;
    }

    return s.size()==10;
}

