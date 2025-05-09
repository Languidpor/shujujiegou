#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"hash_table.h"

//�궨��
#define my_malloc malloc
#define my_free free

//hash�ṹ��1
struct hash_node
{
	char* key;
	void* value; //void*��ʾvalue
	struct hash_node* next; //����ͬһ�����ϵĽڵ�
};

//hash�ṹ��2
struct hash_table
{
	struct hash_node** hash_set; //ÿ�����ϵ������ͷָ��
	int n; //hash_table�����ж��ٸ�����
};

//��������
struct hash_table* create_hash_table(int n)
{
	struct hash_table* t = my_malloc(sizeof(struct hash_table)); //����ṹ�ڴ�
	memset(t, 0, sizeof(struct hash_table)); //��ʼ�ڴ�

	//n�����ϵ��ڴ棬��ŵ�������ͷ��ָ��
	t->hash_set = my_malloc(n * sizeof(struct hash_node*)); //����ṹ�弯���ڴ�
	memset(t->hash_set, 0, sizeof(struct hash_node*) * n);
	t->n = n; //��¼���ϸ���
	return t;
}

//����hash�㷨
static unsigned int hash_index(char* str)
{
	register unsigned int h;
	register unsigned char* p;

	for (h = 0, p = (unsigned char*)str; *p; p++)
		h = 31 * h + *p;
	return h;
}

void hash_insert(struct hash_table* t, char* key, void* value)
{
	struct hash_node* node = my_malloc(sizeof(struct hash_node));
	memset(node, 0, sizeof(struct hash_node));
	node->key = _strdup(key);
	node->value = value;

	//ʹ��hash������key�������ĸ�����
	int index = (hash_index(key) % t->n); //ģ���㣬����ȡ��[0,0-1]
	struct hash_node* header = t->hash_set[index];

	node->next = header;
	t->hash_set[index] = node;
}