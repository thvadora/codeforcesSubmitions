#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
#define ll long long
#define pb push_back
#define bs binary_search

#define MAXN 1000001

int a[MAXN],repeat[MAXN],n;

int main(){
	int m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)cin>>a[i];
	set<int> s;
	for (int i = n-1; i >= 0; i--){
		s.insert(a[i]);
		repeat[i] = s.size();
	}
	int l;
	while(m--){
		cin >> l;
		cout << repeat[l-1] << endl;
	}

	return 0;
}