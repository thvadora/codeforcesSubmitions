#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll n,w,record[1024];

int main(){
	cin >> n >> w;
	for (int i = 0; i < n; ++i){
		cin >> record[i];
	}
	ll i = 0;
	ll del = 0,maxx = w;
	ll sum = 0;
	while(i < n){
		sum = sum + record[i];
		del = max(del,0-sum);
		maxx = min(maxx,w-sum);
		i++;
	}
	if(del <= maxx){
		cout << maxx - del +1;
	} else{
		cout << 0;
	}

	return 0;
}