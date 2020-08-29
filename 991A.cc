#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define pb push_back

int a,b,c,n;

int main(){
	cin >> a >> b >> c >> n;
	int res = a + b - c;
	if(res < n && c <= min(a,b)){
		cout << (n - res);
	} else {
		cout << -1;
	}

	return 0;
}