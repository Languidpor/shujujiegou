#include "Stack.h"

Stack::Stack( ):top(NULL), np(NULL), m_size(0)
{
    //ctor
}

Stack::~Stack()
{
    //dtor
}

Stack::Stack(const Stack& other)
{
    //copy ctor
}

Stack& Stack::operator=(const Stack& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

bool Stack::push(int data)
{
    //Node * np;//np在Stack类中
    /* 这里不考虑 new 失败时的异常处理.
     * 当 new 失败时, 返回 false;
     * 或者当 data 不符合要求时返回 false;
     */
    np = new Node;
    np->data = data;
    np->next = NULL;
    if (top == NULL)
    {
        top = np;
    }
    else
    {
        np->next = top;
        top = np;
    }
    m_size++;
    return true;
}

/** 将栈顶数据弹出栈
 *  弹出前将栈顶元素传递给参数 rs.
 */
bool Stack::pop(int & rs)
{
    if (top == NULL)
    {
        return false;
    }
    else
    {
        rs=top->data;
        Node *p = top;
        top = top->next;
        delete(p);
        m_size--;
        return true;
    }
}

/** 将栈顶数据弹出栈
 *  不保存栈顶数据
 *  空栈时返回false;
 */
bool Stack::pop( )
{
    if (top == NULL)
    {
        return false;
    }
    else
    {
        Node *p = top;
        top = top->next;
        delete(p);
        m_size--;
        return true;
    }
}


/** 返回栈顶数据
 *  若栈为空, 则返回 false;
 */
bool Stack::peek(int & rs)
{
    if (top != NULL)
    {
        rs=top->data;
        return true;
    }else
    {
        return false;
    }
}

/** 打印栈中的元素
 *  从top处打印数据,
 */
void Stack::display(const char * name)
{
    std::cout<<std::endl;
    Node *p;
    p = top;
    std::cout<<"Tower "<< name << "-> "<<"  ";
    while (p != NULL)
    {
        std::cout<<p->data<<"->";
        p = p->next;
    }
    std::cout<<std::endl;
}

bool Stack::empty()
{
    //return top==NULL;
    return m_size==0;
}

int Stack::size()
{
    return m_size;
}
