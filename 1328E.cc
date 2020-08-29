#include <bits/stdc++.h>
using namespace std;
 
typedef int integer;

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
#define bs binary_search
#define up upper_bound
#define lw lower_bound
#define fst first
#define snd second
#define secondd second 
#define mp make_pair    
 
#define fore(i,a,b) for(ll i = a; i < b; i++)
#define rfore(i, a, b) for(ll i = a - 1; i >= b; i--)
#define forev(a,b) fore(i,0,b)cout<<a[i]<<" "; 
#define mm(a,b) memset(a , b , sizeof a) 
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())
 
#define infll (long long)1e13
#define INF (long long)1e13
#define infi  (int)2e9
#define int long long
#define endl '\n'
const ld pi = acos(-1);
const long long MOD = 1e9+7;
const ld EPS = 1e-9;
const int MAXN = 2e5;
 
typedef pair<ll,ll> pr;
 
int gcd(int a, int b) { return b == 0 ? a : gcd(b,a%b); } 
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int fpow(int b, int e, int m=MOD){if(!e)return 1;int q=fpow(b,e/2,m);q=(q*q)%m;return e&1?(b*q)%m:q;}
void printgraph(vector <int> g[], int n){fore(i,0,n){for(auto x:g[i]){cout<<i<<" "<<x<<endl;}}}
void printvec(vector<int> v){for(auto x: v){cout<<x<<" ";}cout<<endl;}
void printmap(map<int, int> v){for(auto x: v){cout<<x.fst<<" "<<x.snd<<endl;}cout<<endl;}

int depth[MAXN];
const int K = 19;
vector<int> g[1<<19];int n;  // K such that 2^K>=n
int F[19][1<<19],D[1<<19];
void lca_dfs(int x){
    fore(i,0,g[x].size()){
        int y=g[x][i];if(y==F[0][x])continue;
        F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
    }
}
void lca_init(){
    D[0]=0;F[0][0]=-1;
    lca_dfs(0);
    fore(k,1,K)fore(x,0,n)
        if(F[k-1][x]<0)F[k][x]=-1;
        else F[k][x]=F[k-1][F[k-1][x]];
}
int lca(int x, int y){
    if(D[x]<D[y])swap(x,y);
    for(int k=K-1;k>=0;--k)if(D[x]-(1<<k)>=D[y])x=F[k][x];
    if(x==y)return x;
    for(int k=K-1;k>=0;--k)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];
    return F[0][x];
}

void dfs(int i, int t, int p){
    depth[i] = t;
    for(auto x: g[i]){
        if(x!=p){
            dfs(x,t+1,i);
        }
    }
}

bool comp(int a, int b){return depth[a]>depth[b];}

integer main(){FIN;
    int q; cin>>n>>q;
    fore(i,0,n-1){
        int a,b; cin>>a>>b; a--; b--;
        g[a].pb(b); g[b].pb(a);
    }
    dfs(0,0,-1);
    lca_init();
    while(q--){
        int k; cin>>k;
        vector<int> path;
        fore(i,0,k){int x; cin>>x; path.pb(x-1);}
        sort(ALL(path),comp);
        int node = path[0];
        bool res = 1;
        fore(i,1,k){
            int upnode = path[i];
            if(lca(node,upnode)==upnode){
                continue;
            }else{
                int br = 0;
                for(auto j:g[upnode]){
                    if(lca(node,j)==j){
                        br=1;
                        upnode = j;
                        break;
                    }
                }
                if(!br){
                    res=0;
                }
            }
            node = upnode;
        }
        if(res)cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }

    return 0;
}