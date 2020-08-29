#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pb push_back
#define bs binary_search
#define fs first 
#define sd second 
#define mk make_pair    
#define mt make_tuple

#define fore(i,a,b) for(ll i = a; i < b; i++)
#define rfore(i, a, b) for(ll i = a - 1; i >= b; i--)
#define mm(a,b) memset(a , b , sizeof a) 
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())
#define V(a) vector <a> 
#define P(a,b) pair<a,b>
#define M(a,b) map<a,b> 
#define S(a) set<a>
int c;
vector<int> g[10000];
int visited[10000];
pair <ll,ll> nodes[10000]; 

void dfs(ll i){
	visited[i]=1;
	for(auto x : g[i]){
		if(!visited[x])dfs(x);
	}
}
void connect(ll x, ll y){
	fore(i,0,c){
		if((x<nodes[i].fs && nodes[i].fs<y) || (x<nodes[i].sd && nodes[i].sd<y)){
			g[i].pb(c);		}
		if((nodes[i].fs<x && x<nodes[i].sd) || (nodes[i].fs<y && y<nodes[i].sd)){
			g[c].pb(i);
		}
	}
}
int main(){
	int n; cin>>n;
	while(n--){
		ll t,x,y; cin>>t>>x>>y;x--;y--;
		if(t==1){
			connect(x,y);
			nodes[c]= mk(x,y);
			c++;
		}
		if(t==2){
			mm(visited,0);
			dfs(x);
			if(visited[y])cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		} 
	}
	return 0;
}