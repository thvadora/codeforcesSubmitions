#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define pb push_back
#define ll long long

map <string,ll> data;

int main(){
	ll n,k,m;
	cin >> n >> k >> m;
	ll a[n];
	ll cost[n];
	ll grupo[n];
	string s;
	string sarray[n];
	for (ll i = 0; i < n; ++i){
		cin >> s;
		data[s] = i;
		cost[i] = (ll)1e9;
	}
	for (ll i = 0; i < n; ++i)cin >> a[i];
	for (ll i = 0; i < k; ++i){
		ll t = 0;
		cin >> t;
		while(t--){
			ll g = 0;
			cin >> g;
			grupo[g-1] = i;
			cost[i] = min(cost[i],a[g-1]);
		}
	}
	ll res = 0;
	while(m--){
		cin >> s;
		res = res + cost[grupo[data[s]]];
	}
	cout << res;

	return 0;
}