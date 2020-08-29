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
const int MAXN = 1e6;
 
typedef pair<ll,ll> pr;
 
int gcd(int a, int b) { return b == 0 ? a : gcd(b,a%b); } 
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int fpow(int b, int e, int m=MOD){if(!e)return 1;int q=fpow(b,e/2,m);q=(q*q)%m;return e&1?(b*q)%m:q;}
void printgraph(vector <int> g[], int n){fore(i,0,n){for(auto x:g[i]){cout<<i<<" "<<x<<endl;}}}

  
int uf[MAXN];
void uf_init(){memset(uf,-1,sizeof(uf));}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
    x=uf_find(x);y=uf_find(y);
    if(x==y)return false;
    if(uf[x]>uf[y])swap(x,y);
    uf[x]+=uf[y];uf[y]=x;
    return true;
}

integer main(){FIN;
    int n; cin>>n;
    uf_init();
    vector<pr> fre;
    fore(i,0,n-1){
        int a,b; cin>>a>>b; a--;b--;
        if(uf_find(a)==uf_find(b)){
            fre.pb({a,b});
        }else{
            uf_join(a,b);
        }
    }
    int p=0; vector<pair<pr,pr> > res;
    fore(i,0,n){
        fore(j,0,n){
            if(uf_find(i)!=uf_find(j)){
                uf_join(i,j);
                res.pb({{fre[p].fst+1,fre[p].snd+1},{i+1,j+1}});
                //cout<<fre[p].fst+1<<" "<<fre[p].snd+1<<" "<<i+1<<" "<<j+1<<endl;
                p++;
            }
        }
    }
    cout<<SZ(res)<<endl;
    for(auto x:res){
        cout<<x.fst.fst<<" "<<x.fst.snd<<" "<<x.snd.fst<<" "<<x.snd.snd<<endl;
    }
    return 0;
}