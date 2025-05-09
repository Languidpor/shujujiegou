// LinkTable.cpp : �������̨Ӧ�ó������ڵ㡣

#include <iostream>
#include <string>
using namespace std;

//����Ľṹ��
struct node
{
	char val;
	node* next;
};

//��������
struct node* create(string& str_link)
{
	int len = str_link.length();

	struct node* phead = new node();     //���б�ͷ��������ͷ�в��洢�κ�Ԫ��
	struct node* preNode = phead;
	for (int i = 0; i < len; i++)
	{
		struct node* pNode = new node();
		pNode->val = str_link[i];
		pNode->next = NULL;
		preNode->next = pNode;
		preNode = pNode;
	}
	return phead;
}

//�������
void out_link(struct node* phead)
{
	if (phead == NULL)
		return;
	struct node* pNode = phead->next;
	while (pNode)
	{
		cout << pNode->val;
		pNode = pNode->next;
	}
	cout << endl;
}

//�ҵ���index��Ԫ��
struct node* find_node(struct node* phead, int index)
{
	if (!phead) return NULL;
	struct node* pNode = phead;
	while (index--)
	{
		pNode = pNode->next;
		if (!pNode)
			return NULL;
	}
	return pNode;
}

//��ǰ���ڵ�
struct node* find_preNode(struct node* phead, struct node* pNode)
{
	if (!pNode) return NULL;
	struct node* preNode = phead;
	while (preNode)
	{
		if (preNode->next == pNode)
			return preNode;
		preNode = preNode->next;
	}
	return NULL;
}

//�����ڵ�
void exchange_node(struct node* phead, struct node* pNode1, struct node* pNode2)
{
	if (!phead) return;
	//�ֱ��ҵ�pNode1��ǰ��pPre1,��pNode2��ǰ��pPre2
	struct node* pPre1 = find_preNode(phead, pNode1);
	struct node* pPre2 = find_preNode(phead, pNode2);
	if (!pPre1 || !pPre2) return;  //���κ�һ��û���ҵ�

	//���ڵ����
	struct node* pBefore, * pAfter, * pPre;
	if (pPre2 == pNode1)
	{
		pBefore = pNode1;
		pAfter = pNode2;
		pPre = pPre1;
	}
	if (pPre1 == pNode2)
	{
		pBefore = pNode2;
		pAfter = pNode1;
		pPre = pPre2;
	}
	if (pPre2 == pNode1 || pPre1 == pNode2)
	{
		pPre->next = pAfter;
		pBefore->next = pAfter->next;
		pAfter->next = pBefore;
	}
	else
	{
		//�����ڵ����
		struct node* pNext1 = pNode1->next;
		pNode1->next = pNode2->next;
		pPre1->next = pNode2;
		pPre2->next = pNode1;
		pNode2->next = pNext1;
	}

}

void test()
{
	string str;
	cin >> str;
	struct node* phead = create(str);

	int index;
	cin >> index;
	struct node* pNode1 = find_node(phead, index);
	cin >> index;
	struct node* pNode2 = find_node(phead, index);
	exchange_node(phead, pNode1, pNode2);
	cout << "after exchange: " << endl;
	out_link(phead);

}

int _tmain(int argc, _TCHAR* argv[])
{
	test();
	return 0;
}