#include <bits/stdc++.h>
using namespace std;

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define bs binary_search
#define up upper_bound
#define fs first 
#define sd second 
#define mp make_pair    

#define fore(i,a,b) for(ll i = a; i < b; i++)
#define rfore(i, a, b) for(ll i = a - 1; i >= b; i--)
#define forev(a,b) fore(i,0,b)cout<<a[i]<<" "; 
#define mm(a,b) memset(a , b , sizeof a) 
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())

#define infll 1e18
#define infi  2e9
#define pi 3.14159265359 
#define mod 1e9+7
#define eps  1e-6

typedef pair<ll,ll> pll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

vector <int> g[100005];
int visited[100005];
bool t=true;

void dfs(int i, int parent){
	visited[i]=1;
	for(auto x : g[i]){
		if(visited[x] && x!=parent){t=false; return;}
		else if(!visited[x])dfs(x,i);
	}
}


int main(){FIN;
	int n,m; cin>>n>>m;
	while(m--){
		int x,y; cin>>x>>y; x--;y--;
		g[x].pb(y); g[y].pb(x);
	}
	int res=0;
	fore(i,0,n){
		if(!visited[i]){
			t=true;
			dfs(i,-1);
			if(t)res++;
		}
	}
	cout<<res;
}