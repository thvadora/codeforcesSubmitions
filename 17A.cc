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
const ll MAXN =3000;

typedef pair<ll,ll> pll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

int n,k;
vector <int> v;

int cr[MAXN];
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,MAXN)if(cr[i]<0)for(ll j=1LL*i*i;j<MAXN;j+=i)cr[j]=i;
}

integer main(){
	cin>>n>>k;
	init_sieve();
	fore(i,1,MAXN)if(cr[i]==-1)v.pb(i);
	/*fore(i,0,n+1)cout<<v[i]<<" ";
	cout<<endl;*/
	int res=0;
	fore(i,2,n+1){
		int num = i;
		if(cr[num]==-1){
			fore(j,1,num){
				int need = num - (v[j-1]+v[j]);
				if(need <0)break;
				if(need==1){res++; break;}
			}
		}
	}
	if(res>=k)cout<<"YES";
	else cout<<"NO";
    return 0;
}