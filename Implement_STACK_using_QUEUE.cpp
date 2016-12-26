#include <bits/stdc++.h>
using namespace std;

struct Qnode
{
	int data;
	struct Qnode *next;	
};

int size = 0;
bool flag = true;

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
		return 1;
	else
		return 0;
}

void enqueue(struct Queue *queue, int data)
{
	struct Qnode* temp = createQnode(data);
	if(queue->rear == NULL && queue->front == NULL)
	{
		queue->front = queue->rear = temp;
		if(flag)
			printf("Inserted:  %d\n", data);
		size++;
	}
	else
	{
		(queue->rear)->next = temp;
		queue->rear = temp;
		if(flag)
			printf("Inserted:  %d\n", data);
		size++;
	}
}

void dequeue(struct Queue *queue1, struct Queue *queue2)
{
	if(isEmpty(queue1))
	{
		printf("Queue is Empty...\n");
	}
	else
	{
       	int sizel = size;
       	int size2 = 0;
    	while((queue1->front)->next != NULL)
    	{
    		struct Qnode* del = queue1->front;
			struct Qnode* temp = (queue1->front)->next;
			int elemDeleted = (queue1->front)->data;
			queue1->front = temp;
    		flag = false;
    		enqueue(queue2, elemDeleted);
    		size2++;
		}
		
		flag = true;
		struct Qnode* del1 = queue1->front;
		int elemDeleted1 = (queue1->front)->data;
		printf("Permanently Dequeued:  %d\n", (queue1->front)->data);
		free(del1);
		queue1->front = NULL;
   		size--;
    	if (queue1->front == NULL) 
       		queue1->rear = NULL;
       		
    	while((queue2->front) != NULL)
    	{
    		struct Qnode* del2 = queue2->front;
			struct Qnode* temp2 = (queue2->front)->next;
			int elemDeleted2 = (queue2->front)->data;
			free(del2);
			queue2->front = temp2;
    		size2--;
    		enqueue(queue1, elemDeleted2);
    		
    		if (queue2->front == NULL) 
       			queue2->rear = NULL;
		}
	}
}

int main()
{
	struct Queue *q = createQueue();
	struct Queue *q2 = createQueue();
    dequeue(q, q2);

    enqueue(q, 10);
    enqueue(q, 40);
    dequeue(q, q2);
    dequeue(q, q2);
    dequeue(q, q2);
	return 0;
}
