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
const int MAX_N = 2e5;


typedef pair<ll,ll> pr;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

int a[MAX_N];
int dp[MAX_N];
int n;
int frq[MAX_N];

int solve(int pos){
    if(pos>n)return 0;
    int &r = dp[pos];
    if(r!=-1)return r;
    int r0,r1,r2,r3,r4; r0=r1=r2=r3=r4=0;
    r4 = solve(pos+1);
    if(a[pos]==a[pos-1]+1 && a[pos]+1==a[pos+1])r0=frq[a[pos]]*a[pos]+solve(pos+2);
    else if(a[pos]+1==a[pos+1])r1=frq[a[pos]]*a[pos]+solve(pos+2);
    else if(a[pos-1]+1==a[pos])r2=frq[a[pos]]*a[pos]+solve(pos+1);
    else r3 = frq[a[pos]]*a[pos]+solve(pos+1);
    r=max({r0,r1,r2,r3,r4});
    return r;
}

integer main(){
    mm(dp,-1); set <int> st;
    cin>>n; fore(i,0,n){int x; cin>>x; frq[x]++;st.insert(x);}
    int k=1;
    for(auto x:st)a[k++]=x;
    a[0] =MAX_N-1; a[n+1]=MAX_N; a[n+2]=MAX_N+1; a[n+3]=MAX_N+2; a[n+4]=MAX_N+3;
    n=k-1;
    sort(a+1,a+n+1);
    cout<<solve(1);
    return 0;
}