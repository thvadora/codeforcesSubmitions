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
const ll mod = 1e9+7;


typedef pair<ll,ll> pll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

const int MAX_N = 1e5+10;

pair <ll,ll> ss_(pair <ll,ll> x, pair <ll,ll> y){
	return {x.fs+y.fs,x.sd+y.sd};
}

int main(){FIN;
	int n; cin>>n;
	pair <ll,ll> a[n];
	pair <ll,ll> b[n];
	fore(i,0,n)cin>>a[i].fs>>a[i].sd;
	fore(i,0,n)cin>>b[i].fs>>b[i].sd;
	map< pair <ll,ll> , int> mpp;
	fore(i,0,n){
		fore(j,0,n){
			mpp[ss_(a[i],b[j])]++;
		}
	}
	for(auto m : mpp){
		if(m.sd == n){
			cout<<m.fs.fs<<" "<<m.fs.sd;
			break;
		}
	}
	return 0;
}