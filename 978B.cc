#include <iostream>
using namespace std;

char file[128];
int n;

int main(){

	cin >> n;

	for (int i = 0; i < n; ++i){
		cin >> file[i];
	}
	int countx = 0;
	for (int i = 2; i < n; ++i){
		if(file[i] == 'x' && file[i-1] == 'x' && file[i-2] == 'x'){
			countx++;
		}
	}
	cout << countx;
	return 0;
}