#include <stdio.h>
#include "CircularQueue.h"

int main(void)
{
	// Queue�� ���� �� �ʱ�ȭ ///////
	Queue q;
	QueueInit(&q);

	// ������ �ֱ� ///////
	Enqueue(&q, 100);  
	Enqueue(&q, 200);
	Enqueue(&q, 300);
	Dequeue(&q);
	Dequeue(&q);
	Dequeue(&q);
	Enqueue(&q, 400);
	Enqueue(&q, 500);
	Enqueue(&q, 600);
	Enqueue(&q, 700);


	// ������ ������ ///////
	while(!QIsEmpty(&q))
		printf("%d ", Dequeue(&q)); 

	return 0;
}