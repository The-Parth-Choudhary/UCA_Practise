typedef struct {
    int value[1000];
    int top;

} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *queue = malloc(sizeof(MyQueue));
    queue->top = -1;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->top = obj->top+1;
    obj->value[obj->top] = x;
}

int myQueuePop(MyQueue* obj) {
    int x = obj->value[0];
    
    for(int i = 0; i < obj->top; i++){
        obj->value[i] = obj->value[i+1];
    }

    obj->top = obj->top-1;
    return x;
}

int myQueuePeek(MyQueue* obj) {
    return obj->value[0];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
    return;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/