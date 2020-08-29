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
const int MAX_N = 2e5+10;

vector <int> g[MAX_N];
int visited[MAX_N];
int parent[MAX_N];

void dfs(int i,int p){
    visited[i]=1; parent[i]=p;
    for(auto x : g[i]){
        if(!visited[x])dfs(x,i);
    }
}

integer main(){
    int n; cin>>n;
    int cc=1; map<string,int> mpp;
    fore(i,0,n){
        string name1,basura,name2;
        cin>>name1>>basura>>name2;
        transform(ALL(name1),name1.begin(),::tolower);
        transform(ALL(name2),name2.begin(),::tolower);
        if(mpp[name1]==0)mpp[name1]=cc,cc++;
        if(mpp[name2]==0)mpp[name2]=cc,cc++;
        g[mpp[name2]].pb(mpp[name1]);
    }
    cc=1; int res=0;
    dfs(mpp["polycarp"],-1);
    for(auto x : mpp){
        int node = x.sd;
        //cout<<"analizando: "<<x.fs<<endl;
        if(node!=mpp["polycarp"]){
            while(parent[node]!=mpp["polycarp"]){
                node=parent[node]; cc++;
            }
            res=max(res,cc); cc=1;
        }
    }
    cout<<res+1;
    return 0;
}