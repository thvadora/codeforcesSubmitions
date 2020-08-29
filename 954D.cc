#include <bits/stdc++.h>
using namespace std;

typedef int integer;

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
#define bs binary_search

#define fst first 
#define snd second 
#define mp make_pair    

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
#define EPS 1e-9
#define NIL -1
const ld pi = 3.14159265258979222846;
const ll mod = 1e9+7;


typedef pair<ll,ll> pr;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

const int MAXN = 200000;

int n,m,s,t;

vector<pair<int,int> > g[MAXN];  // u->[(v,cost)]
ll dist[MAXN];
int ds[MAXN]; int dt[MAXN];

void dijkstra(int x){
    memset(dist,-1,sizeof(dist));
    priority_queue<pair<ll,int> > q;
    dist[x]=0;q.push(mp(0,x));
    while(!q.empty()){
        x=q.top().snd;ll c=-q.top().fst;q.pop();
        if(dist[x]!=c)continue;
        fore(i,0,g[x].size()){
            int y=g[x][i].fst,c=g[x][i].snd;
            if(dist[y]<0||dist[x]+c<dist[y])
                dist[y]=dist[x]+c,q.push(mp(-dist[y],y));
        }
    }
}

map <pr,int> mpp;

integer main(){FIN;
    cin>>n>>m>>s>>t; s--; t--;
    fore(i,0,m){
        int a,b; cin>>a>>b; a--;b--;
        g[a].pb(mp(b,1)); g[b].pb(mp(a,1));
        mpp[mp(a,b)]=1; mpp[mp(b,a)]=1;
    }
    dijkstra(s); fore(i,0,n)ds[i]=dist[i]; dijkstra(t); fore(i,0,n)dt[i]=dist[i];
    /*fore(i,0,n)cout<<ds[i]<<" ";
    cout<<endl;
    fore(i,0,n)cout<<dt[i]<<" ";*/
    int min_cost = ds[t]; int res=0;
    fore(i,0,n){
        fore(j,0,n){
            if(!mpp[mp(i,j)] && (i!=j)){
                if(!(ds[i]+dt[j]+1<min_cost || ds[j]+dt[i]+1<min_cost))res++;
            }
        }
    }
    cout<<res/2;
	return 0;
}