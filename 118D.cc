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
#define fst first 
#define snd second 
#define mp make_pair    

#define fore(i,a,b) for(ll i = a; i < b; i++)
#define rfore(i, a, b) for(ll i = a - 1; i >= b; i--)
#define forev(a,b) fore(i,0,b)cout<<a[i]<<" "; 
#define mm(a,b) memset(a , b , sizeof a) 
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())

#define infll (long long)1e7
#define INF (long long)1e7
#define infi  (int)2e9
#define int long long
#define endl '\n'
const ld pi = 3.14159265258979222846;
const ll mod = 1e8;
const ld EPS = 1e-18;


typedef pair<ll,ll> pr;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

const int MAX_N = 2e5;

int dp[101][101][11][3];
int n,m,k0,k1; 

int solve(int i, int j, int c, int ant){
    if(c<0 || i>n || j>m)return 0;
    if(i==n&&j==m)return 1;
    int &r = dp[i][j][c][ant];
    if(r!=-1)return r;
    r=0;
    if(ant==1)r+=(solve(i+1,j,c-1,ant)+solve(i,j+1,k1-1,!ant))%mod;
    else r+=(solve(i,j+1,c-1,ant)+solve(i+1,j,k0-1,!ant))%mod;
    return r;
}

integer main(){
    mm(dp,-1);
    cin>>n>>m>>k0>>k1;
    cout<<solve(0,0,k0,1);
    return 0;
}