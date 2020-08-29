#include <bits/stdc++.h>
using namespace std;

typedef int integer;
typedef pair<long long,long long> pr;

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
#define INF (long long)1e15
#define infi  (int)2e9
#define int long long
#define endl '\n'

const ld pi = 3.14159265258979222846;
const ll mod = 1e9+7;
const ld EPS = 1e-10;
const int MAXN = 2e5;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll fpow(ll b, ll e, ll m = mod){if(!e)return 1;ll q=fpow(b,e/2,m);q=(q*q)%m;return e&1?(b*q)%m:q;}

int a[MAXN];

#define oper min
#define NEUT INF
struct STree { // segment tree for min over integers
	vector<int> st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void init(int k, int s, int e, int *a){
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int k, int s, int e, int p, int v){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int p, int v){upd(1,0,n,p,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);


vector<int> g[MAXN];int n;
struct edge {int u,v,comp;bool bridge;};
vector<edge> e;
void add_edge(int u, int v){
	g[u].pb(e.size());g[v].pb(e.size());
	e.pb((edge){u,v,-1,false});
}
int D[MAXN],B[MAXN],T;
int nbc;  // number of biconnected components
int art[MAXN];  // articulation point iff !=0
stack<int> st;  // only for biconnected
void dfs(int u,int pe){
	B[u]=D[u]=T++;
	for(int ne:g[u])if(ne!=pe){
		int v=e[ne].u^e[ne].v^u;
		if(D[v]<0){
			st.push(ne);dfs(v,ne);
			if(B[v]>D[u])e[ne].bridge = true; // bridge
			if(B[v]>=D[u]){
				art[u]++; // articulation
				int last; // start biconnected
				do {
					last=st.top();st.pop();
					e[last].comp=nbc;
				} while(last!=ne);
				nbc++;    // end biconnected
			}
			B[u]=min(B[u],B[v]);
		}
		else if(D[v]<D[u])st.push(ne),B[u]=min(B[u],D[v]);
	}
}
void doit(){
	memset(D,-1,sizeof(D));memset(art,0,sizeof(art));
	nbc=T=0;
	fore(i,0,n)if(D[i]<0)dfs(i,-1),art[i]--;
}


int w[MAXN];
int mapac[MAXN];
map <pr,int> mpp;
multiset <int> ml[MAXN];
int visited[MAXN];

vector<int> bct[MAXN];
int wg[MAXN],dad[MAXN],dep[MAXN]; // weight,father,depth
void dfs1(int x){
	wg[x]=1;
	for(int y:bct[x])if(y!=dad[x]){
		dad[y]=x;dep[y]=dep[x]+1;dfs1(y);
		wg[x]+=wg[y];
	}
}
int curpos,pos[MAXN],head[MAXN];
void hld(int x, int c){
	if(c<0)c=x;
	pos[x]=curpos++;head[x]=c;
	int mx=-1;
	for(int y:bct[x])if(y!=dad[x]&&(mx<0||wg[mx]<wg[y]))mx=y;
	if(mx>=0)hld(mx,c);
	for(int y:bct[x])if(y!=mx&&y!=dad[x])hld(y,-1);
}
void hld_init(){dad[0]=-1;dep[0]=0;dfs1(0);curpos=0;hld(0,-1);}
int query(int x, int y, STree& rmq){
	int r=NEUT;
	while(head[x]!=head[y]){
		if(dep[head[x]]>dep[head[y]])swap(x,y);
		r=oper(r,rmq.query(pos[head[y]],pos[y]+1));
		y=dad[head[y]];
	}
	if(dep[x]>dep[y])swap(x,y); // now x is lca
	r=oper(r,rmq.query(pos[x],pos[y]+1));
	if(x<nbc && x!=0){
		r=oper(r,rmq.query(pos[dad[x]],pos[dad[x]]+1));
	}
	return r;
}
// for updating: rmq.upd(pos[x],v);
// queries on edges: - assign values of edges to "child" node
//                   - change pos[x] to pos[x]+1 in query (line 28)

integer main(){FIN;
	int m,q; cin>>n>>m>>q;
	mm(mapac,-1);
	fore(i,0,n)cin>>w[i];
	fore(i,0,m){
		int a,b; cin>>a>>b; a--; b--;
		add_edge(a,b);
	}
	doit();
	for(auto x:e){
		if(!art[x.u])mapac[x.u]=x.comp;
		if(!art[x.v])mapac[x.v]=x.comp;
	}
	int nw = nbc;
	fore(i,0,n){
		if(art[i]){
			mapac[i]=nw++;
			for(auto x:g[i]){
				int v=e[x].u^e[x].v^i;
				bct[mapac[i]].pb(e[x].comp);
				bct[e[x].comp].pb(mapac[i]);
			}
		}
	}
	fore(i,0,n){
		sort(ALL(bct[i]));
		bct[i].erase(unique(ALL(bct[i])),bct[i].end());
	}
	hld_init();
	fore(i,0,n){
		ml[mapac[i]].insert(w[i]);
		if(mapac[i]>=nbc){
			ml[dad[mapac[i]]].insert(w[i]);
		}
	}
	STree st(nw); st.init(a);
	fore(i,0,nw){
		st.upd(pos[i],*ml[i].begin());
		/*if(i>=nbc){
			ml[dad[i]].insert(*ml[i].begin());
			st.upd(pos[dad[i]],*ml[i].begin());
		}*/
	}
	/*fore(i,0,nw){
		for(auto x:bct[i]){
			cout<<i<<" "<<x<<endl;
		}
	}
	fore(i,0,nw){
		cout<<"componente "<<i<<endl;
		for(auto x:ml[i]){
			cout<<x<<endl;
		}
	}
	cout<<endl;
	cout<<"seg tree"<<endl;
	fore(i,0,nw){
		cout<<st.query(pos[i],pos[i]+1)<<" ";
	}
	cout<<endl<<endl;*/
	fore(i,0,q){
		char type; cin>>type;
		if(type=='C'){
			int a,b; cin>>a>>b; a--;
			int mp = 0;
			mp = mapac[a];
			//cout<<mp<<endl;
			ml[mp].erase(ml[mp].find(w[a]));
			ml[mp].insert(b);
			st.upd(pos[mp],*ml[mp].begin());
			if(mp>=nbc){
				//cout<<"gil"<<endl;
				ml[dad[mp]].erase(ml[dad[mp]].find(w[a]));
				ml[dad[mp]].insert(b);
				st.upd(pos[dad[mp]],*ml[dad[mp]].begin());
			}
			w[a]=b;
			/*cout<<"seg tree"<<endl;
			fore(i,0,nw){
				cout<<st.query(pos[i],pos[i]+1)<<" ";
			}
			cout<<endl<<endl;
			fore(i,0,nw){
				cout<<"componente "<<i<<endl;
				for(auto x:ml[i]){
					cout<<x<<endl;
				}
			}
			cout<<endl;*/
		}else{
			int a,b; cin>>a>>b; a--; b--;
			if(a==b){
				cout<<w[a]<<endl;
				continue;
			}
			a = mapac[a]; b = mapac[b];
			/*cout<<a<<" "<<b<<endl;
			cout<<pos[a]<<" "<<pos[b]<<endl;*/
			cout<<query(a,b,st)<<endl;
		}
	}
    return 0;
}