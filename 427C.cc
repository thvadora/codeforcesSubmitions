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
const ll mod = 1e9+7;


typedef pair<ll,ll> pll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

ll c[100001];
const int MAX_N = 1e5;
stack <int> s;
vector <int> a[MAX_N], rev[MAX_N], comp[MAX_N];
int visited[MAX_N], am, n, m;

void dfs(int pos){
  visited[pos] = true;
  for(int x : a[pos]){
    if(!visited[x]){
      dfs(x);
    }
  }
  s.push(pos);
}

void dfs1(int i, int pos){
  visited[pos] = true;
  comp[i].push_back(pos);
  for(int x : rev[pos]){
    if(!visited[x]){
      dfs1(i, x);
    }
  }
}

void scc(){   // returns "am" vectors containing scc
  int i;
  for(i = 0; i < n; i++){
    if(!visited[i]){
      dfs(i);
    }
  }
  memset(visited, 0, sizeof(visited));
  while(s.size()){
    int x = s.top();
    s.pop();
    if(!visited[x]){
      dfs1(am, x);
      am++;
    }
  }
}


int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>c[i];	
	cin>>m;
	fore(i,0,m){
		int x,y; cin>>x>>y; x--;y--;
		a[x].pb(y);
    rev[y].pb(x);
	}
	scc();
  vector < pair<ll,ll> > res;
	fore(i,0,am){
    ll curmin=infll;
    int cant = 0;
		fore(j,0,SZ(comp[i]))curmin=min(curmin,c[comp[i][j]]);
    fore(j,0,SZ(comp[i]))if(c[comp[i][j]]==curmin)cant++;
    res.pb(mp(curmin,cant));
	}
  ll res0=0,res1=1;
	fore(i,0,SZ(res)){
    res0+=res[i].fs;
    res1 = (res1*res[i].sd)%mod;
  }
  cout<<res0<<" "<<res1;
	return 0;
}