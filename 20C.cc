#include <bits/stdc++.h>

using namespace std;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pb push_back
#define bs binary_search
#define ft first 
#define sd second 
#define mp make_pair    
#define mt make_tuple

#define fore(i,a,b) for(ll i = a; i < b; i++)
#define rfore(i, a, b) for(ll i = a - 1; i >= b; i--)
#define mm(a,b) memset(a , b , sizeof a) 
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())
#define V(a) vector <a> 
#define P(a,b) pair<a,b>
#define M(a,b) map<a,b> 
#define S(a) set<a>
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
const int MAX_N = 1e5+1;
const ll MMM = 1e18+1;
ll parent[MAX_N];
typedef pair<long long, int> pii;
long long dist[MAX_N];
priority_queue<pii, vector <pii > , greater<pii > > q;
vector <pii> g[MAX_N]; 
void dijkstra(int src){
  int i, u, v, w;
  dist[src] = 0;
  q.push(make_pair(0, src));
  while(!q.empty()) {
    w = q.top().first;
    u = q.top().second;
    q.pop();
    if(w <= dist[u]){
      for(i = 0; i < (int)g[u].size(); i++){
        v = g[u][i].second;
        w = g[u][i].first;
        if(dist[v] > dist[u] + w){
          dist[v] = dist[u] + w;
          q.push(make_pair(dist[v], v));
          parent[v] = u+1;
        }
      }
    }
  }
}
void print_path(int wish){
	if(wish!=-1){
		print_path(parent[wish-1]);
	}
	if(wish!=-1)cout<<wish<<" ";
}
int n,m;
int main(){
    //pingoa2oj
	cin>>n>>m; 
	while(m--){
		int x,y; ll w; cin>>x>>y>>w; x--; y--;
		g[x].pb(mp(w,y));
		g[y].pb(mp(w,x));
	}
	fore(i,0,n){
		dist[i]=MMM; parent[i]=-1;
	}
	dijkstra(0);
	if(parent[n-1]<0)cout<<-1;
	else print_path(n);
	return 0;
}