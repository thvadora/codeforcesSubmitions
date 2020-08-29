#include <iostream>
using namespace std;

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	char room[n][m];
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cin >> room[i][j];
		}
	}
	int sum = 0;
	int aux = 0;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if(room[i][j] == '.'){
				aux++;
			} else if (aux >= k){
				sum = sum + (aux - k + 1);
				aux = 0;
			} else {
				aux = 0;
			}
		}
		if(aux>=k){
			sum = sum + (aux - k + 1);
		}
		aux = 0;
	}
	if(k>1){
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j){
				if(room[j][i] == '.'){
					aux++;
				} else if (aux >= k){
					sum = sum + (aux - k + 1);
					aux = 0;
				} else {
					aux = 0;
				}
			}
			if(aux>=k){
				sum = sum + (aux - k + 1);
			}
			aux = 0;
		}
	}
	cout << sum;
	
	return 0;
}