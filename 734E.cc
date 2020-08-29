#include <bits/stdc++.h>
using namespace std;

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
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
#define All(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())

#define infll 1e17
#define infi  2e9
const ld pi = 3.14159265358979323846;
const ll mod = 1e9+7;


typedef pair<ll,ll> pii;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

const ll MAX_N = 2e5+100;

vector <int> g[MAX_N];
vector <int> leaf;
int visited[MAX_N];
int c[MAX_N];
int depth=0;
int ch;
void dfs(int i,int d){
    if(d>depth){
        ch=i; depth=d;
    }
    visited[i]=1;
    for(auto x:g[i])if(!visited[x])dfs(x,d+(c[i]!=c[x]));
}

int main(){
    int n; cin>>n;
    fore(i,0,n)cin>>c[i];
    fore(i,0,n-1){
        int x,y; cin>>x>>y; x--;y--;
        g[x].pb(y); g[y].pb(x);
    }
    dfs(0,1); 
    mm(visited,0);
    dfs(ch,1);
    cout<<depth/2;
	return 0;
}