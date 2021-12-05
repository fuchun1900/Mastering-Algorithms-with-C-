#include <stdlib.h>
#include <string.h>

#include "list.h"

//list initiate
void list_init(List *list, void (*destroy)(void * data))
{
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;

    return;
}

//list destroy
void list_destroy(List *list)
{
    void * data;
    // remove each element
    while (list_size(list) > 0)
    {
        if(list_rem_next(list,NULL,(void **)&data) == 0 && list->destroy !=NULL)
            list->destroy(data); //call a user_defined function to free dynamically allocated data.
    }
    memset(list,0,sizeof(list)); //set the new  memory to 0
}

int list_ins_next(List *list,ListELmt * element,const void * data)
{
    ListELmt * new_element;
    //allocate storage for element
    if((new_element = (ListELmt *)malloc(sizeof(ListELmt))) == NULL)
        return -1;
    //insert the element into list
    new_element->data = (void *)data;
    if(element == NULL)
    {
        //Handle insertion at the head of the list
        if(list_size(list) == 0)
            list->tail = new_element;
        new_element->next = list->head;
        list->head = new_element;
    }
    else
    {
        //handle insertion somewhere other than at the head
        if(element->next == NULL)
            list->tail = new_element;
        new_element->next = element->next;
        element->next = new_element;
    }
    list->size++;

    return 0;
}

int list_rem_next(List *list,ListELmt *element,void ** data)
{
    ListELmt * old_element;
    // Do not allow removal from an empty list.
    if(list_size(list) == 0)
        return -1;
    
    //Remove the element from the list
    if (element == NULL)
    {
        // Handle removal form the head of the list
        *data = list->head->data;
        old_element = list->head;
        list->head = list->head->next;

        if(list_size(list) ==1)
            list->tail = NULL;
    }
    else
    {
        //Handle removal from somewhere other than the head
        if(element->next == NULL)
            return -1;
        *data = element->next->data;
        old_element = element->next;
        element->next = element->next->next;
        if (element->next == NULL)
            list->tail = element;
    //Free the storage allocated by the abstract datatype
    free(old_element);
    list->size--;

    return 0;
    }
}
