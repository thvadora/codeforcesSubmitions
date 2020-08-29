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

int n;
int p[MAXN];
int c[MAXN];
int f = -1;
vector<int> loops[MAXN];
int visited[MAXN];


void vis(int i, int t){
    if(visited[i]>-1)return;
    visited[i] = t;
    loops[t].pb(i);
    vis(p[i], t);
}

bool can(int k, vector<int> lp){
    fore(_,0,k){
        int res=1;
        int color = c[lp[_]];
        int i = _;
        int v = 0;
        int nn = SZ(lp);
        while(v<nn){
            res&=(color==c[lp[i%nn]]);
            if(!res)break;
            i+=k;
            v++;
        }
        if(res)return res;
    }
    return false;
}

integer main(){FIN;
    int t; cin>>t;
    while(t--){
        mm(visited,-1);
        mm(c,0);
        fore(i,0,f)loops[i].clear();
        f = 0;
        cin>>n;
        fore(i,0,n)cin>>p[i];
        fore(i,0,n)cin>>c[i];
        fore(i,0,n)p[i]--;
        fore(i,0,n){
            if(visited[i]>=0)continue;
            vis(p[i],f);
            f++;
        }
        //printgraph(loops, f);
        int res = infll;
        int listo = 0;
        fore(i,0,f){
            listo=0;
            fore(j,1,SZ(loops[i])+1){
                if(SZ(loops[i])%j)continue;
                //cout<<"loop: "<<i<<" -> can? : "<<endl;
                //cout<<can(j, loops[i])<<endl;
                if(can(j, loops[i])){
                    res = min(res,j);
                    break;
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}