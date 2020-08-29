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
#define infi  2e9
#define int long long
#define endl '\n'
const ld pi = 3.14159265358979323846;
const ll mod = 1e9+7;


typedef pair<ll,ll> pll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

const int MAX_N = 1e15;
const int K=20;

integer main(){
	int n,k; cin>>n>>k;string s;cin>>s;
    string p=""; char c; c=s[0]; p+=c;
    map<string,int> mpp;
    if(k==1){
        fore(i,0,n){
            p=s[i];mpp[p]++;
        }
        int mxx=0;
        for(auto x:mpp)mxx=max(mxx,x.sd);
            cout<<mxx;
        return 0;
    }
    int i=1; 
    while(i<n){
        if(s[i]==c){
            p+=s[i];
        }else{
            p="";
            p+=s[i];
            c=s[i];
        }    
        if(SZ(p)==k){
            mpp[p]++;
            p="";i++;
            p+=s[i];
            c=s[i];
        }
        i++;
    }
    int mxx=0;
    for(auto x:mpp)mxx=max(mxx,x.sd);
    cout<<mxx;
    return 0;
}