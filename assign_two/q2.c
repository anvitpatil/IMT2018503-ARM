#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int head;
    int capacity;
    int* arr;
};

struct Stack* empty_descending_stack(int capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->head = stack->capacity-1 ;
    stack->arr = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack)
{
    return stack->head == -1;
}
 
int isEmpty(struct Stack* stack)
{
    return stack->head == stack->capacity-1;
}

void Push(int ele,struct Stack* stack ){
    if(isFull(stack)){
        printf("Cannot Push!! Stack is full\n");
        return;
    }
    stack->arr[stack->head--] = ele;
    printf("%d has been Pushed\n",ele);
}

int* Pop(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Cannot Pop, Stack is empty\n");
        return NULL;
    }
    return &stack->arr[++stack->head];
}
 
void print(struct Stack* stack){
    int n = stack->capacity;
    for(int i = n-1;i>stack->head;i--){
        printf("%d \t",stack->arr[i]);
    }
    printf("\n");
}

int main(){
    int size, ele;
    int* data = NULL;
    printf("Enter the size of stack\n");
    scanf("%d",&size);
    struct  Stack* stack = empty_descending_stack(size);
    printf("Stack is created, choose your options from the menu below\n");
    printf("1: Print stack\n 2: Push element\n 3: Pop element\n 4: Exit\n");
    int choice,exit = 0;
    
    while(exit == 0){
        printf("enter your choice from the menu(ex: 2 for push, 4 for exit) \n");
        scanf("%d",&choice);
        switch(choice){

            case 1:
                    print(stack);
                    break;
            case 2:
                    printf("Enter the element you want to push\n");
                    scanf("%d",&ele);
                    Push(ele,stack);
                    break;
            case 3:
                    data = Pop(stack);
                    if(data != NULL)
                    printf("element popped is %d\n",*data);
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