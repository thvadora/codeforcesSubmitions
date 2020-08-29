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
const ll mod = 1e9+7;


typedef pair<ll,ll> pll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

vector <int> g[1005];
int visited[1005];
map <int,int> nei;
vector <int> gov;
int vis;

void dfs(int i){
	visited[i]=1;
	vis++;
	for(auto x : g[i]){
		if(!visited[x])dfs(x);
	}
}


int main(){
	int n,m,k; cin>>n>>m>>k;
	fore(i,0,k){int a; cin>>a; a--; gov.pb(a);}
	fore(i,0,m){
		int x,y; cin>>x>>y; x--; y--;
		g[x].pb(y); g[y].pb(x);
	}
	int mx=0; ll res=0;
	fore(i,0,k){
		vis=0;
		dfs(gov[i]);
		res+=vis*(vis-1)/2;
		mx=max(mx,vis);
	}
	res-=mx*(mx-1)/2;
	fore(i,0,n)if(!visited[i]){vis=0;dfs(i);mx+=vis;}
	cout<<res-m+mx*(mx-1)/2;
	return 0;
}