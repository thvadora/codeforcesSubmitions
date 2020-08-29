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

#define infi  2e9
#define int long long
#define endl '\n'
const ld pi = 3.14159265358979323846;
const ll mod = 1e9+7;
const ll INF = 1e10;
const ll MAXN =3000;

typedef pair<ll,ll> pll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

int n,m,x,y;
int chhash[MAXN];
int chdot[MAXN];
char wall[MAXN][MAXN];
int dp[MAXN][2][MAXN];

int solve(int pos, int color, int times){
	if(pos==m){
		if(times>=x && times<=y)return 0;
		else return INF;
	}
	int &r = dp[pos][color][times];
	if(r!=-1)return r;
	r = INF;
	if(times<x){
		if(color==0)r=chhash[pos]+solve(pos+1,color,times+1);
		else r=chdot[pos]+solve(pos+1,color,times+1);
	}else if(times>=x && times<y){
		if(color==0)r=min(chhash[pos]+solve(pos+1,color,times+1),chdot[pos]+solve(pos+1,!color,1));
		else r=min(chdot[pos]+solve(pos+1,color,times+1),chhash[pos]+solve(pos+1,!color,1));
	}
	else{
		if(color==0)r=chdot[pos]+solve(pos+1,!color,1);
		else r=chhash[pos]+solve(pos+1,!color,1);
	}
	return r;
}

integer main(){
 	cin>>n>>m; cin>>x>>y; mm(dp,-1);
 	fore(i,0,n)fore(j,0,m)cin>>wall[i][j];
 	fore(j,0,m)fore(i,0,n)chdot[j]+=(wall[i][j]=='.');
 	fore(j,0,m)fore(i,0,n)chhash[j]+=(wall[i][j]=='#');
 	cout<<min(solve(0,0,0),solve(0,1,0));
    return 0;
}