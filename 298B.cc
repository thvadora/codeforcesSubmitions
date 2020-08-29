#include <iostream>
#include <vector>
using namespace std;
#define pb push_back


int main(){
	int n = 0;
	cin >> n;
	pair<int,int> start;
	pair<int,int> end;
	cin >> start.first >> start.second >> end.first >> end.second;
	vector<char> v;
	char t;
	for (int i = 0; i < n; ++i){
		cin >> t;
		v.pb(t);
	}
	int i = 0;
	int r_i = 0;
	while(i<n){
		if(v[i] == 'E'){
			if(abs((start.first + 1) - end.first) < abs(start.first - end.first)){
				start.first += 1;
			}
		}
		if(v[i] == 'S'){
			if(abs((start.second - 1) - end.second) < abs(start.second - end.second)){
				start.second -= 1;
			}
		}
		if(v[i] == 'W'){
			if(abs((start.first - 1) - end.first) < abs(start.first - end.first)){
				start.first -= 1;
			}
		}
		if(v[i] == 'N'){
			if(abs((start.second + 1) - end.second) < abs(start.second - end.second)){
				start.second += 1;
			}
		}
		if(start.first == end.first && start.second == end.second){
			r_i = i;
			break;
		}
		i++;
	}
	if(i>=n){
		cout << -1;
	} else {
		cout << r_i+1;
	}
	return 0;
}