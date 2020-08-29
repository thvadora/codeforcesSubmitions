#include <bits/stdc++.h>

using namespace std;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pb push_back
#define bs binary_search
#define ft first 
#define sd second 
#define mp make_pair    
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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
const ll maxn = 2e5+128;
ll n;
ll sp1[maxn];
int sum1(int l, int r){
	return sp1[r]-sp1[l];
}
int main(){
	cin>>n; 
	sp1[0]=0;
	ll hh[n];
	ll shh[n];
	fore(i,0,n){
		ll w,h; cin>>w>>h;
		sp1[i+1]=sp1[i]+w;
		hh[i]=h;
		shh[i]=h;
	}
	sort(shh,shh+n);
	ll max1=shh[n-1]; ll max2=shh[n-2];
	fore(i,0,n){
		ll res=0;
		res=sum1(0,i)+sum1(i+1,n);
		if(max1!=hh[i])res*=max1;
		else res*=max2;
		cout<<res<<" ";
	}

	return 0;
}