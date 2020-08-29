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
map <pr,int> mpp;
pr back[MAX_N];
int bits[100][100];
vector <int> cmp[2];
int y=-1;
int finish = 0;

void dfs(int i,int type){
	if(i==y){cout<<0; finish=1;}
	visited[i]=1;
	cmp[type].pb(i);
	for(auto x:g[i]){
		if(!visited[x])dfs(x,type);
	}
}

integer main(){
	int n; cin>>n; int p=0;
	fore(i,0,n){fore(j,0,n){mpp[mp(i,j)]=p; back[p]=mp(i,j); p++;}}
	int a,b,c,d; cin>>a>>b>>c>>d; a--; b--; c--; d--;
	int i_node = mpp[mp(a,b)]; int e_node = mpp[mp(c,d)];
	fore(i,0,n){fore(j,0,n){char h; cin>>h; bits[i][j]=h-'0';}}
	pr mv[4]={mp(0,-1),mp(-1,0),mp(0,1),mp(1,0)};
	fore(i,0,n){
		fore(j,0,n){
			if(!bits[i][j]){
				fore(k,0,4){
					int nw0,nw1; nw0=i+mv[k].fst; nw1=j+mv[k].snd;
					//cout<<nw0<<" "<<nw1<<endl;
					if(nw0>=0 && nw1<n && nw1>=0 && nw0<n && !bits[nw0][nw1]){
						g[mpp[mp(i,j)]].pb(mpp[mp(nw0,nw1)]);
						//g[mpp[mp(nw0,nw1)]].pb(mpp[mp(i,j)]);
					}
				}
			}
		}
	}

	dfs(i_node,0); mm(visited,0); y=i_node; dfs(e_node,1);
	if(finish){return 0;}
	int res=infll;
	fore(i,0,SZ(cmp[0])){
		pr x = back[cmp[0][i]]; 
		fore(j,0,SZ(cmp[1])){
			pr z = back[cmp[1][j]];
			res = min(res,(x.fst-z.fst)*(x.fst-z.fst)+(x.snd-z.snd)*(x.snd-z.snd));
		}
	}
	cout<<res;
	return 0;
}