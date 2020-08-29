#include <iostream>
#include <set>
#include <string>
using namespace std;
#define MAX 100

int main(){

	int n,m,fst,t;
	string bulb;
	set<int> g;
	cin >> n >> m;
	int matrix[256][256];
	for (int i = 0; i < n; ++i){
		cin >> fst;
		for (int j = 0; j < fst; ++j){
			cin >> t;
			g.insert(t);
		}
	}
	if(g.size() == m){
		cout << "YES";
	} else {
		cout << "NO";
	}
	
	return 0;
}