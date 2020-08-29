#include <stdio.h>
#include <stdbool.h>

typedef struct par{
	int x;
	int y;
}par_t;

int cuantos_der(par_t a[],int n, int j){
	int res = 0;
	int i;

	for(i = 0; i < n; i++){
		if(a[j].x > a[i].x && a[j].y == a[i].y){
			res++;
		}		
	}
	return res;
}

int cuantos_izq(par_t a[],int n, int j){
	int res = 0;
	int i;

	for(i = 0; i < n; i++){
		if(a[j].x < a[i].x && a[j].y == a[i].y){
			res++;
		}		
	}
	return res;
}

int cuantos_up(par_t a[],int n, int j){
	int res = 0;
	int i;

	for(i = 0; i < n; i++){
		if(a[j].x == a[i].x && a[j].y < a[i].y){
			res++;
		}		
	}
	return res;
}

int cuantos_low(par_t a[],int n, int j){
	int res = 0;
	int i;

	for(i = 0; i < n; i++){
		if(a[j].x == a[i].x && a[j].y > a[i].y){
			res++;
		}		
	}	
	return res;
}


int main(int argc, char const *argv[]){
	
	int i, n, count = 0;
	scanf("%d", &n);
	par_t lista[n];

	for(i = 0; i < n; i++){
		scanf("%d %d", &lista[i].x, &lista[i].y);
	}

	for(i = 0; i < n; i++){
		if(cuantos_der(lista,n,i) >= 1){ /*&& cuantos_izq(lista,n,i) <= 1 && cuantos_up(lista,n,i) <= 1 && cuantos_low(lista,n,i) <= 1*/
			if(cuantos_izq(lista,n,i) >= 1){
				if(cuantos_up(lista,n,i) >= 1){
					if(cuantos_low(lista,n,i) >= 1){
						count++;
					}
				}
			}
		}
	}

	printf("%d", count);
	return 0;
}