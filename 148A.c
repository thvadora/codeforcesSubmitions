#include <stdio.h>

int main(int argc, char const *argv[]){
	
	int i,j,k,l,m,n,d;
	int count=0;

	scanf("%d",&k);
	scanf("%d",&l);
	scanf("%d",&m);
	scanf("%d",&n);
	scanf("%d",&d);

	int array[d];
	int new_array[100001];

	for (int i = 0; i < 100001; ++i)
	{
		new_array[i] = 0;
	}

	for (i = 1; i <= d; ++i)
	{
		array[i-1] = i;
	}
	j = 0;
	for (i = 0; i < d; ++i)
	{
		if (array[i]%k==0 || array[i]%l==0 ||array[i]%m==0 ||array[i]%n==0 )
		{
			new_array[j] = array[i];
			j++;
		}
	}

	for (i = 0; i < d; ++i)
	{
		if(new_array[i] != 0){
			count++;
		}
	}

	printf("%d", count );



	return 0;
}