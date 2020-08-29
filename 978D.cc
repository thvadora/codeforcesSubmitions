#include <iostream>

using namespace std;

#define ll long long

ll b[1000001];
ll n;


ll can(ll a0,ll a1){
	bool d = true;
	ll dif = a1-a0;
	ll res = 10000000001;
	ll count = 0;
	ll ai;
	for (int i = 0; i < n && d; ++i){
		 ai = a0 + i*(a1-a0);
		if(abs(ai-b[i]) > 1){
			d = false;
		}else if(b[i] != ai){
			count++;
		}
	}
	if(d){
		res = count;
	}

return res;
}

int main(){

	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> b[i];
	}
	if (n<=2){
		cout << 0;
	} else {
		ll res = 10000000001;
		for (int i = -1; i < 2; ++i){
			for (int j = -1; j < 2; ++j){
				res = min(res,can(b[0]+i,b[1]+j)); 
			}
		}
		if(res == 10000000001){
			cout << -1;
		} else {
			cout << res;
		}
	}

	return 0;
}