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
    //Node * np;//np��Stack����
    /* ���ﲻ���� new ʧ��ʱ���쳣����.
     * �� new ʧ��ʱ, ���� false;
     * ���ߵ� data ������Ҫ��ʱ���� false;
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

/** ��ջ�����ݵ���ջ
 *  ����ǰ��ջ��Ԫ�ش��ݸ����� rs.
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

/** ��ջ�����ݵ���ջ
 *  ������ջ������
 *  ��ջʱ����false;
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


/** ����ջ������
 *  ��ջΪ��, �򷵻� false;
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

/** ��ӡջ�е�Ԫ��
 *  ��top����ӡ����,
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
