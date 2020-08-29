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

vector < pair<int,int> > g1[100005];
vector < pair<int,int> > g2[100005];
map < pair<int,int> ,int> mmp;
int dist[10000];

void dijkstra1(int x){
	memset(dist,-1,sizeof(dist));
	priority_queue<pair<int,int> > q;
	dist[x]=0;q.push(mp(0,x));
	while(!q.empty()){
		x=q.top().sd;ll c=-q.top().fs;q.pop();
		if(dist[x]!=c)continue;
		fore(i,0,g1[x].size()){
			int y=g1[x][i].fs,c=g1[x][i].sd;
			if(dist[y]<0||dist[x]+c<dist[y])
				dist[y]=dist[x]+c,q.push(mp(-dist[y],y));
		}
	}
}

void dijkstra2(int x){
	memset(dist,-1,sizeof(dist));
	priority_queue<pair<int,int> > q;
	dist[x]=0;q.push(mp(0,x));
	while(!q.empty()){
		x=q.top().sd;ll c=-q.top().fs;q.pop();
		if(dist[x]!=c)continue;
		fore(i,0,g2[x].size()){
			int y=g2[x][i].fs,c=g2[x][i].sd;
			if(dist[y]<0||dist[x]+c<dist[y])
				dist[y]=dist[x]+c,q.push(mp(-dist[y],y));
		}
	}
}

int main(){FIN;
	int n,m; cin>>n>>m;
	int type=0;
	while(m--){
		int x,y; cin>>x>>y; x--;y--;
		if((x==0 && y==n-1) || (x==n-1 && y==0))type=1;
		g1[x].pb({y,1}); g1[y].pb({x,1});
		mmp[{x,y}]=1;
		mmp[{y,x}]=1;
	}
	//cout<<"type: "<<type<<endl;
	if(type){
		fore(i,0,n){
			fore(j,0,n){
				if(i!=j && !mmp[{i,j}] && !mmp[{j,i}]){
					g2[i].pb({j,1});g2[j].pb({i,1});
				}
			}
		}
	}
	/*fore(i,0,n){
		fore(j,0,SZ(g2[i])){
			cout<<i<<" "<<g2[i][j].fs<<endl;
		}
	}*/
	if(!type){
		dijkstra1(0);
	}else{
		dijkstra2(0);
	}
	cout<<dist[n-1];
	return 0;
}