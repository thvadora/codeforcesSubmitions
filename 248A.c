#include <stdio.h>

int has_more(int a[],int tam){

	int count0,count1;
	count1 = 0;
	count0 = 0;

	for (int i = 0; i < tam; ++i)
	{
		if (a[i] == 1)
		{
			count1++;
		}else{
			count0++;
		}
	}

if (count1 > count0){
	return 1;
} else {
	return 0;
}

}

int dif(int a[], int tam, int x){

	int count,i;
	count = 0;

	for (i = 0; i < tam; ++i)
	{
		if (a[i] != x)
		{
			count++;
		}
	}
return count;

}

int changes(int a[], int b[], int tam){

	int count,i;
	count = 0;
	i = 0;

	if (has_more(a,tam) == 0)
	{
		count = dif(a,tam,0);
	} else {
		count = dif(a,tam,1);
	}

	if (has_more(b,tam) == 0)
	{
		count = count + dif(b,tam,0);
	} else {
		count = count + dif(b,tam,1);
	}

	return count;
}

int main(int argc, char const *argv[])
{
	int i,cup,r;
	r = 0;

	scanf("%d", &cup);

	int left_doors[cup];
	int rigth_doors[cup];

	for (i = 0; i < cup; ++i)
	{
		scanf("%d %d",&left_doors[i],&rigth_doors[i]);
	}

	r =  changes(left_doors,rigth_doors,cup);
	printf("%d",r );


	return 0;
}