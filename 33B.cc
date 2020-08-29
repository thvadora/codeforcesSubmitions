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

#define infi  2e9
#define int long long
#define endl '\n'
const ld pi = 3.14159265358979323846;
const ll mod = 1e9+7;
const ll INF = 1e10;
const ll MAXN =1000;

typedef pair<ll,ll> pll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

ll g[MAXN][MAXN];int n;int cant=0; 
void floyd(){ // O(n^3) . Replaces g with min distances
    fore(k,0,cant)fore(i,0,cant)if(g[i][k]<INF)fore(j,0,cant)if(g[k][j]<INF)
        g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}


integer main(){
    string s,t; cin>>s>>t;
    if(SZ(s)!=SZ(t)){cout<<-1; return 0;}
    int len=SZ(s);
    cin>>n;
    fore(i,0,1000)fore(j,0,1000)g[i][j]=INF;
    fore(i,0,1000)g[i][i]=0;
    map<char,int>abc;
    for(char i='a';i<='z';i++)abc[i]=cant,cant++;
    fore(i,0,n){
        char a,b; cin>>a>>b; int w; cin>>w;
        g[abc[a]][abc[b]]=min(g[abc[a]][abc[b]],w);
    }
    floyd();
   // fore(i,0,cant){fore(j,0,cant){if(g[i][j]!=INF)cout<<g[i][j]<<" ";else cout<<"INF"<<" ";}cout<<endl;}
    int cost=0; char add; string res="";
    fore(i,0,len){
        //if(s[i]==t[i])continue;
        char x,y; x=s[i]; y=t[i];
       	int mn=INF;
       	for(char j='a';j<='z';j++){
       		int c = g[abc[x]][abc[j]]+g[abc[y]][abc[j]];
       		//cout<<"intentando cambiar: "<<x<<" y "<<y<<" por: "<<j<<" con costo: "<<c<<endl;
       		//mn=min(mn,c);
       		if(c<mn){
       			mn=c;
       			add=j;
       		}
       	}
       	//cout<<mn<<endl;
       	res+=add;
       	if(mn>=INF){cout<<-1; return 0;}
       	cost+=mn;
    }
    cout<<cost<<endl;
    cout<<res;
    return 0;
}