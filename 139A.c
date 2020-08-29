#include <stdio.h>

int main(int argc, char const *argv[]){

	int i;
	int pages = 0;
	scanf("%d",&pages);

	int days_array[7];

	for (i = 0; i < 7 ; ++i){
		scanf("%d", &days_array[i]);
	}

	//c mamut
	int count = 0;

	/*for (i = 0; i < 7; ++i){
		count = count + days_array[i];
		if (count >= pages){
			printf("%d", i+1);
			break;
		}
	}*/
	//int falta;

	while(count < pages){
		//falta = pages - count;
		for (i = 0; i < 7; ++i){
			count = count + days_array[i];
			if (count >= pages){
				printf("%d",i+1);
				break;
			}
		}
	}

	return 0;
}