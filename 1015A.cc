#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pb push_back
#define bs binary_search
#define fs first 
#define sd second 
#define mk make_pair    
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

int mark[10000];

int main(){FIN;
	int n,m; cin>>n>>m; int l[n],r[n];
	for (int i = 0; i < n; ++i)cin>>l[i]>>r[i];
	for (int i=0;i<n;i++){
		for (int j = l[i]; j <=r[i]; ++j){
			mark[j]=true;
		}
	}
	int count=0;
	for (int i = 1; i <= m; ++i){
		if(!mark[i])count++;
	}
	cout<<count<<endl;
	for (int i = 1; i <= m; ++i){
		if(!mark[i])cout<<i<<" ";
	}
	return 0;
}