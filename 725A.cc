#include <iostream>
using namespace std;

int out_der(char bumpers[], int n){
	int count = 0;
	bool b = true;
	for (int i = n-1; i >= 0 && b; i--){
		if(bumpers[i] == '>'){
			count++;
		} else {
			b = false;
		}
	}
return count;
}

int out_izq(char bumpers[], int n){
	int count = 0;
	bool b = true;
	for (int i = 0; i < n && b; ++i){
		if(bumpers[i] == '<'){
			count++;
		} else {
			b = false;
		}
	}
return count;
}

int main(int argc, char const *argv[]){
	int n;
	cin >> n;
	char bumpers[n];
	for (int i = 0; i < n; ++i){
		cin >> bumpers[i];
	}
	int count_der = out_izq(bumpers,n);
	int count_izq = out_der(bumpers,n);
	cout << count_der + count_izq;
	return 0;
}