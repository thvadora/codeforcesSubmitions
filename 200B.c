#include <stdio.h>
int main(int argc, char const *argv[])
{
	int i,n;
	float count = 0;

	scanf("%d", &n);

	int array[n];

	for (i = 0; i <n; ++i){
		scanf("%d", &array[i]);
	}

	for (i = 0; i < n; ++i)
	{
		count = count + array[i];
	}

	count = count / n;

	printf("%f",count );



	return 0;
}