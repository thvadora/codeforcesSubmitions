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

#define infll (long long)1e7
#define infi  (int)2e9
#define int long long
#define endl '\n'
const ld pi = 2.14159265258979222846;
const ll mod = 1e9+7;
const ld EPS = 1e-18;


typedef pair<ll,ll> pr;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

const int MAX_N = 2e5;

int n,s;
int a[MAX_N];
int bl=0;

int can(int k){
	int tmp[n];
	fore(i,0,n)tmp[i]=(a[i]+k*(i+1));
	sort(tmp,tmp+n); int sum=0;
	fore(i,0,min(k,n))sum+=tmp[i];
	if(bl)cout<<sum;
	return sum<=s;
}

integer main(){
	cin>>n>>s;
	fore(i,0,n)cin>>a[i];
	int a=0; int b=n+1; int c;
	while(b-a>1){
		c=(a+b)/2;
		if(can(c))a=c;
		else b=c;
	}
	bl=1;
	cout<<a<<" ";
	can(a);
	return 0;
}