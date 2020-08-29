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

int main(){
	int n; cin>>n; int a[n];
	fore(i,0,n)cin>>a[i];
	int c=0; int end; int res = 0;
	int i = 0;
	while(i<n-1){
		if(a[i]*2>=a[i+1]){
			c++;
		} else{
			res=max(res,c);
			c=0;
		}
		i++;
	}
	res=max(res,c);
	cout<<res+1;
}