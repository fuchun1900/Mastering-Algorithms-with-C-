#ifndef SET_H
#define SET_H

#include <stdlib.h>
#include "list.h"

/* 以链表来实现集合 */

typedef List Set;

void set_init(Set * set,int (*match)(const void *key1,const void*key2),void (*destroy)(void * data));
//初始化集合，mathc是函数指针，用来各种集合操作中判断两个成员是否相等，destroy参数用来释放动态分配的内存空间

void set_destroy(Set *set)
//销毁set所指向的集合，将集合中所有成员移除

int set_insert(Set *set,const void *data);
//项set指定的集合中插入一个成员，成员包含一个指向data的指针。

int set_remove(Set *set,void **data);
//移除set指定集合中与data相吻合饿成员，函数返回后data指向移除成员的数据部分

int set_union(Set *setu,const Set *set1, const Set *set2);
//建立一个集合，其结果为set1和set2所指定集合的并集

int set_intersection(Set *seti,const Set *set1, const Set *set2);
//建立一个集合，其结果为set1和set2所指定集合的交集

int set_difference(Set *setd,const Set *set1, const Set *set2);
//建立一个集合，其结果为set1和set2所指定集合的差集

int set_is_member(const Set *set,const void *data);
//判断由data所指定的成员是否在set所指定的集合中

int set_is_subset(const Set *set,const void *data);
//判断参数set1是否为set2的子集

int set_is_equal(const Set *set1,const Set *set2);
//判断set1和set2是否相等

#define set_size(Set) ((Set) ->size)
//返回集合中的元素个数
#define set_destroy list_destroy

#endif