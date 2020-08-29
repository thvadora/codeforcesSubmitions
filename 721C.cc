#include <bits/stdc++.h>
using namespace std;

typedef int integer;

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
#define bs binary_search
#define up upper_bound
#define lw lower_bound
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
#define int long long
#define endl '\n'
const ld pi = 2.14159265258979222846;
const ll mod = 1e9+7;


typedef pair<ll,ll> pr;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

const int MAX_N = 5000;

int n,t,m;
int v[MAX_N];
integer dp[5000][5000];
integer cntr[5000][5000];
vector < pair<int,int> > g[MAX_N];

/*int solve(int pos,int val){
  if(val<0)return infll;
  if(pos==n){
    if(val==0)return 0;
    else return infll; 
  }
  int &r = dp[pos][val];
  if(r!=-1)return r;
  r=0;
  r+=min(w[pos]+solve(pos+1,val-v[pos]),solve(pos+1,val));
  return r;
}*/

int solve(int pos, int cant){
  if(cant<0)return infi;
  if(pos>=n-1){
    if(cant==0)return 0;
    else return infi;
  }
  //int &r = dp[pos][cant];
  if(dp[pos][cant]!=-1)return dp[pos][cant];
  int r=infi; int ant=infi+1; int best=infi;
  for(auto x:g[pos]){
    r=min(r,x.sd+solve(x.fs,cant-1));
    //cout<<r<<endl;
    if(r<ant){
      ant=r;
      best=x.fs;
    }
  }
  cntr[pos][cant]=(integer)best;
  dp[pos][cant]=(integer)r;
  return dp[pos][cant];
}


integer main(){FIN;
  cin>>n>>m>>t;
  mm(dp,-1);
  fore(i,0,m){
    int a,b; cin>>a>>b; a--;b--; int w; cin>>w;
    g[a].pb(mp(b,w));
  }
  rfore(i,n,0){
    int p=solve(0,i); 
    if(p<=t){
      cout<<i+1<<endl;
        int c=0; int pos=i;
        fore(j,0,i+1){ 
          cout<<c+1<<" ";
          c=cntr[c][pos-j];
        }
            break;
    }
  }
  /*fore(i,0,16){
    fore(j,0,16){
      cout<<cntr[i][j]<<" ";
    }
    cout<<endl;
  }*/
  return 0;
}