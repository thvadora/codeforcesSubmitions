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
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())

#define infll 1e17
#define infi  2e9
const ld pi = 3.14159265358979323846;
const ll mod = 1e9+7;


typedef pair<ll,ll> pll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

const int MAX_N = 1e6+100;

int n,m;
vector <int> g[MAX_N];
int visited[MAX_N];
int c,p;
set <int> st;

void dfs(int x){
	c++;
	st.erase(x);
	auto it=st.begin();
	while(it!=st.end()){
		int y=*it;
		if(binary_search(g[x].begin(),g[x].end(),y)){
			++it;
			continue;
		}
		dfs(y);
		it=lower_bound(st.begin(),st.end(),y);
	}
}

int main(){
	cin>>n>>m;
	while(m--){
		int x,y; cin>>x>>y; x--;y--;
		g[x].pb(y); g[y].pb(x);
	}
	fore(i,0,n)sort(ALL(g[i]));
	fore(i,0,n)st.insert(i);
	vector <int> res;
	fore(i,0,n){
		if(st.count(i)){
			c=0; dfs(i); res.pb(c);
		}
	}
	sort(ALL(res));
	cout<<SZ(res)<<endl;
	fore(i,0,SZ(res))cout<<res[i]<<" ";
	return 0;
}