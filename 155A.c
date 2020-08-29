#include <stdio.h>
#include <stdbool.h>

bool is_grater(int a[],int index){

	bool r;
	r = true;

	for (int i = 0; i < index && r; ++i)
	{
		r = r && a[index] > a[i];
	}

return r;
}

bool is_lower(int a[],int index){

	bool r;
	r = true;

	for (int i = 0; i < index && r; ++i)
	{
		r = r && a[index] < a[i];
	}

return r;
}

int amazings(int a[], int tam){

	int count;
	count = 0;
	int i;

	for (i = 1; i < tam; ++i)
	{
		if(is_grater(a,i) || is_lower(a,i)){
			count++;
		}
	}

	return count;
 
}

int main(int argc, char const *argv[])
{
	int i,n;

	scanf("%d", &n);

	int array[n];

	for(i = 0; i < n; i++){
		scanf("%d",&array[i]);
	}

	printf("%d",amazings(array,n));

	return 0;
}