#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){

	int n;
	scanf("%d", &n);

	if (n % 2 == 0 && n != abs(2) && n != 0){
		printf("YES");
	} else {
		printf("NO");
	}

	return 0;
}