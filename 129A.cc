#include <iostream>
using namespace std;

int ways(int array[], int n, int k){
	int count = 0;
	for (int i = 0; i < k; ++i){
		count = count + array[i];
	}
	for (int i = k+1; i < n; ++i){
		count = count + array[i];
	}
	if(count % 2 != 0){
		count = 0;
	} else {
		count = 1;
	}
return count;
}

int main(int argc, char const *argv[]){
	ios::sync_with_stdio(false);
	int n = 0;
	cin >> n;
	int bags[n];
	int count = 0;
	for (int i = 0; i < n; ++i){
		cin >> bags[i];
		if(bags[i] % 2 == 0){
			bags[i] = 2;
		} else {
			bags[i] = 1;
		}
	}
	for (int i = 0; i < n; ++i){
		count += ways(bags,n,i);
	}
	if (count == 0){
		cout << count;
	} else {
		cout << count;
	}
	return 0;
}