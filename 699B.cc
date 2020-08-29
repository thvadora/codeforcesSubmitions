#include <iostream>
using namespace std;


int main(){
	int n = 0, m = 0;
	int count_walls = 0;
	cin >> n >> m;
	char depot[n][m];
	int line_sum[n];
	int col_sum[m];
	int help[n];
	int sum = 0;
	int i,j;
	for (i = 0; i < n; ++i){
		for (j = 0; j < m; ++j){
			cin >> depot[i][j];
			if(depot[i][j] == '*'){
				sum++;
			}
		}
		line_sum[i] = sum;
		//cout << line_sum[0]<< endl;
		count_walls += sum;
		sum = 0;
	}
	for (int i = 0; i < n; ++i){
		help[i] = line_sum[i];
	}
	sum = 0;
	for (i = 0; i < m; ++i){
		for (j = 0; j < n; ++j){
			if(depot[j][i] == '*'){
				sum++;
			}
		}
		col_sum[i] = sum;
		sum = 0;
	}
	//cout << help[0] << endl;
	int current_sum = 0;
	int k = -1;
	for (i = 0; i < n; ++i){
		for (j = 0; j < m; ++j){
			 //cout << "fila:"  << line_sum[0]<< endl;
			 current_sum = help[i] + col_sum[j];
			 //cout << current_sum << endl;
			 if(depot[i][j] == '*'){
			 	current_sum--;
			 }
			 if(current_sum == count_walls){
			 	k = 1;
			 	break;
			 }
		}
		if(current_sum == count_walls){
			break;
		}
	}

	if(k == 1){
		cout << "YES" << endl;
		cout << i+1 << " " << j+1;
	} else {
		cout << "NO";
	}


	return 0;
}