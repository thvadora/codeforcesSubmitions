#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int steps(int initial, int final, int period){

	int count = 0;
	if (initial < final){
		count = (final - initial) / period;
		if ((final-initial) % period != 0){
			printf("-1");
			exit(0);
		}
	} else if(initial > final){
		count = (initial - final) / period;
		if ((final-initial) % period != 0){
			printf("-1");
			exit(0);
		}
	}

return count;
}

int go_to(int rows, int cols, int matrix[rows][cols], int lidder_number, int period){

	int i,j;
	int count = 0;

	for( i = 0; i < rows; i++){
		for( j = 0; j < cols; j++){
			count = count + steps(matrix[i][j], lidder_number, period);
		}
	}

	//printf("%d, ", count );

return count;

}

int main(int argc, char const *argv[]){
	int n,m,d;
	int i,j;

	scanf("%d %d %d", &n,&m,&d);

	int matrix[n][m];

	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
	
	int count = go_to(n,m,matrix,matrix[0][0],d);

	
	for (i = 0; i < n ; ++i){
		for (j = 0; j < m; ++j){
			if(count > go_to(n,m,matrix,matrix[i][j],d)){
				count = go_to(n,m,matrix,matrix[i][j],d);
			}
		}
	}
		printf("%d", count);


	return 0;
}