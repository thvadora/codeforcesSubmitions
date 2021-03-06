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

int cr[MAXN]; // -1 if prime, some not trivial divisor if not
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,MAXN)if(cr[i]<0)for(ll j=1LL*i*i;j<MAXN;j+=i)cr[j]=i;
}

integer main(){
	int n; cin>>n;
	init_sieve();
	cr[0]=0; cr[1]=0;
	fore(i,0,n){
		int a; cin>>a;
		if((int)sqrt(a)*(int)sqrt(a) != a){cout<<"NO"<<endl;}
		else{if(cr[(int)sqrt(a)]==-1)cout<<"YES"<<endl; else cout<<"NO"<<endl;}
	}
	return 0;
}