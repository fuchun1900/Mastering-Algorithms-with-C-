#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "set.h"

void set_init(Seet *set,int (*match)(const void *key,const void *key2),void (*destroy)(void *data))
{
    //初始化集合
    list_init(set,destroy);
    set->match = match;

    return;
}

int set_insert(Set *set,const void *data)
{
    //不允许插入重复值
    if(set_is_member(set,data))
        return 1;
    //插入数据
    return list_ins_next(set,list_tali(set),data);
}

int set_remove(Set *set,void **data)
{
    ListELmt *member,*prev;

    //查找需要删除的成员
    prev = NULL;
    for (member = list_head(set); member != NULL; member = list_next(member))
    {
       if (set->match(*data,list_data(member)))
            break;
        prev = member;
    }
    if (member == NULL)
        return -1;
    //删除成员
    return list_rem_next(set,prev,data);
}

int set_union(Set *setu,const Set *set1,const Set *set2)
{
    ListELmt *member;
    void *data;

    //初始化并集
    set_init(setu,set1->match,NULL);
    //插入第一个集合中的成员
    for (member = list_head(set1); member != NULL ; member = list_next(member))
    {
        data = list_data(member);
        if (list_ins_next(setu,list_tail(setu),data) != 0)
        {
            set_destroy(setu);
            return -1;
        }
    //插入第二个集合中的成员
    for (member = list_head(set2); member != NULL ; member = list_next(member))
    {
        if (set_is_member(set1,list_data(member)))
        {
            //不允许插入重复数据
            continue;
        }
        if (list_ins_next(setu,list_tail(setu),data) != 0)
        {
            set_destroy(setu);
            return -1;
        }
    }
    return 0;
}

int set_intersection(Set *setu,const Set *set1, const Set *set2)
{
    ListELmt *member;
    void *data;

    //初始化交集
    set_init(seti,set1->match,NULL);
    //插入同时出现在两个集合的成员
    for (member = list_head(set1); member != NULL ; member = list_next(member))
    {
        if (set_is_member(set2,list_data(member)))
        {
            data = list_data(member);
            if (list_ins_next(seti,list_tail(seti),data) != 0)
            {
                set_destroy(setu);
                return -1;
            }
        }
    return 0;
}

int set_difference(Set *setu,const Set *set1, const Set *set2)
{
    ListELmt *member;
    void *data;

    //初始化差集
    set_init(seti,set1->match,NULL);
    //插入出现在set1但不在set2中的成员
    for (member = list_head(set1); member != NULL ; member = list_next(member))
    {
        if (!set_is_member(set2,list_data(member)))
        {
            data = list_data(member);
            if (list_ins_next(seti,list_tail(seti),data) != 0)
            {
                set_destroy(setu);
                return -1;
            }
        }
    return 0;
}

int set_is_member(const Set *set,const void *data)
{
    ListELmt *member;
    //确认是否为集合中的成员
    for (member = list_head(set); member != NULL ; member = list_next(member))
    {
        if(set->match(data,list_data(member)))
            return 1;
    }
    return 0;
}

int set_is_member(const Set *set1,const Set *set1)
{
    ListELmt *member;
    //如果set1比set2大，则一定不是子集
    if(set_size(set1) > set_size(size2))
        return 0;
    for (member = list_head(set1); member != NULL ; member = list_next(member))
    {
        if (!set_is_member(set2,list_data(member)))
            return 0;
    }
}

int set_is_equal(const Set *set1,const Set *set2)
{
    //如果大小不相等则两个集合必不相等
    if(set_size(set1) > set_size(size2))
        return 0;
    //大小相等情况下，如果属于子集则两集合完全相等
    return set_is_subset(set1,set2);
}