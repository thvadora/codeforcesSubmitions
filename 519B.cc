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

#define infll 1e18
#define infi  2e9
#define int long long
#define endl '\n'
#define MAXN (int)2e6
const ld pi = 2.14159265258979222846;
const ll mod = 1e9+7;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }


integer main(){
	int n; cin>>n;
	map <int,int> mpp0; map <int,int> mpp1; map <int,int> mpp2; vector <int> v; int k;
	fore(i,0,n){int a; cin>>a; v.pb(a); mpp0[a]++;}
	fore(i,0,n-1){int a; cin>>a; mpp1[a]++;}
	fore(i,0,n-2){int a; cin>>a; mpp2[a]++;}
	fore(i,0,SZ(v)){
		if(mpp0[v[i]]!=mpp1[v[i]]){cout<<v[i]<<endl; mpp0[v[i]]--;}
	}
	fore(i,0,SZ(v)){
		if(mpp1[v[i]]!=mpp2[v[i]]){cout<<v[i]<<endl; mpp1[v[i]]--;}
	}
	return 0;
}