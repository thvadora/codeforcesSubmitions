#include <bits/stdc++.h>
using namespace std;

typedef int integer;
typedef pair<long long,long long> pr;

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
#define bs binary_search
#define up upper_bound
#define lw lower_bound
#define fst first 
#define snd second 
#define mp make_pair    

#define fore(i,a,b) for(int i = a; i < b; i++)
#define rfore(i, a, b) for(ll i = a - 1; i >= b; i--)
#define forev(a,b) fore(i,0,b)cout<<a[i]<<" "; 
#define mm(a,b) memset(a , b , sizeof a) 
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())

#define infll (long long)1e7
#define INF (long long)1e15
#define infi  (int)2e9
#define int long long
#define endl '\n'

const ld pi = acos(-1);
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const int MAX_N = 2e5;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll fpow(ll b, ll e, ll m = MOD){if(!e)return 1;ll q=fpow(b,e/2,m);q=(q*q)%m;return e&1?(b*q)%m:q;}


integer main(){FIN;
	int t; cin>>t;
	while(t--){
		int x; cin>>x;
		int dp=x;
		int bk=0;
		int i=2;
		vector<int> res;
		while(bk<=(int)6e5 && SZ(res)<2){
			if(x%i==0 && find(ALL(res),i)==res.end()){
				//cout<<"meto: "<<i<<endl;
				res.pb(i);
				x/=i;
				//cout<<"x: "<<x<<endl;
				if(x<=1){
					cout<<"NO"<<endl;
					goto f;
				}
				i=2;
			}else{
				i++;
			}
			bk++;
		}
		res.pb(x);
		//cout<<"SIZE: "<<SZ(res)<<endl;
		if(SZ(res)==3 && res[0]!=res[1] && res[0]!=res[2] && res[1]!=res[2] && res[0]*res[1]*res[2]==dp){
			cout<<"YES"<<endl;
			cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<endl;
		}else{
			cout<<"NO"<<endl;
		}
		f:
		i=2;
	}
    return 0; 
}