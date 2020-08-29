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
#define endl "\n"

#define inf (1ll << 62)
                            
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

int main(){
	ll n,m,k,l; cin>>n>>m>>k>>l;
	ll res=0; 
	//ya fue, mandale binaria papu
	ll a=0,b=n/m,mid=0;
	while(a<=b){
		//cout<<"gil"<<endl;
		mid=(a+b)/2;
		if(m*mid - k >= l){
			b=mid-1;
		}else{
			a=mid+1;
			//cout<<"a: "<<a<<endl;
		}
	}
	a=min(a,n/m);
	if(m*a-k>=l)cout<<a;
	else cout<<-1;
	return 0;
}