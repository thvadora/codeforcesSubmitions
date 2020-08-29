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

vector <int> g[100001];

int main(){FIN;
	int n,d,h; cin>>n>>d>>h;
	int l=0;
	int lst=0;
	fore(i,1,h+1){
		g[i].pb(i+1);
		lst = i;
		l=i+1;	
	}
	l++;
	int rnod = n-(h+1);
	//cout<<rnod<<endl;
	if((rnod<(d-h) || (d-h)>h) && (d-h)!=0){cout<<-1<<endl;return 0;}
	int p=l;
	if(d-h != 0){
		g[1].pb(l);
		fore(i,l,l+(d-h)-1){
			g[i].pb(i+1);
			p=i+1;
		}
		p++;
		rnod = rnod-((d-h));
	}
	if(lst==1 && (d-h)==0 && n>2){cout<<-1<<endl;return 0;}
	fore(i,p,p+rnod){
		g[lst].pb(i);
	}
	rnod-=rnod;
	if(rnod==0){	
		fore(i,1,n+1){
			fore(j,0,SZ(g[i])){
				cout<<i<<" "<<g[i][j]<<endl;
			}
		}
	}
	return 0;
}