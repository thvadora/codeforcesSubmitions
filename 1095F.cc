#include <bits/stdc++.h>
using namespace std;

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define bs binary_search
#define up upper_bound
#define fs first 
#define sd second 
#define mp make_pair    

#define fore(i,a,b) for(ll i = a; i < b; i++)
#define rfore(i, a, b) for(ll i = a - 1; i >= b; i--)
#define forev(a,b) fore(i,0,b)cout<<a[i]<<" "; 
#define mm(a,b) memset(a , b , sizeof a) 
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())

#define infll 1e17
#define infi  2e9
#define pi 3.14159265359 
const ll mod = 1e9+7;


typedef pair<ll,ll> pll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

#define MAXN 200005

ll uf[MAXN];
void uf_init(){memset(uf,-1,sizeof(uf));}
ll uf_find(ll x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(ll x, ll y){
        x=uf_find(x);y=uf_find(y);
        if(x==y)return false;
        if(uf[x]>uf[y])swap(x,y);
        uf[x]+=uf[y];uf[y]=x;
        return true;
}
vector<pair<ll,pair<ll,ll> > > es; // edges (cost,(u,v))
pll a[200005];
ll n,m;

ll kruskal(){  // assumes graph is connected

    sort(es.begin(),es.end());uf_init();
    ll r=0;
    fore(i,0,es.size()){
        ll x=es[i].sd.fs,y=es[i].sd.sd;
        if(uf_join(x,y)){
            r+=es[i].fs; // (x,y,c) belongs to mst
            
        }
        if(n == 1)return r;
    }
    return r; // total cost
}




int main(){
    FIN;

    cin>>n>>m;
    fore(i,0,n){
        ll p;
        cin>>p;
        a[i] = {p,i+1};
    }
    sort(a,a+n);
    fore(i,1,n){
        es.pb({a[i].fs+a[0].fs,{a[i].sd,a[0].sd}});
    }

    fore(i,0,m){
        ll u,v,c;cin>>u>>v>>c;
        es.pb({c,{u,v}});
    }
    cout<<kruskal();

    return 0;
}