#include <iostream>
#include <string>

using namespace std;

int main(){

	int n = 0;
	cin >> n;
	int k;
	cin >> k;
	
	while(k){
		if(n % 10 == 0){
			n = n / 10;
		} else {
			n--;
		}
		k--;
	}

	cout << n;
	return 0;
}