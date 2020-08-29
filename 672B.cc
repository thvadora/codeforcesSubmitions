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
	int n; string s; cin>>n>>s;
	int abc=26; int eq=0;
	map <char,int> m;
	fore(i,0,SZ(s)){
		if(m[s[i]]==0)abc--;
		else eq++;
		m[s[i]]++;
	}
	if(abc>=eq)cout<<eq;
	else cout<<-1;
	return 0;
}