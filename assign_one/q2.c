#include <stdio.h>
#include <stdlib.h>
int main(){
    int n = 15,big;
    printf("number of elements: %d\n",n);
  
    int *arr = (int*)malloc(n*sizeof(int));
    printf("Enter the numbers\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    big = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i] > big){
            big = arr[i];
        }
    }
    printf("The largest number is %d\n",big);
    return 0;
}
