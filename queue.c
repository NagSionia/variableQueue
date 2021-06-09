#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int *pt;
    size_t capacity;
    long head;
    long tail;
} Queue;


Queue *new_que(){
    Queue* q = calloc(1, sizeof(Queue));
    if(q == NULL){ fprintf(stderr, "Memory Allocation Failed\n"); exit(1); }
    q->pt = calloc(9, sizeof(int));
    q->capacity = 9;
    q->head = 0;
    q->tail = -1;
    return q;
}

void enq(Queue* q, int elem){
    if ((q->tail + 2) % q->capacity == q->head){
        size_t pre_cap_index = q->capacity;
        q->capacity += 8;
        int *tq = realloc(q->pt, sizeof(int) * q->capacity);
        if (tq == NULL){ fprintf(stderr, "Memory Reallocation Failed\n"); exit(1); }
        q->pt = tq;
        if(q->tail < q->head){
            for(int i=0; i < q->tail+1;i++){
                q->pt[pre_cap_index+i] = q->pt[i];
            }
        }
        q->tail=pre_cap_index+q->tail;
    }
    q->tail = (q->tail + 1) % q->capacity;
    q->pt[q->tail] = elem;
}

int deq(Queue *q){
    if((q->tail + 1) % q->capacity == q->head){
        fprintf(stderr, "Queue is empty");
        return 0;
    }
    int ret;
    ret = q->pt[q->head];
    q->head = (q->head + 1) % q->capacity;
    
    return ret;
}

int main(void){
    Queue *q = new_que();
    
    enq(q, 1);
    enq(q, 2);
    enq(q, 3);
    enq(q, 4);
    enq(q, 5);
    deq(q);
    deq(q);
    deq(q);
    enq(q, 6);
    enq(q, 7);
    enq(q, 8);
    enq(q, 9);
    enq(q, 10);
    enq(q, 11);
    enq(q, 12);
    enq(q, 13);
    enq(q, 14);
    enq(q, 15);
    enq(q, 16);
    enq(q, 17);
    enq(q, 18);
    enq(q, 19);
    enq(q, 20);
    enq(q, 21);
    enq(q, 22);
    
    return 0;
}
