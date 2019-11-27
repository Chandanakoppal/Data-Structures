//heapmain

#include<stdio.h>
#include<stdint.h>
#include "heapsort.h"
int main()
{
	int32_t a[10]={30,10,20,90,15,40};
	Heap h = heap_new(a,6);
	Heap *heap = &h;
	Heap *hp = heap_sort(heap);
	for(int i=0;i<6;i++)
	{
		printf("%d\t",heap->data[i]);
	}
	return 0;
}
