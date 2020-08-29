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

#define infll 1e18
#define infi  2e9
#define pi 3.14159265359 
#define mod 1e9+7
#define eps  1e-6

typedef pair<ll,ll> pll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

vector <int> g[100001];
int tc[10001];
int v[10001];
map <int,int> mpp;

int main(){FIN;
	int n,m; cin>>n>>m;
	pair<int,int> a[n];
	fore(i,0,n){
		cin>>a[i].fs;a[i].sd=i;
		mpp[i]=a[i].fs;
	}	
	while(m--){
		int u,v; cin>>u>>v; u--;v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	ll c=0;
	sort(a,a+n);
	reverse(a,a+n);
	ll res = 0;
	fore(i,0,n){
		int node=a[i].sd;
		//cout<<"tomo nodo: "<<node<<endl;
		if(!v[node]){
			fore(j,0,SZ(g[node])){
				int vecino = g[node][j];
				if(!v[vecino]){
					//cout<<"sumo: "<<mpp[vecino]<<" del nodo: "<<vecino<<endl;
					tc[node]+=mpp[vecino];
				}
			}
				res+=tc[node];
				v[node]=1;
				//cout<<"elimino nodo: "<<a[i].sd<<endl;
		}
	}
	
	cout<<res;
	return 0;
}