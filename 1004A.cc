#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n,d;
	cin >> n >> d; int x[n];
	for (int i = 0; i < n; ++i)cin >> x[i];
	sort(x,x+n);
	int res = 2;
	int last = x[0];
	for (int i = 0; i < n-1; ++i){
		if(abs(x[i]-x[i+1]) > 2*d)res+=2;
		if(abs(x[i]-x[i+1]) == 2*d)res++;
	}
	cout << res;
	return 0;
}