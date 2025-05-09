#ifndef STACK_H
#define STACK_H
/**
*  基于单链表实现栈
*/

#include <stdio.h>
#include <iostream>

class Stack
{
    public:

        /** Default constructor */
        Stack();

        /** Default destructor */
        virtual ~Stack();

        /** Copy constructor
         *  \param other Object to copy from
         */
        Stack(const Stack& other);

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Stack& operator=(const Stack& other);

        /** 将数据 data 压入栈中
         *
         */
        bool push(int data);

        /** 将栈顶数据弹出栈
         *  弹出前将栈顶元素传递给参数 rs.
         */
        bool pop(int & rs);

        /** 将栈顶数据弹出栈
         *  不保存栈顶数据
         */
        bool pop();

        /** 读取栈顶数据
         *
         */
        bool peek(int & rs);

        void display(const char * name);

        bool empty();

        int size();

    protected:
        struct Node
        {
            int data;
            Node *next;
        };

    private:
        Node *top;
        Node *np; //np means new pointer
        int m_size; //栈中数据个数
};

#endif // STACK_H
