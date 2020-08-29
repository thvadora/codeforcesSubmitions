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

#define infi  2e9
#define int long long
#define endl '\n'
const ld pi = 3.14159265358979323846;
const ll mod = 1e9+7;
const ll INF = 1e10;

typedef pair<ll,ll> pll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

const int MAXN = 2000;
const int K=20;

int used[MAXN];

integer main(){
    string s; cin>>s; int n=SZ(s);
    vector <pll> v; 
    int c=0;
    bool b=true;
    while(b){
    	b=false; 
    	fore(i,1,n){
    		if(s[i]==s[i-1]){
    			b=true;
    			int j,k; j=i-1; k=i;
    			while(j>=0&&k<n&&(s[j]==s[k])){
    				c++; //cout<<"sume"<<endl;
    				j--;
    				k++;
    			}
    			string nw0,nw1;
    			nw0=s.substr(0,j+1);
    			nw1=s.substr(k);
    			s=nw0+nw1; n=SZ(s);
    			//cout<<nw0<<" "<<nw1<<endl;
    		}
    	}	
    }
    if(c%2==0)cout<<"No";
    else cout<<"Yes";
    return 0;
}