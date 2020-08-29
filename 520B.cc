#include <bits/stdc++.h>

using namespace std;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pb push_back
#define bs binary_search
#define ft first 
#define sd second 
#define mp make_pair    
#define mt make_tuple

#define fore(i,a,b) for(ll i = a; i < b; i++)
#define rfore(i, a, b) for(ll i = a - 1; i >= b; i--)
#define mm(a,b) memset(a , b , sizeof a) 
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())
#define V(a) vector <a> 
#define P(a,b) pair<a,b>
#define M(a,b) map<a,b> 
#define S(a) set<a>
const int inf = 1e7;
const int e4 = 2e4;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

int n,m;
int dp[e4*10];
int an[e4*10];

int solve(int i){
	if(i==m)return 0;
	if(i>e4 || i<0) return inf;
	if(dp[i]) return dp[i];
	if(an[i]) return inf;
	an[i]=1;
	int x,y; 
	x=1+solve(2*i); y=1+solve(i-1);
	dp[i] = min(x,y);
	return dp[i];
}

int main(){
	cin>>n>>m;
	cout<<solve(n);
	return 0;
}