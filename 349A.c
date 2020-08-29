#include <stdio.h>
#include <stdbool.h>

bool function_money(int line[], int n){
	bool b = true;
	int count_25 = 0;
	int count_50 = 0;
	for (int i = 0; i < n && b; ++i){
		if(line[i] == 25){
			count_25++;
		} else if(line[i] == 50){
			if(count_25 < 1){
				b = false;
			} else {
				count_25--;
				count_50++;
			}
		} else {
			if(count_25 > 0 && count_50 > 0){
				count_25--;
				count_50--;
			} else if(count_25 >= 3){
				count_25 = count_25 - 3;
			} else {
				b = false;
			}
		}
	}
return b;
}

int main(int argc, char const *argv[]){
	int n = 0;
	scanf("%d", &n);
	int line[n];
	for (int i = 0; i < n; ++i){
		scanf("%d", &line[i]);
	}

	if(line[0] == 25 && function_money(line,n)){
		printf("YES");
	} else {
		printf("NO");
	}

	return 0;
}