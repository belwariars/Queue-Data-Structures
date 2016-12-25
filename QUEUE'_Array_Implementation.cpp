#include <bits/stdc++.h>
using namespace std;

struct Queue
{
	unsigned capacity;
	int size, front, rear;
	int *arr;	
};

struct Queue *createqueue(unsigned capacity)
{
	struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1; // Remember This!!!
	queue->arr = (int*)malloc(capacity *sizeof(int));
}

int isEmpty(struct Queue *queue)
{
	if(queue->size == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isFull(struct Queue *queue)
{
	if(queue->size == queue->capacity-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int front(struct Queue *queue)
{
	return (queue->arr[queue->front]);
}

int rear(struct Queue *queue)
{
	return (queue->arr[queue->rear]);
}

int enqueue(struct Queue *queue, int item)
{
	if (isFull(queue))
        return -1;
	queue->arr[(++queue->rear)%(queue->capacity)] = item;
	queue->size++;
	printf("Element Inserted:  %d\n", item);
	return item;
}

int dequeue(struct Queue *queue)
{
	if (isEmpty(queue))
        return INT_MIN;
	int elem = queue->arr[queue->front++];
	queue->size--;
	printf("Element dequeued:  %d\n", elem);
	return elem;
}

int main()
{
	struct Queue* queue = createqueue(10);
 
	enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40); 
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
 //   dequeue(queue);
	return 0;
}
