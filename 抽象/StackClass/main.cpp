#include <iostream>

#include "Stack.h"

using namespace std;

//Top of Hanoi Tower
void toh(Stack & A, Stack & B, Stack & C);
int top_of_stack(Stack & A, Stack & B, Stack & C);

int main()
{
    int n, i;
    cout<<"Hanoi Tower\n";
    cout<<"Enter the number of disks\nn=";
    cin>>n;
    Stack A;
    Stack B;
    Stack C;

    for (i = n; i >= 1; i--)
    {
        A.push(i);
    }
    //cout<<"A.size()="<<A.size()<<", B.size()="<<B.size()<<", C.size()="<<C.size()<<endl;

    toh(A,B,C);
    return 0;
}

/** 检查 1 位于 A,B,C 哪个栈上.
 *  注意只有一个 1; 1 当然只能位于栈顶.
 */
int top_of_stack(Stack & A, Stack & B, Stack & C)
{
    //A.top->data
    int peek_data;

    if (!A.empty())
    {
        A.peek(peek_data);
        //cout<<"A->peek_data="<<peek_data<<endl;
        if(peek_data==1)
            return 1;
    }

    if (!B.empty())
    {
        B.peek(peek_data);
        //cout<<"B->peek_data="<<peek_data<<endl;
        if(peek_data==1)
            return 2;
    }

    if (!C.empty())
    {
        C.peek(peek_data);
        //cout<<"C->peek_data="<<peek_data<<endl;
        if(peek_data==1)
            return 3;
    }

    //A,B,C 均为空
    return 0;

}

//top of Haino Tower
void toh(Stack & A, Stack & B, Stack & C)
{
    long long int i;
    int x;
    int n;
    n=A.size();
    long long int N;
    N=1<<n;// 即 pow(2,n)
    int a, b, c;//where a,b,c stands the pop value of Stack A, B, C respectively.
    bool pop_A_success=false;
    bool pop_B_success=false;
    bool pop_C_success=false;

    for (i = 0; i < N; i++)
    {
        cout<<"===================="<<endl;
        cout<<"A.size()="<<A.size()<<", B.size()="<<B.size()<<", C.size()="<<C.size()<<endl;

        A.display("A");
        B.display("B");
        C.display("C");
        cout<<"---------------"<<endl;
        x = top_of_stack(A,B,C);//检查1位于哪个栈, 返回 1,2,3 分别对应栈 A,B,C.
        cout<<"x="<<x<<endl;
        if (i % 2 == 0)
        {
            if (x == 1)
            {
                A.pop(a);
                C.push(a);
            }
            else if (x == 2)
            {
                B.pop(b);
                A.push(b);
            }
            else if (x == 3)
            {
                C.pop(c);
                B.push(c);
            }
        }
        else
        {
            if (x == 1)
            {
                pop_B_success = B.pop(b);//B栈顶元素弹出并保存到a中.
                pop_C_success = C.pop(c);//C栈顶元素弹出并保存到b中.
                if(pop_B_success && pop_C_success)
                {
                    if(b < c)
                    {
                        C.push(c);
                        C.push(b);
                    }else if(c < b)
                    {
                        B.push(b);
                        B.push(c);
                    }
                }
                else if (pop_C_success==false)
                {
                    C.push(b);
                }
                else if (pop_B_success == false)
                {
                    B.push(c);
                }
            }
            else if (x == 2)
            {
                pop_A_success = A.pop(a);//A栈顶元素弹出并保存到a中.
                pop_C_success = C.pop(c);//C栈顶元素弹出并保存到b中.
                if(pop_A_success && pop_C_success)
                {
                    if (a < c)
                    {
                        C.push(c);
                        C.push(a);
                    }
                    else if (c < a )
                    {
                        A.push(a);
                        A.push(c);
                    }
                }else if(pop_C_success == false)
                {
                    C.push(a);
                }
                else if (pop_A_success == false)
                {
                    A.push(c);
                }
            }
            else if (x == 3)
            {
                pop_A_success = A.pop(a);//A栈顶元素弹出并保存到a中.
                pop_B_success = B.pop(b);//B栈顶元素弹出并保存到b中.
                if(pop_A_success && pop_B_success)
                {
                    if (a < b)
                    {
                        B.push(b);
                        B.push(a);
                    }
                    else if (b < a)
                    {
                        A.push(a);
                        A.push(b);
                    }
                }
                else if (pop_B_success == false)
                {
                    B.push(a);
                }
                else if (pop_A_success == false)
                {
                    A.push(b);
                }
            }
        }
    }
}

