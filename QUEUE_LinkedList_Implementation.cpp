#include <bits/stdc++.h>
using namespace std;

struct Qnode
{
	int data;
	struct Qnode *next;	
};

struct Queue
{
	struct Qnode *front;
	struct Qnode *rear;
};

struct Qnode* createQnode(int data)
{
	struct Qnode* qnode = (struct Qnode*)malloc(sizeof(struct Qnode));
	qnode->data = data;
	qnode->next = NULL;
	return qnode;
}

struct Queue *createQueue()
{
	struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->front = queue->rear = NULL;
	return queue;
}

int isEmpty(struct Queue *queue)
{
	if(queue->rear == NULL && queue->front == NULL)
	{
	//	printf("Queue is empty\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

void enqueue(struct Queue *queue, int data)
{
	struct Qnode* temp = createQnode(data);
	if(isEmpty(queue))
	{
		queue->front = queue->rear = temp;
		printf("Inserted:  %d\n", data);
	}
	else
	{
		(queue->rear)->next = temp;
		queue->rear = temp;
		printf("Inserted:  %d\n", data);
	}
}

void dequeue(struct Queue *queue)
{
	if(isEmpty(queue))
	{
		printf("Queue is Empty...\n");
	}
	else
	{
		struct Qnode* del = queue->front;
		struct Qnode* temp = (queue->front)->next;
		printf("Dequeued:  %d\n", (queue->front)->data);
		free(del);
		queue->front = temp;
		
		if (queue->front == NULL)  // Don't forget this....
       		queue->rear = NULL;
	}
}

int main()
{
	struct Queue *q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    dequeue(q);
  	dequeue(q);
  	dequeue(q);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    dequeue(q);
  	dequeue(q);
  	dequeue(q);
 	dequeue(q); 
	return 0;
}
