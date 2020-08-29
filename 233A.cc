#include <iostream>
using namespace std;

void swap(int array[], int i, int j){
	int tmp = 0;
	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

int main(int argc, char const *argv[]){
	int n = 0;
	cin >> n;
	if(n % 2 != 0){
		cout<< -1;
	} else {
		int array[n];
		for (int i = 0; i < n; i+=2){
			array[i] = i+2;
			array[i+1] = i+1;
		}
		for (int i = 0; i < n-1; ++i){
			cout << array[i] << " ";
		}
		cout << array[n-1];
	}
	return 0;
}