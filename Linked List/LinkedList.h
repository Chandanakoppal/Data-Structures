#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *next;
};

struct node *start = NULL;
int count = 0;
void insert_at_begin(int);
void insert_at_end(int);
void traverse();
void delete_from_begin();
void delete_from_end();
void search_item(int value);
void count_list();
int findmin(struct node *);
int findmax(struct node *);
void insertNodeAtMiddle(int , int);
//void DelNode(struct node **,int );
//void reverse(struct node **);
void reverseList();
void deleteMiddleNode(int );