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
const ll INF = 1e9+100;
                            
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

#define operr gcd
#define NEUTT 0
struct STreeBANANERO {
	vector<ll> st;ll n;
	STreeBANANERO(ll n): st(4*n+5,NEUTT), n(n) {}
	void init(ll k, ll s, ll e, ll *a){
		if(s+1==e){st[k]=a[s];return;}
		ll m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=operr(st[2*k],st[2*k+1]);
	}
	void upd(ll k, ll s, ll e, ll p, ll v){
		if(s+1==e){st[k]=v;return;}
		ll m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=operr(st[2*k],st[2*k+1]);
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(s>=b||e<=a)return NEUTT;
		if(s>=a&&e<=b)return st[k];
		ll m=(s+e)/2;
		return operr(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(ll *a){init(1,0,n,a);}
	void upd(ll p, ll v){upd(1,0,n,p,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
}; 


#define oper min
#define NEUT INF
struct STree {
	vector<ll> st;ll n;
	STree(ll n): st(4*n+5,NEUT), n(n) {}
	void init(ll k, ll s, ll e, ll *a){
		if(s+1==e){st[k]=a[s];return;}
		ll m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(ll k, ll s, ll e, ll p, ll v){
		if(s+1==e){st[k]=v;return;}
		ll m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(ll *a){init(1,0,n,a);}
	void upd(ll p, ll v){upd(1,0,n,p,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
};

M(ll,ll) id;
vector<ll> graciasLuis[100005];

int main (){FIN;
	ll n; cin>>n; ll a[n];
	ll pos = 1;
	fore(i,0,n){
		ll x; cin>>x;
		a[i]=x; id[x]; if(id[x]==0){id[x]=pos; pos++;}
	}
	fore(i,0,n)graciasLuis[id[a[i]]].pb(i+1);
	STree deme(n+2); STreeBANANERO trio(n+2);
	deme.init(a); trio.init(a);
	ll q; cin>>q;
	while(q--){
		ll l,r; cin>>l>>r;
		ll mini=deme.query(l-1,r);
		ll ggccdd=trio.query(l-1,r);
		//cout<<"jaja sape: "<<ggccdd<<" "<<mini<<endl;
		if(mini==ggccdd) cout<<(r-l+1)-(lower_bound(ALL(graciasLuis[id[ggccdd]]),r+1)-lower_bound(ALL(graciasLuis[id[ggccdd]]),l))<<endl;
		else cout<<(r-l+1)<<endl;

	}

	return 0;
}