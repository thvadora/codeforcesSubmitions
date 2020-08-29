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
int n;
int x[MAX_N],h[MAX_N];
int dp[200000][3];

//1 izq, 2 der, 0 nada

int solve(int pos, int f){
	if(pos==0)return 1+solve(pos+1,1);
	if(pos>=n-1)return 1;
	int &r = dp[pos][f];
	if(r!=-1)return r;
	int r1,r0,r2; r1=0; r0=0; r2=0;
	if(f==1 || f==0){
		if(x[pos]-h[pos]>x[pos-1])r1+=(1+solve(pos+1,1));
		r0+=solve(pos+1,0);
		if(x[pos]+h[pos]<x[pos+1])r2+=(1+solve(pos+1,2));
	}
	if(f==2){
		if(x[pos-1]+h[pos-1]<x[pos]-h[pos])r1+=(1+solve(pos+1,1));
		r0+=solve(pos+1,0);
		if(x[pos]+h[pos]<x[pos+1])r2+=(1+solve(pos+1,2));
	}
	r = max({r0,r1,r2});
	return r;
}

integer main(){FIN;
	cin>>n; if(n==1){cout<<1; return 0;}
	fore(i,0,n)cin>>x[i]>>h[i];
	mm(dp,-1);	
	cout<<solve(0,0);
	return 0;
}