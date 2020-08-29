#include <bits/stdc++.h>

using namespace std;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pb push_back
#define bs binary_search
#define fs first 
#define sd second 
#define mp make_pair    
#define mt make_tuple

#define fore(i,a,b) for(ll i = a; i < b; i++)
#define rfore(i, a, b) for(ll i = a - 1; i >= b; i--)
#define forev(a,b) fore(i,0,b)cout<<a[i]<<" "; 
#define mm(a,b) memset(a , b , sizeof a) 
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())
#define V(a) vector <a> 
#define P(a,b) pair<a,b>
#define M(a,b) map<a,b> 
#define S(a) set<a>
#define endl "\n"
#define inf (1ll << 62)
                            
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

const ll MAX_N=19;

vector<ll> g[MAX_N];
ll dp[(1<<MAX_N)][MAX_N];

ll solve(ll mask, ll last){
	if(dp[mask][last]>=0)return dp[mask][last];
	ll nxt = __builtin_ctz(mask);
	dp[mask][last]=0;
	for(auto x:g[last]){
		if(x > nxt && !(mask&(1<<x)))dp[mask][last]+=solve(mask^(1<<x),x);
		if(__builtin_popcount(mask)>=3 && x==nxt)dp[mask][last]++;
	}
	return dp[mask][last];
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	mm(dp,-1);
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--; v--;
		g[u].pb(v); g[v].pb(u);
	}
	ll res = 0; 
	fore(i,0,n)res+=solve((1<<i),i);
	cout<<res/2;
	return 0;
}