#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
#define ll long long
#define pb push_back
#define maxn 10

int n,m;
int a[10],b[10];
vector<int> res;

int main(){
	int* p;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];
	for (int i = 0; i < n; i++){
		p = find(b,b+m,a[i]);
		if(p!=b+m){
			res.pb(a[i]);
		}
	}
	for (int i = 0; i < res.size(); ++i){
		cout << res[i] << " ";
	}

	return 0;
}