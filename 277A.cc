#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pb push_back
#define bs binary_search
#define ft first 
#define sd second 
#define mp make_pair    
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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
const int maxn = 1e4;
int n,m;
vector<int> g[maxn];
int visited[maxn];

void dfs(int i){
	visited[i]=1;
	for(auto x:g[i]){
		if(!visited[x]){
			dfs(x);
		}
	}
}
int main(){
	cin>>n>>m;
	vector <int> info[maxn];
	bool atleast=false;
	fore(i,0,n){
		int q; cin>>q;
		fore(j,0,q){
			atleast=true;
			int a; cin>>a;
			info[i].pb(a+n);
		}
	}
	if(!atleast){cout<<n; return 0;}
	fore(i,0,n){
		if(SZ(info[i])!=0){
			fore(j,0,SZ(info[i])){
				g[i].pb(info[i][j]);
				g[info[i][j]].pb(i);
			}
		}
	}
	int qq=0;
	fore(i,0,n){
		if(!visited[i]){
			qq++;
			dfs(i);
		}
	}
	cout<<qq-1;
	return 0;
}