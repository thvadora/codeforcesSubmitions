#include <stdio.h>
#include <string.h>

// use strcmp(a,b) == 0
int len(char a[]){
    int i;
    for(i = 0; a[i] != '\0'; ++i);
    return i;
}

char teams(int n, char array_strings[n][16]){

	int i = 0;
	char first_team[16];
	char second_team[16];

	strcpy(first_team, array_strings[0]);

	for (i = 1; i < n; i++){
		if(strcmp(array_strings[i], first_team) != 0){
			strcpy(second_team, array_strings[i]);
			break;
		}
	}

	int count_first = 0;
	int count_second = 0;

	for (i = 0; i < n; i++){
		if(strcmp(array_strings[i],first_team) == 0){
			count_first++;
		} else {
			count_second++;
		}
	}

	//printf("%d %d\n", count_first, count_second);

	if(count_first > count_second){
		printf("%s", first_team );
	} else {
		printf("%s", second_team );
	}


}

int main(void){

	int n = 0;
	scanf("%d", &n);
	
	char array_strings[n][16];
	int i = 0;

	for (i = 0; i < n; ++i){
		scanf("%s", &array_strings[i]);
	}

	teams(n,array_strings);

	/*for (i = 0; i < n; ++i){
		printf("%s, ", array_strings[i] );
	}*/


	return 0;
}