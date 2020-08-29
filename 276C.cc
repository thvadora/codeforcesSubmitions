#include <bits/stdc++.h>
using namespace std;

typedef int integer;

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define pb push_baceach
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
int seg[MAX_N];

#define NEUTRO 0
int oper(int x,int y){
    return x+y;
}
struct STree { // example: range sum with range addition
    vector<int> st,lazy;int n;
    STree(int n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
    void init(int k, int s, int e, int *a){
        lazy[k]=0;  // lazy neutral element
        if(s+1==e){st[k]=a[s];return;}
        int m=(s+e)/2;
        init(2*k,s,m,a);init(2*k+1,m,e,a);
        st[k]=oper(st[2*k],st[2*k+1]); // operation
    }
    void push(int k, int s, int e){
        if(!lazy[k])return; // if neutral, nothing to do
        st[k]+=(e-s)*lazy[k]; // update st according to lazy
        if(s+1<e){ // propagate to children
            lazy[2*k]+=lazy[k];
            lazy[2*k+1]+=lazy[k];
        }
        lazy[k]=0; // clear node lazy
    }
    void upd(int k, int s, int e, int a, int b, int v){
        push(k,s,e);
        if(s>=b||e<=a)return;
        if(s>=a&&e<=b){
            lazy[k]+=v; // accumulate lazy
            push(k,s,e);return;
        }
        int m=(s+e)/2;
        upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
        st[k]=oper(st[2*k],st[2*k+1]); // operation
    }
    int query(int k, int s, int e, int a, int b){
        if(s>=b||e<=a)return NEUTRO; // operation neutral
        push(k,s,e);
        if(s>=a&&e<=b)return st[k];
        int m=(s+e)/2;
        return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b)); // operation
    }
    void init(int *a){init(1,0,n,a);}
    void upd(int a, int b, int v){upd(1,0,n,a,b,v);}
    int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);


integer main(){
    int n,q; integer n0,q0; scanf("%d %d",&n0,&q0);
    n=n0; q=q0;
    int a[n];
    fore(i,0,n){
        integer a0; scanf("%d",&a0);
        a[i]=a0;
    }
    STree st(n+1); st.init(seg);
    while(q--){
        integer l,r; scanf("%d %d",&l,&r); l--;
        st.upd(l,r,1);
    }
    int ac[n+1];
    fore(i,0,n){
        ac[i]=st.query(i,i+1);
    }
    sort(ac,ac+n); reverse(ac,ac+n);
    sort(a,a+n); reverse(a,a+n);
    ll res=0;
    fore(i,0,n){
        res+=(a[i]*ac[i]);
    }
    cout<<res;
	return 0;
}