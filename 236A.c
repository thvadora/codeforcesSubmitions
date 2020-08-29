#include <stdio.h>
#include <string.h>
//#include <stdlib.h>

int count_ceros(char user_name_converted[]){
	int i;
	int count = 0;

	for (i = 0; i < strlen(user_name_converted); i++){
		if (user_name_converted[i] == '0'){
			count++;
		}
	}

return count;
}

int count_equals(char user_name[]){
	int i = 0;
	int j = 1;
	int count = 0;

	while(i < strlen(user_name)-1){
		while(j< strlen(user_name)){
			if(user_name[i] == user_name[j]){
				user_name[j] = '0';
			}
			j++;
		}
		i++;
		j = i+1;
	}

count = count_ceros(user_name);

return count;

}

int main(int argc, char const *argv[]){
	int  complement = 0;
	char user_name[103];

	scanf("%s", &user_name);

	complement = count_equals(user_name);

	if((strlen(user_name)-complement) % 2 == 0){
		printf("CHAT WITH HER!");
	} else {
		printf("IGNORE HIM!");
	}
	

	return 0;
}