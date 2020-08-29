#include <iostream>
#include <algorithm>
using namespace std;

int max_position(int array[], int n){
	int maximum = array[0];
	int current = 0;
	for (int i = 1; i < n; ++i){
		if(maximum < array[i]){
			current = i;
			maximum = array[i];
		}
	}
return current;
}

int main(){
	ios :: sync_with_stdio(false);
	int n = 0;
	cin >> n;
	int array[n];
	for (int i = 0; i < n; ++i){
		cin >> array[i];
	}
	int max_pos = max_position(array,n);
	array[max_pos] = (array[max_pos] == 1 ? 2 : 1);
	sort(array,array+n);
	for (int i = 0; i < n; ++i){
		cout << array[i] << " ";
	}
	return 0;
}