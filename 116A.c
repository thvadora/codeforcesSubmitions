#include <stdio.h>

int find_max(int a[], int tam){

	int max;
	max = 0;
	int i;
	i = 0;
	int count;
	count = 0;

	while(i < tam){
		count = count - a[i] + a[i+1];
		if (count > max){
			max = count;
		}
		i= i+2;
	}

	return max;
}

int main(int argc, char const *argv[]){
	int stops;
	int i;

	scanf("%d", &stops);

	int array[2*stops];

	for (i = 0; i < 2*stops; ++i){
		scanf("%d", &array[i]);
	}

	printf("%d", find_max(array,2*stops));

	return 0;
}