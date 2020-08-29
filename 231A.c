#include <stdio.h>

int main(int argc, char const *argv[]){
	
	int n,i;
	scanf("%d", &n);
	int count = 0;
	int a = 0;
	int b = 0;
	int c = 0;

	for(i = 0; i < n; ++i){
		scanf("%d %d %d", &a,&b,&c);
		if (a+b+c >= 2){
				count++;
			}	
	}

	printf("%d",count);

	return 0;
}