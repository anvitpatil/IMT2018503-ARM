#include <stdio.h>
#include <stdlib.h>

void swap(int* x,int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


int main(){
    int n = 20,big;
    printf("number of elements: %d\n",n);
    int *arr = (int*)malloc(n*sizeof(int));
    printf("Enter the numbers\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }

    printf("Sorted array : ");
    for(int i=0;i<n;i++){
        printf("%d \t",arr[i]);
    }


}
