#include <stdio.h>
#include <stdbool.h>

int len(char a[]){
    int i;
    for(i = 0; a[i] != '\0'; ++i);
    return i;
}
bool exists(char a[], int tam, char elem){

    bool r = false;
    int i;
    for (i = 0; i < tam; i++){
        if(a[i]==elem){
            r = true;
            break;
        }
    }
    return r;
}


int syntax(char a[]){

	if(exists(a,len(a),'H') == 1 || exists(a,len(a),'Q') == 1 || exists(a,len(a),'9') == 1){
		return 1;
	} else {
		return 0;
	}

}

int main(int argc, char const *argv[]){

	char input[128];

	scanf("%s", &input);

	if(syntax(input) == 1){
		printf("YES");
	} else {
		printf("NO");
	}

	
	return 0;
}