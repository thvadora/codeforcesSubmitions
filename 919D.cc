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
#define fst first 
#define snd second 
#define mp make_pair    

#define fore(i,a,b) for(ll i = a; i < b; i++)
#define rfore(i, a, b) for(ll i = a - 1; i >= b; i--)
#define forev(a,b) fore(i,0,b)cout<<a[i]<<" "; 
#define mm(a,b) memset(a , b , sizeof a) 
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())

#define infll (long long)1e7
#define INF (long long)1e13
#define infi  (int)2e9
#define int long long
#define endl '\n'
const ld pi = 3.14159265258979222846;
const ll mod = 1e8;
const ld EPS = 1e-18;
const int MAX_N = 3e5+100;


typedef pair<ll,ll> pr;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

int n,m; 
vector <int> g[MAX_N];
string val;

bool tsort(){ 
  vector<int> r;priority_queue<int> q;
  vector<int> d(2*n,0);
  fore(i,0,n)fore(j,0,g[i].size())d[g[i][j]]++;
  fore(i,0,n)if(!d[i])q.push(-i);
  while(!q.empty()){
    int x=-q.top();q.pop();r.pb(x);
    fore(i,0,g[x].size()){
      d[g[x][i]]--;
      if(!d[g[x][i]])q.push(-g[x][i]);
    }
  }
  return r.size()<n;  
}

int dp[MAX_N][27];

int solve(int node, int let){
  if(SZ(g[node])==0)return (val[node]-'a'==let);
  int &r = dp[node][let];
  if(r!=-1)return r;
  r = 0;
  for(auto x:g[node]){
    r = max(r,(val[node]-'a'==let)+solve(x,let));
  }
  return r;
}

integer main(){
    mm(dp,-1);
    cin>>n>>m;
    cin>>val;
    while(m--){
      int a,b; cin>>a>>b; a--; b--;
      g[a].pb(b);
    }
    if(tsort()){
      cout<<-1;
      return 0;
    }
    int res = 0;
    fore(i,0,27){
      fore(j,0,n)res = max(res,solve(j,i));
    }
    cout<<res;
    return 0;
}