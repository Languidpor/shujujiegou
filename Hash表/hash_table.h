#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

//创建hash结构
struct hash_table;

//创建hash对象   n:多少个集合
struct hash_table* create_hash_table(int n);

//插入一个key:value，不判断是否重复
void hash_insert(struct hash_table* t, char* key, void* value);

//删除hash表
void hash_delete(struct hash_table* t, char* key);

//清理所有的hash表的数据
void hash_clear(struct hash_table* t);

//删除hash对象
void destory_hash_table(struct hash_table* t);

//插入/修改key:value
void hash_set(struct hash_table* t, char* key, void* value);

//在hash表里面查找我们想要的值
void* hash_find(struct hash_table* t, char* key);

#endif // !__HASH_TABLE_H__
