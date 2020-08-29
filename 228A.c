#include <stdio.h>

int count_ceros(int a[], int tam){
	int i = 0;
	int count = 0;

	for (i = 0; i < tam; i++)
	{
		if(a[i] == 0){
			count++;
		}
	}
	
	return count;
}

int count_equals(int a[], int tam){

int i = 0;
int  count = 0;
int j = 1;

while(i<tam-1){
	while(j<tam){
		if(a[i] == a[j]){
			a[j] = 0;
		}
	j++;
	}
i++;
j = i+1;
}

count = count_ceros(a,tam);

return count;

}

int main(int argc, char const *argv[])
{
	int i;
	int array[4];

	for (i = 0; i < 4; ++i){
		scanf("%d", &array[i]);
	}
	//for (i = 0; i < 4; ++i){
	//	printf("%d ", array[i]);
	//}

	switch(count_equals(array,4)){
		case 3:
			printf("%d", 3);
			break;
		case 2:
			printf("%d", 2);
			break;
		case 1: 
			printf("%d", 1);
			break;
		case 0:
			printf("%d", 0);
			break;
	}

	return 0;
}