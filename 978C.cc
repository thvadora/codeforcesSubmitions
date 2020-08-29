#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define pb push_back

ll n,m,dorm[200001],letters[200001];
vector < pair<ll,ll> > res;

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; ++i){
		cin >> dorm[i];
	}
	ll sum,t;
	sum = 0;
	t = 0;
	for (int i = 0; i < m; ++i){
		cin >> letters[i];
		while(sum + dorm[t] < letters[i]){
			sum = sum + dorm[t];
			t++;
		}
		cout << t+1 << " " << letters[i]-sum << endl;

	}

	return 0;
}