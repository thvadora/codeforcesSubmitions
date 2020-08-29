#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define pb push_back

int n,k;
char m[500001];

int main(){
	char abc[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
					'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	cin >> n >> k;
	char s;
	for (int i = 0; i < n; ++i)cin >> m[i];
	int i = 0;
	while(k > 0){
		char current = abc[i];
		for (int i = 0; i < n && k > 0; ++i){
			if(m[i] == current){
				m[i] = '1';
				k--;
			}
		}
		i++;
		//k--;
	}
	for (int i = 0; i < n; ++i){
		if(m[i] != '1'){
			cout << m[i];
		}
	}

	return 0;
}