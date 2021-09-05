#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front, rear;
    int capacity;
    int* arr;
};

struct Queue* make_queue(int capacity){
    struct Queue* queue = (struct  Queue*)malloc(sizeof(struct Queue));
    queue->front=-1;
    queue->rear=-1;
    queue->capacity = capacity;
    queue->arr = (int *)malloc(sizeof(int)*capacity);
    return queue; 
} 

int isFull(struct Queue* queue)
{
    return ((queue->front == 0 && queue->rear == queue->capacity-1) || queue->front == queue->rear+1);
}
  
int isEmpty(struct Queue* queue)
{
    return (queue->front == -1);
}

void add_to_queue(struct Queue* queue, int ele)
{
    if (isFull(queue)){
        printf("cannot add as the queue is full\n");
    }
    else{
    if(queue->front == -1){
        queue->front = 0;
    }
    queue->rear = (queue->rear+1)%queue->capacity;
    queue->arr[queue->rear]=ele;
    printf("%d added to queue\n", ele);
    }
}

int remove_from_queue(struct Queue* queue)
{
    int data;
    if (isEmpty(queue)){
        printf("Cannot delete, as the queue is empty\n");
        return -1;
    }
    else{
    data = queue->arr[queue->front];
     if (queue->front == queue->rear) {
      queue->front = -1;
      queue->rear = -1;
    }
    else{
        queue->front = (queue->front + 1)%queue->capacity;
    }
    return data; 
}
}

void print(struct Queue* queue){
    int i;
    if(isEmpty(queue)){
        printf("Queue is empty\n");
    }
    else{
        for( i=queue->front;i!=queue->rear;i=(i+1)%queue->capacity){
            printf("%d \t",queue->arr[i]);
        }
        printf("%d \t",queue->arr[i]);
    }
    printf("\n");
}

int main(){
    int capacity,ele;
    int data;
    printf("Enter the size of Queue\n");
    scanf("%d",&capacity);
    struct Queue* queue = make_queue(capacity);
    printf("Queue is created, choose your options from the menu below\n");
    printf("1: Print queue\n 2: add element to queue\n 3: remove element\n 4: Exit\n");
    int choice,exit = 0;
    
    while(exit == 0){
        printf("enter your choice from the menu(ex: 2 for adding, 4 for exit) \n");
        scanf("%d",&choice);
        switch(choice){

            case 1:
                    print(queue);
                    break;
            case 2:
                    printf("Enter the element you want to add\n");
                    scanf("%d",&ele);
                    add_to_queue(queue,ele);
                    break;
            case 3:
                    data = remove_from_queue(queue);
                        printf("element removed is %d\n",data);
                    break;
            case 4:
                    printf("Exiting the program\n");
                    exit = 1;
                    break;
            default:
                    printf("Please enter a valid choice\n");
        }
    }
    return 0;
}
