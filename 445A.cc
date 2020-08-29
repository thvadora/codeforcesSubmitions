#include <bits/stdc++.h>

using namespace std;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pb push_back
#define bs binary_search
#define ft first 
#define sd second 
#define mp make_pair    
#define mt make_tuple

#define fore(i,a,b) for(ll i = a; i < b; i++)
#define rfore(i, a, b) for(ll i = a - 1; i >= b; i--)
#define mm(a,b) memset(a , b , sizeof a) 
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())
#define V(a) vector <a> 
#define P(a,b) pair<a,b>
#define M(a,b) map<a,b> 
#define S(a) set<a>
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

int main(){
	int n,m; cin>>n>>m;
	char c[n][m];
	fore(i,0,n){
		fore(j,0,m){
			cin>>c[i][j];
		}
	}
	fore(i,0,n){
		fore(j,0,m){
			if(c[i][j]=='.'){
				if((i+j)%2==0)cout<<"B";
				else cout<<"W";
			} else {
				cout<<"-";
			}
		}
		cout<<endl;
	}
	return 0;
}