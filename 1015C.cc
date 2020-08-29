#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pb push_back
#define bs binary_search
#define fs first 
#define sd second 
#define mk make_pair    
#define mt make_tuple

#define fore(i,a,b) for(ll i = a; i < b; i++)
#define rfore(i, a, b) for(ll i = a - 1; i >= b; i--)
#define mm(a,b) memset(a , b , sizeof a) 
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())
#define V(a) vector <a> 
#define P(a,b) pair<a,b>
#define M(a,b) map<a,b> 
#define S(a) set<a>

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll a[n],b[n],compress[n]; 
	ll asum=0,bsum=0; 
	for (ll i = 0; i < n; ++i){
		cin>>a[i]>>b[i];
		asum+=a[i]; bsum+=b[i];
		compress[i]=a[i]-b[i];
	}
	if(asum<=m){cout<<0; return 0;}
	if(bsum>m){cout<<-1; return 0;}
	sort(compress,compress+n);
	ll t=n-1; ll songs=0;
	while(asum>m){
		asum-=compress[t];
		t--; 
		songs++;
	}
	cout<<songs;
	return 0;
}