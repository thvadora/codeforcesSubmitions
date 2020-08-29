#include <stdio.h>
#include <math.h>

float maxx(float array[], int tam){

	float max_value = 0.0;

	for (int i = 0; i < tam; ++i){
		if (array[i] >= max_value){
			max_value = array[i];
		}
	}

return max_value;

}

int times(float array[],int tam, float elem){

	int count = 0;

	for (int i = 0; i < tam; ++i){
		if (array[i] == elem){
			count++;
		}
	}

return count;

}

int combinations(float arrayA[], int n, float arrayB[], int m){

	float ratio = 0.0;
	float int_ratios[m*n];

	//fill int_ratios whith min values = 0
	for (int i = 0; i < m*n; ++i){
		int_ratios[i] = 0;
	}
	int k = 0;

	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j){
			ratio = arrayB[i] / arrayA[j];
			if ( fmod(ratio,2.0) == 0 || fmod(ratio,2.0) == 1){
				int_ratios[k] = ratio;
				k++;
			}
		}
	}

	float max = maxx(int_ratios,k);
	int count = times(int_ratios,k,max);

return count;

}

int main(int argc, char const *argv[]){

	int pedal_axe = 0;
	scanf("%d", &pedal_axe);

	float pedal_stars[pedal_axe];
	for (int i = 0; i < pedal_axe; ++i){
		scanf("%f", &pedal_stars[i]);
	}

	int wheel_axe = 0;
	scanf("%d", &wheel_axe);

	float wheel_stars[wheel_axe];
	for (int i = 0; i < wheel_axe; ++i){
		scanf("%f", &wheel_stars[i]);
	}

	int count = 0;
	count = combinations(pedal_stars,pedal_axe,wheel_stars,wheel_axe);

	printf("%d", count );

	return 0;
}