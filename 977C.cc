#include <iostream>
#include <algorithm>
using namespace std;

int k,n,a[2*1000001],res;

int main(){
	cin >> n >> k;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a,a+n);
	if(k == 0 && a[0] > 1){
		res = a[0]-1;
	} else if(k >= 1 && a[k] > a[k-1]){
		res = a[k-1];
	} else if(k == n){
		res = a[n-1];
	}else{
		res = -1;
	}
	cout << res;
}