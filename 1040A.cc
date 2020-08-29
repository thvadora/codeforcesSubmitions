#include <bits/stdc++.h>

using namespace std;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pb push_back
#define bs binary_search
#define fs first 
#define sd second 
#define mp make_pair    
#define mt make_tuple

#define fore(i,a,b) for(ll i = a; i < b; i++)
#define rfore(i, a, b) for(ll i = a - 1; i >= b; i--)
#define forev(a,b) fore(i,0,b)cout<<a[i]<<" "; 
#define mm(a,b) memset(a , b , sizeof a) 
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())
#define V(a) vector <a> 
#define P(a,b) pair<a,b>
#define M(a,b) map<a,b> 
#define S(a) set<a>

#define inf (1ll << 62)
                            
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

int main(){FIN;
	int n,a,b; cin>>n>>a>>b;
	int ar[n];
	fore(i,0,n)cin>>ar[i];
	int i,j; i=0; j=n-1;
	int res=0;
	while(i<j){
		if(ar[i]!=ar[j] || (ar[i]==2 && ar[j]==2)){
			if(ar[i]==1&&ar[j]==0){cout<<-1; return 0;}
			else if(ar[i]==0&&ar[j]==1){cout<<-1; return 0;}
			else if(ar[i]==1 || ar[j]==1)res+=b;
			else if(ar[i]==0 || ar[j]==0)res+=a;
			else res+=2*min(a,b);
		}
		i++; j--;
	}
	if(n%2!=0){
		if(ar[i]!=0 && ar[i]!=1)res+=min(a,b);
	}
	cout<<res;
	return 0;
}