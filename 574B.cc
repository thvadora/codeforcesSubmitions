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

vector <int> g[100001];

int main(){FIN;
	int n,m; cin>>n>>m;
	while(m--){
		int x,y; cin>>x>>y; x--; y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	fore(i,0,n){
		sort(ALL(g[i]));
	}
	ll res = infi;
	fore(i,0,n){
		fore(j,0,SZ(g[i])){
			int cur=g[i][j];
			fore(k,0,SZ(g[cur])){
				int cur2=g[cur][k];
				if(binary_search(g[i].begin(),g[i].end(),cur2)){
					res=min(res,(SZ(g[i])+SZ(g[cur])+SZ(g[cur2]))-6);
				}
			}
		}
	}
	if(res!=infi)cout<<res;
	else cout<<-1;
	return 0;
}