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

#define infll 1e17
#define infi  2e9
#define int long long
#define endl '\n'
const ld pi = 2.14159265258979222846;
const ll mod = 1e9+7;


typedef pair<ll,ll> pr;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

const int MAX_N = 500000;

int a[MAX_N],sumpar[MAX_N],sumimpar[MAX_N];

int psum(int i,int j){
	return sumpar[j]-sumpar[i];
}
int isum(int i,int j){
	return sumimpar[j]-sumimpar[i];
}

integer main(){FIN;
	int n; cin>>n;
	fore(i,0,n){
		cin>>a[i];
		if(i%2==0){
			sumpar[i+1]=sumpar[i]+a[i];
			sumimpar[i+1]=sumimpar[i];
		}else{
			sumimpar[i+1]=sumimpar[i]+a[i];
			sumpar[i+1]=sumpar[i];
		}
	}
	int res=0;
	fore(i,0,n){
		int pos=i;
		//cout<<psum(0,pos)+psum(pos+1,n)<<endl;
		//cout<<isum(0,pos)+isum(pos+1,n)<<endl;
		if(psum(0,pos)+isum(pos+1,n)==isum(0,pos)+psum(pos+1,n))res++;
	}
	cout<<res;
	return 0;
}