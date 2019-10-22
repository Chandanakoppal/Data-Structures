#include<stdlib.h>
#include<stddef.h>
#include<stdio.h>
#include<assert.h>
#include "heap.h"

Slist slist_new()
{
    Slist s={NULL,NULL,0};    
    return s;
}

static Node* slist_new_node(uint32_t time,uint32_t num,uint32_t ttime,uint32_t ltime)
{
    Node *new_node=(Node *)malloc(sizeof(Node));
    new_node -> time_stamp = time;
    new_node -> aircraft_num = num;
    new_node -> takeoff = ttime;
    new_node -> landing = ltime;
    new_node -> next=NULL;
    return new_node;
}

Slist* slist_add_head(Slist *list, uint32_t time,uint32_t num,uint32_t ttime,uint32_t ltime)
{
    assert(list!= NULL);
    Node *new_node = slist_new_node(time,num,ttime,ltime);
    new_node -> next = list -> head;
    list -> head=new_node;
    if(list->tail == NULL)
    {
        list->tail=new_node;
    }
    ++list->length;
    assert((list->length==1 && list->head==list->tail) || (list->length>0 && list->head!=list->tail));
    return list;
}


uint32_t slist_length(Slist *list)
{
        assert(list!=NULL);
        return list -> length;
}

void traverse(Slist *list) {
assert(list!=NULL);
   Node *t;  
   t=list->head;
   while (t->next != NULL) {
      printf("%d\t", t->time_stamp);
      printf("%d\t", t->aircraft_num);
      printf("%d\t", t->takeoff);
      printf("%d\n\n", t->landing);
      t = t->next;
   }

      printf("%d\t", t->time_stamp);
      printf("%d\t", t->aircraft_num);
      printf("%d\t", t->takeoff);
      printf("%d\n", t->landing);
}

void 

int main()
{
    Slist s = slist_new();
    Slist *list = &s;

    list = slist_add_head(list, 1000, 123,1,9);
    list = slist_add_head(list, 2030, 234,12,8);
    list = slist_add_head(list, 1230, 321,10,7);
    list = slist_add_head(list, 1130, 678,12,8);
    
    traverse(list);
}

