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

vector < pair<ll, pair<ll,ll> > > v;
vector <ll> f;

int main(){
	ll n,m,k; cin>>n>>m>>k;
	while(m--){
		ll x,y,c; cin>>x>>y>>c;
		v.pb(mp(c,mp(x,y)));
	}
	while(k--){
		ll x; cin>>x;
		f.pb(x);
	}
	sort(ALL(f));
	ll res = inf;
	fore(i,0,SZ(v)){
		if(bs(ALL(f),v[i].sd.fs) && !bs(ALL(f),v[i].sd.sd))res=min(res,v[i].fs);
		if(bs(ALL(f),v[i].sd.sd) && !bs(ALL(f),v[i].sd.fs))res=min(res,v[i].fs);
	}
	if(res==inf){cout<<-1; return 0;}
	cout<<res;
	return 0;
}