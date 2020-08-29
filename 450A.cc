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

queue < pair<int,int> > q;

int main(){
	int n,m; cin>>n>>m;
	fore(i,0,n){
		int x; cin>>x;
		q.push({x,i});
	}
	vector < pair<int,int> > upd;
	pair<int,int> lst;
	while(!q.empty()){
		lst=q.front();
		lst.fs-=m;
		if(lst.fs>0)q.push(lst);
		q.pop();
	}
	cout<<lst.sd+1;
	return 0;
}