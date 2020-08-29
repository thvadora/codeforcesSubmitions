#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define pb push_back

vector <int> a;
vector <int> res;
int main(){

	int n;
	cin >> n;
	int ai;
	for (int i = 0; i < n; ++i){
		cin >> ai;
		a.pb(ai);
	}
	vector<int>::iterator it;
	for (int i = n-1; i >= 0; i--){
		it = find(res.begin(), res.end(), a[i]);
		if(it == res.end()){
			res.pb(a[i]);
		}
	}
	cout << res.size() << endl;
	reverse(res.begin(), res.end());
	for(auto i : res){
		cout << i << " ";
	}
	return 0;
}