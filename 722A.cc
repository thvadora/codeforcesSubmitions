#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
	string hour;
	int format = 0;
	cin >> format;
	cin >> hour;
	if(format == 24){
		if(hour[3] > '5'){
			hour[3] = '0';
		}
		if(hour[0] > '2'){
			hour[0] = '0';
		}else if(hour[0] == '2' && hour[1] > '3'){
			hour[1] = '0';
		}
	} else {
		if(hour[3] > '5'){
			hour[3] = '0';
		}
		if(hour[0] > '1' && hour[1] < '3'){
			hour[0] = '1';
		}else if(hour[0] > '1' && hour[1] >= '3'){
			hour[0] = '0';
		}else if(hour[0] == '1' && hour[1] > '2'){
			hour[1] = '0';
		}
		if(hour[0] == '0' && hour[1] == '0'){
			hour[1] = '1';
		}
	}
	cout<<hour;
	return 0;
}