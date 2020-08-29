#include <stdio.h>
#include <string.h>

int len(char a[]){
    int i;
    for(i = 0; a[i] != '\0'; ++i);
    return i;
}

int count_max_nexts(char players[]){
	int i = 0;
	int count = 1;
	int aux = 0;

	for (i = 0; i < len(players)-1; i++){
		if (players[i] == players[i+1]){
			count++;
		} else if (aux <= count){
			aux = count;
			count = 1;
			//printf("hola\n");
		} else {
			count = 1;
		}
	}
	if (count > aux){
		aux = count;
	}

return aux;

}

int main(int argc, char const *argv[]){
	
	char players[128];

	scanf("%s", &players);

	int p;

	p = count_max_nexts(players);

	//printf("%d\n", p );

	if(p>=7){
		printf("YES");
	} else {
		printf("NO");
	}

	return 0;
}