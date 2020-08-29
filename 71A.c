#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]){
	int length,n;
	char word[103];
	scanf("%d", &n);

	while(n>0){
		scanf("%s", &word);
		length = strlen(word);
		if(length <=10){
			printf("%s\n", word);
		} else {
			printf("%c%d%c\n",word[0], length-2, word[length-1]);
		}
		n--;
	}



	return 0;
}