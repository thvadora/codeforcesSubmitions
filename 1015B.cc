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

string s,t; 

void swap(int i,int j){
	char tt = s[i];
	s[i]=s[j];
	s[j]=tt;
}

int main(){FIN;
	int n; cin>>n;
	cin>>s>>t;
	map <char,int> checkers;
	map <char,int> checkert; 
	if(s==t){cout<<0; return 0;}
	for (int i = 0; i < n; ++i){
		checkers[s[i]]++;
		checkert[t[i]]++;
	}
	for (int i = 0; i < n; ++i){
		if(checkert[s[i]]!=checkers[s[i]]){cout<<-1; return 0;}
	}
	vector <int> res;
	for (int i = 0; i < n; ++i){ int j = i;
        while(s[j] != t[i])j++;
        while(j != i){
            char aux = s[j];
            s[j] = s[j-1];
            s[j-1] = s[j];
            res.pb(j);
            j--;
        }
    }
    cout<<res.size()<<endl;
    for(auto x:res) cout<<x<<" ";

	return 0;
}