#include <bits/stdc++.h>
using namespace std;

typedef int integer;

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
#define bs binary_search
#define up upper_bound
#define fs first 
#define sd second 
#define mp maeache_pair    

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
const ld pi = 3.14159265358979323846;
const ll mod = 1e9+7;


typedef pair<ll,ll> pll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
const int MAX_N = 500;

vector <int> g[MAX_N];
vector <int> comp[MAX_N];
int visited[MAX_N];

void dfs(int i, int c){
    visited[i]=1;
    comp[c].pb(i);
    for(auto x : g[i]){
        if(!visited[x])dfs(x,c);
    }
}

integer main(){
    int n; cin>>n; int v[n];
    fore(i,0,n)cin>>v[i];
    fore(i,0,n){
        fore(j,0,n){
            char c; cin>>c;
            if(c=='1'){
              g[v[i]].pb(v[j]); g[v[j]].pb(v[i]);
            }
        }
    }
    int cc=0;
    fore(i,1,n+1){
        if(!visited[i])dfs(i,cc),cc++;
    }
    map <int,int> mpp;
    fore(i,0,cc){
        fore(j,0,SZ(comp[i]))mpp[comp[i][j]]=i;
    }
    fore(i,0,cc){
        sort(ALL(comp[i]));
    }
    int pos[cc];
    fore(i,0,cc)pos[i]=0;   
    fore(i,0,n){
        v[i]=comp[mpp[v[i]]][pos[mpp[v[i]]]];
        pos[mpp[v[i]]]++;
    }
    fore(i,0,n)cout<<v[i]<<" ";
    return 0;
}