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
#define infi  (int)2e9
#define int long long
#define endl '\n'
const ld pi = 3.14159265258979222846;
const ll mod = 1e9+7;
const ld EPS = 1e-18;


typedef pair<ll,ll> pr;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

const int MAX_N = 2e5;

vector <int> g[MAX_N];
int visited[MAX_N];

ld dfs(int i){
	visited[i]=1;
	if(SZ(g[i])==1 && i!=0)return 0.00;
	ld sum = 0.00, cnt = 0;
	for(auto x:g[i]){
		if(!visited[x])sum+=(dfs(x)), cnt++;
	}
	return (ld)(1.00+((ld)sum/(ld)cnt));
}

integer main(){
	int n; cin>>n; int m=n-1;
        if(n == 1){cout<<"0\n";exit(0);}
	while(m--){
		int a,b; cin>>a>>b; a--; b--;
		g[a].pb(b); g[b].pb(a);
	}
	printf("%.10LF\n",dfs(0));
	return 0;
}