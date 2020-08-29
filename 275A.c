#include <stdio.h>

void change(int *x){
	if (*x == 0)
	{
		*x = 1;
	} else {
		*x = 0;
	}

}

void change_cross(int temp_matrix[5][5],int x,int y){

	change(&temp_matrix[x][y]);
	change(&temp_matrix[x][y-1]);
	change(&temp_matrix[x][y+1]);
	change(&temp_matrix[x-1][y]);
	change(&temp_matrix[x+1][y]);
}

void func(int matrix[3][3]){
	int i,j;
	i = 0;
	j = 0;
	int temp_matrix[5][5];

	while(i < 5){
		while(j< 5){
			temp_matrix[i][j] = 1;
			j++;
		}
		i++;
		j = 0;
	}
	i = 0;
	j = 0;
	while(i < 3){
		while(j<3){
			if(matrix[i][j]%2 != 0){
				change_cross(temp_matrix,i+1,j+1);
			}
			j++;
		}
		i++;
		j = 0;
	}

	i = 1;
	j = 1;

	while(i < 4){
		while(j<4){
			matrix[i-1][j-1] = temp_matrix[i][j];
			j++;
		}
		i++;
		j= 1;
	}


}

int main(int argc, char const *argv[]){

	int i,j;
	i = 0;
	j = 0;
	int matrix[3][3];

	scanf("%d %d %d",&matrix[0][0],&matrix[0][1],&matrix[0][2]);
	scanf("%d %d %d",&matrix[1][0],&matrix[1][1],&matrix[1][2]);
	scanf("%d %d %d",&matrix[2][0],&matrix[2][1],&matrix[2][2]);

	func(matrix);


	while(i < 3){
		while(j<3){
			printf("%d",matrix[i][j]);
			j++;
		}
		if (i < 2){
			printf("\n");
		}
		i++;
		j = 0;
	}

	return 0;
}