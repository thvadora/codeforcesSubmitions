#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
using namespace std;
#define ll long long
#define pb push_back
#define bs binary_search

#define MAX 1000

int n,m,q;
int visited[100000];
vector < pair<int,int> > g[100000];
bool dfs_bool;

void dfs(int i, int color, int llegada){
	if(i == llegada){
		dfs_bool = 1;
		return;
	}
	visited[i] = 1;
  	for(auto x : g[i]){
    	if(!visited[x.first] && color == x.second){
      		dfs(x.first,color,llegada);
    	}
  	}
}

int main(){
	cin >> n >> m;
	int u,v,c;
	for (int i = 0; i < m; ++i){
		cin >> u >> v >> c;
		g[u].pb(make_pair(v,c));
		g[v].pb(make_pair(u,c));
	}
	cin >> q;
	int can = 0;;
	while(q--){
		can = 0;
		cin >> u >> v;
		for (int i = 1; i <= m; ++i){
			dfs_bool = false;
			dfs(u,i,v);
			if(dfs_bool)
				can++;
			for (int i = 0; i < MAX; ++i){
				visited[i] = 0;
			}
		}
		cout << can <<endl;
	}

	return 0;
}