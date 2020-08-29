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
const int MAXN = 3e5;
 
typedef pair<ll,ll> pr;
 
int gcd(int a, int b) { return b == 0 ? a : gcd(b,a%b); } 
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int fpow(int b, int e, int m=MOD){if(!e)return 1;int q=fpow(b,e/2,m);q=(q*q)%m;return e&1?(b*q)%m:q;}
void printgraph(vector <int> g[], int n){fore(i,0,n){for(auto x:g[i]){cout<<i<<" "<<x<<endl;}}}

int oper(int x, int y){
    return x+y;
}
#define NEUT 0
struct STree { // segment tree for min over integers
    vector<int> st;int n;
    STree(int n): st(4*n+5,NEUT), n(n) {}
    void init(int k, int s, int e, int *a){
        if(s+1==e){st[k]=a[s];return;}
        int m=(s+e)/2;
        init(2*k,s,m,a);init(2*k+1,m,e,a);
        st[k]=oper(st[2*k],st[2*k+1]);
    }
    void upd(int k, int s, int e, int p, int v){
        if(s+1==e){st[k]=v;return;}
        int m=(s+e)/2;
        if(p<m)upd(2*k,s,m,p,v);
        else upd(2*k+1,m,e,p,v);
        st[k]=oper(st[2*k],st[2*k+1]);
    }
    int query(int k, int s, int e, int a, int b){
        if(s>=b||e<=a)return NEUT;
        if(s>=a&&e<=b)return st[k];
        int m=(s+e)/2;
        return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
    }
    void init(int *a){init(1,0,n,a);}
    void upd(int p, int v){upd(1,0,n,p,v);}
    int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

int ft[MAXN+1];

integer main(){FIN;
    int t; cin>>t;
    while(t--){
        STree st(MAXN);
        mm(ft,0);
        int n,m; cin>>n>>m;
        int a[n]; int b[m]; 
        fore(i,0,n){
            cin>>a[i];
            ft[a[i]]=i;
        } 
        fore(i,0,m)cin>>b[i];
        int is=0;
        int ant=-1;
        int res=0;
        set<int> s;
        fore(i,0,m){
            int l=b[i];
            is=(ft[l]<=ant);
            if(is){
                st.upd(ft[l],1);
                res++;
            }else{
                //cout<<"res es: "<<res<<" pero le sumo: "<<((2*ft[l])+1)<<" y resto: "<<distance(s.begin(), s.lower_bound(ft[l]))<<endl;
                res+=((2*ft[l])+1);
                res-=(2*st.query(0,ft[l]));
                st.upd(ft[l],1);
                //cout<<res<<endl;
                ant=ft[l];
            }
        }
        cout<<res<<endl;
    }


    return 0;
}