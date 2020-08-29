#include <stdio.h>
#include <math.h>

int minimum(int a, int b, int c){

	int min_value = 0;

	if( a < b && a < c){
		min_value = a;
	} else if( b < a && b < c){
		min_value = b;
	} else if( c < a && c < b){
		min_value = c;
	} else if(a == b && a < c){
		min_value = a;
	} else if(a==c && a < b){
		min_value = a;
	} else if(b == c && b < a){
		min_value = c;
	} else if( a== b && b == a){
		min_value = b;
	}
return min_value;
}

int main(int argc, char const *argv[]){

	int n,k,l,c,d,p,nl,np;
	int toast;

	scanf("%d %d %d %d %d %d %d %d", &n,&k,&l,&c,&d,&p,&nl,&np);

	int t_slices, t_ml,t_salt;

	t_slices = c*d;
	t_ml = k*l;
	t_salt = p;

	toast = minimum(t_slices, t_ml / nl, t_salt / np) / n;
	printf("%d", toast );

	return 0;
}