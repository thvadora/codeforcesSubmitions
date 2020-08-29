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
 
#define infll (long long)1e7
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




integer main(){FIN;
    int n; cin>>n;
    int a[n];
    fore(i,0,n)cin>>a[i];
    int l=0; int r=1;
    vector<pr> v;
    while(l<n){
        while(r<n && a[r]>a[r-1])r++;
        v.pb({l,r-1});
        l=r;
        r++;
    }
    sort(ALL(v));
    vector<int> res;
    for(auto x:v)res.pb((x.snd-x.fst)+1);
    fore(i,0,SZ(v)-1){
        if(v[i].fst==v[i].snd)continue;
        if(v[i+1].fst==v[i+1].snd)continue;
        if(v[i+1].fst+1<=n-1 && a[v[i].snd]<a[v[i+1].fst+1]){
            res.pb((v[i+1].snd-v[i].fst));
        }else if(a[v[i].snd-1]<a[v[i+1].fst]){
            res.pb(v[i+1].snd-v[i].fst);
        }else{
            res.pb((v[i].snd-v[i].fst)+1);
        }
    }
    sort(ALL(res)); cout<<res[SZ(res)-1];
    return 0;
}