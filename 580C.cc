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
int res=0;
vector <int> g[MAX_N];
int visited[MAX_N];
int c[MAX_N];
int n,k; 

void dfs(int i, int cons){
    visited[i]=1;
    if(cons>k)return;
    if(SZ(g[i])==1&&cons<=k&&i!=0)res++;
    if(!c[i])cons=0;
    for(auto x: g[i]){
        if(!visited[x])dfs(x,cons+c[x]);
    }
}

integer main(){
    cin>>n>>k; int m=n-1;
    fore(i,0,n)cin>>c[i];
    while(m--){
        int a,b; cin>>a>>b; a--; b--;
        g[a].pb(b); g[b].pb(a);
    }
    dfs(0,c[0]);
    cout<<res;
    return 0;
}