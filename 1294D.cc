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
#define inf  (int)2e9
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
	int n; cin>>n; int m; cin>>m;
	set<pr> st; int freq[m];
	fore(i,0,m){
		st.insert({0,i});
		freq[i]=0;
	}
	while(n--){
		int x; cin>>x;
		int mo=x%m;
		/*cout<<"asi esta el set: "<<endl;
		for(auto x:st){
			cout<<x.fst<<" "<<x.snd<<endl;
		}*/
		auto it = st.find({freq[mo],mo});
		pr nw = {(*it).fst+1,(*it).snd};
		st.erase(it); st.insert(nw);
		freq[mo]++;
		cout<<(*st.begin()).fst * m + (*st.begin()).snd<<endl;
	}
    return 0; 
}