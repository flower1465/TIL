#include <stdio.h>
#include "SimpleMaxHeap.h"


void PrintHeap(Heap* heap, char *szTitle)
{
	printf("================================\n%s\n================================\n ", szTitle);
	for (int i = 1; i <= heap->numOfData; i++) {
		printf(" %d %s", heap->heapArr[i].pr, i == heap->numOfData ? "\n\n" : "->");
	}
}

int main(void)
{
	Heap heap;
	int i, nSizeItemList = 0 ; 
	
	HeapElem ItemList[] = { {50, 'A'},
							{40, 'A'},
							{30, 'A'},
							{25, 'A'},
							{30, 'A'},
							{20, 'A'},
							{10, 'A'},
							{5, 'A'}, 
							{15, 'A'},
							{20, 'A'},
							{45, 'A'},
							{60, 'A'}
	}; 

	HeapInit(&heap);

	nSizeItemList = sizeof(ItemList) / sizeof(HeapElem); 

	for (i = 0; i < nSizeItemList ; i++)
	{
		// printf("Item : %c , Priority : %d\n", ItemList[i].data, ItemList[i].pr); 
		HInsert(&heap, ItemList[i].data, ItemList[i].pr); 
	}

	/*삽입 후 결과 출력*/
	PrintHeap(&heap, "삽입후"); 


	HDelete(&heap); 
	PrintHeap(&heap, "데이타 1개 삭제후");

	return 0;
}
