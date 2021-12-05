#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
/*define a structure for linked list elements. */
typedef struct ListElmt_
{
    void * data;  //point the data
    struct ListElmt_ *next; //point the next lined list elemets
} ListELmt;

// define a structure for liked list
typedef struct List_
{
    int size;
    int (*match)(const void * key1, const void * key2);
    void (*destroy)(void * data);
    ListELmt * head;
    ListELmt * tail;
} List;

//public interface
void list_init(List * list,void (*destroy)(void * data)); //initial the linked list
void list_destroy(List *list);
int list_ins_next(List *list,ListELmt *element,const void *data); //insert the next element
int list_rem_next(List *list,ListELmt *element,void **data); //remove the next element
#define list_size(list) ((list)->size)
#define list_tali(list) ((list)->tail)
#define list_is_head(list,element) ((element) == (list)->head ? 1:0)
#define list_ist_tail(element) ((element)->next == NULL ? 1:0)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)

#endif
