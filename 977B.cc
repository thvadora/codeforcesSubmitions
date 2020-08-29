#include <iostream>
#include <string>
#include <map>
using namespace std;

map <string,int> m;

int main(){

	int n;
	cin >> n;
	string s;
	cin >> s;
	string current;
	for (int i = 1; i < n; ++i){
		current = string(s.begin()+i-1, s.begin()+i+1);
		m[current] = m[current]+1;
	}
	string two_gram;
	int maxx = -1;
	for (map<string,int>::iterator it = m.begin(); it != m.end(); ++it){
		if(it->second >= maxx){
			two_gram = it->first;
			maxx = it->second;
		}
	}
	cout << two_gram;
    

	return 0;
}