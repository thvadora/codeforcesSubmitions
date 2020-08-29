#include <iostream>
#include <vector>
using namespace std;
#define pb push_back

int min_vec(vector< pair<int,int> > v, int final){
	int min = 0;
	for (int i = 1; i < final; ++i){
		if(v[min].first > v[i].first){
			min = i;
		}
	}
return min;
}

int main(){
	vector< pair<int,int> > v;
	int days = 0;
	cin >> days;
	int t,k;
	for (int i = 0; i < days; ++i){
		cin >> t >> k;
		v.pb(make_pair(k,t));
	}
	int m;
	int res = 0;
	int final = v.size();
	while(final != 0){
		m = min_vec(v,final);
		for (int i = m; i < final; ++i){
			res = res + v[m].first * v[i].second;
		}
		final = m;
	}
	cout << res;


	return 0;
}