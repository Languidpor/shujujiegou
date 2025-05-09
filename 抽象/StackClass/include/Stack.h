#ifndef STACK_H
#define STACK_H
/**
*  ���ڵ�����ʵ��ջ
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

        /** ������ data ѹ��ջ��
         *
         */
        bool push(int data);

        /** ��ջ�����ݵ���ջ
         *  ����ǰ��ջ��Ԫ�ش��ݸ����� rs.
         */
        bool pop(int & rs);

        /** ��ջ�����ݵ���ջ
         *  ������ջ������
         */
        bool pop();

        /** ��ȡջ������
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
        int m_size; //ջ�����ݸ���
};

#endif // STACK_H
