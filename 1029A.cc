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
int a[100001];  
void build(string s){
  int len = 0, i;
  for(i = 1; i < s.length();){
    if(s[len] == s[i]){
      a[i++] = ++len;
    }
    else if(len){
      len = a[len-1];
    }
    else{
      a[i++] = 0;
    }
  }
}

int main(){
	int n,k; cin>>n>>k;
	string t; cin>>t; int p = SZ(t); string ant = t;
  build(t); int cons=a[p-1];
	if(!cons){
		fore(i,0,k-1){
			t=t+ant;
		}
	} else {
		fore(i,0,k-1){
			t=t+ant.substr(cons,p-1);
		}
	}
	cout<<t;

	return 0;
}