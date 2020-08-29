#include <iostream>
#include <stdbool.h>
using namespace std;

int main(int argc, char const *argv[]){
	string number;
	cin >> number;
	bool b = true;
	int state = 0;
	int i = 0;
	while(i < number.length() && state != 3){
		if(number[i] == '1'){
			state = 0;
		} else if(number[i] == '4' && number[i-1] == '1'){
			state = 1;
		} else if(number[i] == '4' && number[i-1] == '4' && number[i-2] == '1'){
			state = 2;
		} else {
			b = false;
			state = 3;
		}
		i++;
	}
	if(b){
		cout<<"YES";
	} else {
		cout<<"NO";
	}

	return 0;
}