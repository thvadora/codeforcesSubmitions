#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define pb push_back
#define bs binary_search

ll n;
vector <ll> a;
vector <ll> res;
int main(){
	cin >> n;
	ll tmp;
	for (int i = 0; i < n; ++i){
		cin >> tmp;
		a.pb(tmp);
	}
	sort(a.begin(),a.end());
	res.pb(a[0]);
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < 33; ++j){
			ll candidatea = a[i] - (1 << j);
			ll candidaten = a[i] + (1 << j);
			bool ant = bs(a.begin(),a.end(), candidatea);
			bool nxt = bs(a.begin(),a.end(), candidaten);
			if(ant && nxt && res.size() < 3){
				res.clear();
				res.pb(a[i]);
				res.pb(candidatea);
				res.pb(candidaten);
			}
			if(ant && res.size() < 2){
				res.clear();
				res.pb(a[i]);
				res.pb(candidatea);
			}
			if(nxt && res.size() < 2){
				res.clear();
				res.pb(a[i]);
				res.pb(candidaten);
			}
		}
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); ++i){
		cout << res[i] << " ";
	}

	return 0;
}