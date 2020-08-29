#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[]){
	int n = 0, k = 0;
	cin >> n >> k;
	char abc[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char s[101];
	int i = 0;
	int j = 0;
	while(i < n){
		if(j >= k){
			j = 0;
		}
	s[i] = abc[j];
	i++;
	j++;
	}
	s[i] = '\0';
	cout << s;
	return 0;
}