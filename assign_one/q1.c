#include <stdio.h>

int main(){
	int a,b,c,big;
	printf("Read 3 numbers\n");
	scanf("%d %d %d",&a,&b,&c);
	big = a;
	if(a<b){
		big = b;
		if(b<c){
				big = c;
			}
	}
	else if(a<c){
		big = c;
	}
	printf("The largest number is %d\n",big);
	return 0;
}

