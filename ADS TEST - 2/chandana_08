#ifndef _INCLUDED_SLIST_
#define _INCLUDED_SLIST_

#include <stdint.h>
//#define HEAP_MAX_SIZE 32

//typedef struct _heap_ Heap;
typedef struct _node_ Node;
typedef struct _slist_ Slist;

struct  _node_
{
	uint32_t time_stamp;
	uint32_t aircraft_num;
	uint32_t takeoff;
	uint32_t landing;
	Node *next;
};

struct  _slist_
{
	Node *head;
	Node *tail;
	uint32_t length;
};

#endif
