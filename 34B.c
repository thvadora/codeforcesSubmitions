#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int insertion_sort (int *a, int tam){

	int key, i, j;

		for (i = 1; i < tam; i++){
			key = a[i];
			j = i - 1;

			while (j >= 0 && a[j] > key){
				a[j+1] = a[j];
				j--;
			} 

			a[j+1] = key;

		}

return *a;

}

int negatives(int *array, int tam, int can_carry){

	int neg[tam];
	int k = 0;

	//fill neg with limits
	for (int i = 0; i < tam; ++i){
		neg[i] = INT_MIN;
	}



	for (int i = 0; i < tam; ++i){
		if(array[i] < 0 ){
			neg[k] = array[i];
			k++;
		}	
	}

	if(k > can_carry){

		insertion_sort(neg,k);

		int sum = 0;
		for (int i = 0; i < can_carry; ++i){
			sum = sum + neg[i];
		}

		printf("%d", abs(sum));

	} else {
		int sum = 0;
		for (int i = 0; i < k; ++i){
			sum = sum + neg[i];
		}
		printf("%d", abs(sum));
	}


return *neg;

}

int main(int argc, char const *argv[]){
		
	int tvs = 0;
	scanf("%d", &tvs);
	int can_carry = 0;
	scanf("%d", &can_carry);

	int tv_prices[tvs];
	for (int i = 0; i < tvs; ++i){
		scanf("%d", &tv_prices[i]);
	}

	negatives(tv_prices,tvs, can_carry);


	return 0;
}