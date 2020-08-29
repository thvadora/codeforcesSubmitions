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
#define fst first 
#define snd second 
#define mp make_pair    

#define fore(i,a,b) for(ll i = a; i < b; i++)
#define rfore(i, a, b) for(ll i = a - 1; i >= b; i--)
#define forev(a,b) fore(i,0,b)cout<<a[i]<<" "; 
#define mm(a,b) memset(a , b , sizeof a) 
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())

#define infll (long long)1e7
#define INF (long long)1e7
#define infi  (int)2e9
#define int long long
#define endl '\n'
const ld pi = 3.14159265258979222846;
const ll mod = 1e8;
const ld EPS = 1e-18;


typedef pair<ll,ll> pr;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
const int MAX_N = 1e4+5;

set<int> v[40];


integer main(){
    string s; cin>>s;
    fore(i,0,SZ(s)){
    	int p = s[i]-'a';
    	v[p].insert(i);
    }
  	int q; cin>>q;
  	while(q--){
  		int t; cin>>t;
  		if(t==1){
  			int pos; char c; cin>>pos>>c; pos--;
  			fore(i,0,26){
  				if(v[i].find(pos)!=v[i].end()){
  					v[i].erase(v[i].find(pos));
  					break;
  				}
  			}
  			v[c-'a'].insert(pos);
  		}else{
  			int a,b; cin>>a>>b; a--; b--;
  			int res=0;
  			fore(i,0,26){
  				if(v[i].lower_bound(a)!=v[i].end() && *v[i].lower_bound(a)<=b)res++;
  			}
  			cout<<res<<endl;
  		}
  	}

    return 0;
}