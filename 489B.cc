#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
#define pb push_back
#define bs binary_search

#define MAXN 1000

int main(){
	int n,m,res = 0;
	cin >> n;
	int b[n];
	for(int i = 0; i < n; i++)cin>>b[i];
	cin >> m;
	int g[m];
	for(int i = 0; i < m; i++)cin>>g[i];
	sort(b,b+n);
	sort(g,g+m);
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j	){
			if(abs(b[i]-g[j]) <= 1){
				res++;
				g[j] = MAXN;
				break;
			}
		}
	}
	cout << res;
	return 0;
}