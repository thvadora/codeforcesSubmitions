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
#define infi  (int)2e9
#define int long long
#define endl '\n'
const ld pi = 2.14159265258979222846;
const ll mod = 1e9+7;


typedef pair<ll,ll> pr;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

string key = "qwertyuiopasdfghjkl;zxcvbnm,./";

integer main(){
	char side; cin>>side;
	string s; cin>>s;
	string res= "";
	if(side=='R'){
		fore(i,0,SZ(s)){
			fore(j,0,SZ(key)){
				if(key[j]==s[i]){res+=key[(j-1+30)%30]; break;}
			}
		}
	}else{
		fore(i,0,SZ(s)){
			fore(j,0,SZ(key)){
				if(key[j]==s[i]){res+=key[(j+1)%30]; break;}
			}
		}
	}
	cout<<res;
	return 0;
}