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

const int MAX_N = 1e5+200;
int n,m;
ll c[MAX_N];
int vis[MAX_N];
vector <int> g[MAX_N];
map <int,int> mpp;
map <int,int> mpp2;
ll res[MAX_N];
set <int> p[MAX_N];


int main(){FIN;
	cin>>n>>m;
  ll maxcolor = 0;
	fore(i,0,n){
    cin>>c[i];
    mpp2[c[i]]=1;
    mpp[i]=c[i];
    maxcolor = max(maxcolor,c[i]);
  }
	fore(i,0,m){
		int x,y; cin>>x>>y; x--;y--;
		g[x].pb(y);
    g[y].pb(x);
	}
  fore(i,0,n){
      fore(j,0,SZ(g[i])){
      if(c[g[i][j]]!=c[i]){
        p[mpp[i]].insert(c[g[i][j]]);
      }
    }
  }
  int mn=-1; int pos=0;
  fore(i,0,maxcolor+1){
    if(SZ(p[i])>mn && mpp2[i]==1){
      pos=i;
      mn=SZ(p[i]);
    }
  }
  cout<<pos<<endl;
	return 0;
}