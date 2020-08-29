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

const int MAX_N = 1e5+10;

vector <ll> divs(ll x){
	vector<ll> res;
	for(ll i=2; i*i<= x;i++){
		if(x%i==0){
			res.pb(i);
			if(i*i!=x){
				res.pb(x/i);
			}
		}
	}
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	vector<ll> v; v.pb(1); v.pb(n*(n+1)/2);
	vector<ll> p = divs(n);
	for(auto x : p){
		ll demetrio = n/x;
		demetrio=(demetrio*(demetrio-1)/2)*x+demetrio;
		v.pb(demetrio);
	}
	sort(ALL(v));
	for(auto wolovick : v)cout<<wolovick<<" ";

	return 0;
}