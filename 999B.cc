#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back

int n;
string s;

int main(){
	cin >> n;
	cin >> s;
	vector<int> d;
	for (int i = 1; i <= n; i++){
		if(n%i == 0){
			d.pb(i);
		}
	}
	for (int i = 0; i < d.size(); ++i){
		reverse(s.begin(),s.begin()+d[i]);
	}
	cout << s;

}