// LinkTable.cpp : 定义控制台应用程序的入口点。

#include <iostream>
#include <string>
using namespace std;

//链表的结构体
struct node
{
	char val;
	node* next;
};

//建立链表
struct node* create(string& str_link)
{
	int len = str_link.length();

	struct node* phead = new node();     //带有表头的链表，表头中不存储任何元素
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

//输出链表
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

//找到第index个元素
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

//找前驱节点
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

//交换节点
void exchange_node(struct node* phead, struct node* pNode1, struct node* pNode2)
{
	if (!phead) return;
	//分别找到pNode1的前驱pPre1,和pNode2的前驱pPre2
	struct node* pPre1 = find_preNode(phead, pNode1);
	struct node* pPre2 = find_preNode(phead, pNode2);
	if (!pPre1 || !pPre2) return;  //有任何一个没有找到

	//相邻的情况
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
		//不相邻的情况
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