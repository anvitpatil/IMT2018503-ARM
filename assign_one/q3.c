#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,count;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    printf("Enter the numbers\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    count = 0;
    for(int i=0;i<n;i++){
        if(arr[i]%2 == 0){
            count++;
        }
    }
    printf("total number of even numbers: %d\n",count);

}