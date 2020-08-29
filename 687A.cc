#include <bits/stdc++.h>

using namespace std;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pb push_back
#define bs binary_search
#define fs first 
#define sd second 
#define mp make_pair    
#define mt make_tuple

#define fore(i,a,b) for(ll i = a; i < b; i++)
#define rfore(i, a, b) for(ll i = a - 1; i >= b; i--)
#define forev(a,b) fore(i,0,b)cout<<a[i]<<" "; 
#define mm(a,b) memset(a , b , sizeof a) 
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())
#define V(a) vector <a> 
#define P(a,b) pair<a,b>
#define M(a,b) map<a,b> 
#define S(a) set<a>
#define endl "\n"

#define inf (1ll << 62)
                            
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

int flag=1;
vector <int> g[100001]; // <node,color>
int visited1[100001];
int color[100001]; // 1 o 2
vector <int> color1; vector <int> color2;

void dfs1(int i, int cc){
	visited1[i]=1; color[i]=cc;
	if(cc==1)color1.pb(i);
	else color2.pb(i);
	for(auto x : g[i]){
		if(!visited1[x])dfs1(x,(cc==1 ? 2 : 1));
	}
}

int main(){
	int n,m; cin>>n>>m;
	vector < pair<int,int> > v;
	int maxx=0;
	while(m--){
		int x,y; cin>>x>>y; x--;y--;
		v.pb(mp(x,y)); maxx=max(maxx,x); maxx=max(maxx,y);
		g[x].pb(y); g[y].pb(x);
	}
	fore(i,0,maxx)if(!visited1[i])dfs1(i,1);
	fore(i,0,SZ(v)){
		if(color[v[i].fs]==color[v[i].sd]){
			cout<<-1; return 0;
		}
	}
	cout<<SZ(color1)<<endl;
	fore(i,0,SZ(color1)) cout<<color1[i]+1<<" ";
	cout<<endl;
	cout<<SZ(color2)<<endl;
	fore(i,0,SZ(color2)) cout<<color2[i]+1<<" ";
	return 0;
}