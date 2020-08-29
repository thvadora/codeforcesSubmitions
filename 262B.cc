#include <iostream>
using namespace std;

int sum(int array[], int tam){
	int summ = 0;
	for (int i = 0; i < tam; ++i){
		summ += array[i];
	}

return summ;
}

int main(int argc, char const *argv[]){
	int n,k;
	cin >> n >> k;
	int neg_pos = 0;
	int report[1000000];
	for (int i = 0; i < n; ++i){
		cin >> report[i];
		if(report[i] < 0){
			if(k!=0){
				report[i]*=-1;
				k--;
			}
			neg_pos = i;
		}
	}
	if(k % 2 != 0){
		if(abs(report[neg_pos]) >= report[neg_pos+1] && n != 1){
			report[neg_pos+1] *= -1;
		} else {
			report[neg_pos] *= -1;
		}
	}
	cout << sum(report,n);
	
	return 0;
}