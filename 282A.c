#include <stdio.h>

int bit_lenguage(int n, char statements[n][8]){

	int count = 0;

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < 2; ++j)
		{
			if(statements[i][j] == '-' && statements[i][j+1] == '-'){
				count--;
			}
			if (statements[i][j] == '+' && statements[i][j+1] == '+'){
				count++;
			}
		}
	}

return count;

}

int main(int argc, char const *argv[]){
	
	int n = 0;
	scanf("%d", &n);

	char statements[n][8];

	for (int i = 0; i < n; ++i){
		scanf("%s", statements[i]);
	}

	/* just in case
	for (int i = 0; i < n; ++i){
		printf("%s, ", statements[i]);
	}
	*/

	printf("%d", bit_lenguage(n,statements));


	return 0;
}