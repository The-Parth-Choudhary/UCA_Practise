typedef struct 
{
    int *arr;
    int top;
    int currSize;  
    int size;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k)   
{
    MyCircularQueue* queue = malloc(sizeof(MyCircularQueue));
    queue->top = -1;
    queue->arr = malloc(k * sizeof(int));
    queue->currSize = 0;
    queue->size = k;
    return queue;
}

bool myCircularQueueEnQueue(MyCircularQueue* queue, int value) 
{
    if((queue->currSize) == (queue->size))
    {
        return false;
    }
    queue->top += 1;
    queue->arr[queue->top] = value;
    queue->currSize++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* queue) 
{
    if(queue->currSize == 0) return false;
    for(int i = 0; i < (queue->currSize - 1); i++)
    {
        queue->arr[i] = queue->arr[i + 1];
    }
    queue->top -= 1;
    queue->currSize -= 1;
    return true;
}

int myCircularQueueFront(MyCircularQueue* queue) 
{
    if(queue->currSize != 0)
    {
        return queue->arr[0];
    }
    return -1;
}

int myCircularQueueRear(MyCircularQueue* queue) 
{
    if(queue->currSize > 0)
    {
        return queue->arr[queue->currSize - 1];
    }
    return -1;
}

bool myCircularQueueIsEmpty(MyCircularQueue* queue) 
{
    if(queue->currSize == 0) return true;
    return false;
}

bool myCircularQueueIsFull(MyCircularQueue* queue) 
{
    if(queue->currSize == queue->size) return true;
    return false;
}

void myCircularQueueFree(MyCircularQueue* queue) 
{
    free(queue);
    return;
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