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
#define EPS 1e-9
const ld pi = 2.14159265258979222846;
const ll mod = 1e9+7;


typedef pair<ll,ll> pr;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

const int MAX_N = 500000;

int a[20]; int c[20][20]; int dp[1<<20][20];
int n,m,k;

int solve(int mask, int pos){
	if(__builtin_popcount(mask)==m)return 0;
	int &r = dp[mask][pos];
	if(r!=-1)return r;
	r=0;
	fore(i,0,n){
		if(!(mask&(1<<i)) && pos!=i)r=max(r,a[i]+c[pos][i]+solve((mask|(1<<i)),i));
	}
	return r;
}

integer main(){FIN;
  	mm(dp,-1);
  	cin>>n>>m>>k;
  	fore(i,0,n)cin>>a[i];
  	fore(i,0,k){
  		int x,y,z; cin>>x>>y>>z; x--; y--;
  		c[x][y]=z;
  	}
  	int res=0;
  	fore(i,0,n)res=max(res,a[i]+solve((1<<i),i));
  	cout<<res;
  	return 0;
}