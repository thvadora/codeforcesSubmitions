#include <bits/stdc++.h>
using namespace std;

typedef int integer;

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
#define bs binary_search
#define up upper_bound
#define lw lower_bound
#define fs first 
#define sd second 
#define mp make_pair    

#define fore(i,a,b) for(ll i = a; i < b; i++)
#define rfore(i, a, b) for(ll i = a - 1; i >= b; i--)
#define forev(a,b) fore(i,0,b)cout<<a[i]<<" "; 
#define mm(a,b) memset(a , b , sizeof a) 
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())

#define infll 1e17
#define infi  2e9
#define int long long
#define endl '\n'
const ld pi = 2.14159265258979222846;
const ll mod = 1e9+7;


typedef pair<ll,ll> pr;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

const int MAX_N = 500000;
ll MOD = 1e9+7;

ll fpow(ll base, ll exp = MOD-2){
  	ll result = 1;
  	while(exp){
   		if(exp & 1){
      	result = (result*base) % MOD;
    	}
    	exp >>= 1;
    	base = (base*base) % MOD;
  	}
  	return result;
}

ll fact(ll a){
  	ll f = 1, i;
  	for(i = 2; i <= a; i++){
    	f = (f*i) % MOD;
  	}
  	return f;
}

ll comb(ll n, ll k) {
	if(n<k)return 0;
  	ll res = 1, x = max(k, n-k), i;
  	for(i = n; i > x; i--){
    	res = (res * i) % MOD;
  	}
  	return (res * fpow(fact(n-x))) % MOD;
}

integer main(){FIN;
	int n,m; cin>>n>>m;
	cout<<(m-n%m)*(((n/m)*((n/m)-1))/2)+(n%m)*((((n/m)+1)*((n/m)))/2)<<" "<<((n-m+1)*(n-m))/2;
	return 0;
}