#include <stdio.h>
#include "SimpleHeap.h"

int main(void)
{
	Heap heap;
	HeapInit(&heap);

	HInsert(&heap, 'A', 1);
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);
	//printf("%c \n", HDelete(&heap));

	HInsert(&heap, 'A', 1);
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);
	//printf("%c \n", HDelete(&heap));
	/*
	*/
	HInsert(&heap, 'T', 1);
	HInsert(&heap, 'S', 1);
	HInsert(&heap, 'U', 1);
	
	while(!HIsEmpty(&heap))
		printf("%c \n", HDelete(&heap));

	return 0;
}
