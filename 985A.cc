#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	int m = n/2;
	int p[m];
	int op1 = 0, op2 = 0;
	for (int i = 0; i < m; ++i)cin>>p[i];
	sort(p,p+m);
	for (int i = 0; i < m; ++i){
		op1 += abs(p[i]-(i*2+1));
		op2 += abs(p[i]-(i*2+2));
	}
	int res = min(op1,op2);
	cout << res;
	return 0;
}