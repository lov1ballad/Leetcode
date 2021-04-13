#define _CRT_SECURE_NO_WARNINGS 1
typedef struct
{
	int *base;
	int capacity;
	int front;
	int rear;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue *pcq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	pcq->capacity = k;
	pcq->base = (int*)malloc(sizeof(int)*(pcq->capacity + 1));
	pcq->front = pcq->rear = 0;
	return pcq;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	return (obj->rear + 1) % (obj->capacity + 1) == obj->front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsFull(obj))
		return false;
	obj->base[obj->rear] = value;
	obj->rear = (obj->rear + 1) % (obj->capacity + 1);
	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return false;

	obj->front = (obj->front + 1) % (obj->capacity + 1);
	return true;
}

int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->base[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->base[(obj->rear - 1 + obj->capacity + 1) % (obj->capacity + 1)];
}


void myCircularQueueFree(MyCircularQueue* obj)
{
	free(obj->base);
	obj = NULL;
	free(obj);
}

/**
* Your MyCircularQueue struct will be instantiated and called as such:
* MyCircularQueue* obj = myCircularQueueCreate(k);
* bool param_1 = myCircularQueueEnQueue(obj, value);

* bool param_2 = myCircularQueueDeQueue(obj);

* int param_3 = myCircularQueueFront(obj);

* int param_4 = myCircularQueueRear(obj);

* bool param_5 = myCircularQueueIsEmpty(obj);

* bool param_6 = myCircularQueueIsFull(obj);

* myCircularQueueFree(obj);
*/