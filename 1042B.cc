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

#define infll (long long)1e7
#define infi  (int)2e9
#define int long long
#define endl '\n'
const ld pi = 2.14159265258979222846;
const ll mod = 1e9+7;
const ld EPS = 1e-18;


typedef pair<ll,ll> pr;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

const int MAX_N = 2e5;

int n;
int cst[MAX_N];
string s[MAX_N];
int dp[1010][3][3][3];

int solve(int pos,int a,int b,int c){
	if(a>=1 && b>=1 && c>=1)return 0;
	if(pos==n)return infll;
	a=min(a,1ll); b=min(b,1ll); c=min(c,1ll);
	int &r = dp[pos][a][b][c];
	if(r!=-1)return r;
	int aa=(s[pos][0]=='A')||(s[pos][1]=='A')||(s[pos][2]=='A');
	int bb=(s[pos][0]=='B')||(s[pos][1]=='B')||(s[pos][2]=='B');
	int cc=(s[pos][0]=='C')||(s[pos][1]=='C')||(s[pos][2]=='C');
	r=min(cst[pos]+solve(pos+1,a+aa,b+bb,c+cc),solve(pos+1,a,b,c));
	return r;
}

integer main(){
	mm(dp,-1);
	cin>>n;
	fore(i,0,n)cin>>cst[i]>>s[i];
	int res=solve(0,0,0,0);
	if(res>=infll)cout<<-1;
	else cout<<res;
	return 0;
}