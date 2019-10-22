#include <assert.h>
#include "heap.h"
#include <stdio.h>

int main()
{
	Slist s = slist_new();
	Slist *list = &s;

	list = slist_add_head(list, 1000, 123,1,9);
	list = slist_add_head(list, 2030, 234,12,8);
	list = slist_add_head(list, 1230, 321,10,7);
	list = slist_add_head(list, 1130, 678,12,8);
	
	traverse(list);
	bubbleSort(arr, n); 
    printf("Sorted \n"); 
    printArray(arr, n); 
    return 0; 
}

