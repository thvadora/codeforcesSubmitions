#include <bits/stdc++.h>
using namespace std;

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
#define bs binary_search
#define up upper_bound
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
const ld pi = 3.14159265358979323846;
const ll mod = 1e9+7;


typedef pair<ll,ll> pll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

const int MAX_N = 1e5;

int main(){
    int n,k;cin>>n>>k; int a[n]; fore(i,0,n)cin>>a[i];
    vector<int> ac[MAX_N]; fore(i,0,n)ac[a[i]].pb(i);
    map<int,int> mpp; fore(i,0,n)mpp[a[i]]++;
    for(auto x : mpp)if(x.sd>k){cout<<"NO";return 0;}
    int b[n+1]; int p=0;
    for(auto x : mpp){
        fore(i,0,SZ(ac[x.fs])){
            b[ac[x.fs][i]]=(p%k);
            p++;p=p%k;
        }
    }
    cout<<"YES"<<endl;
    fore(i,0,n)cout<<b[i]+1<<" ";
	return 0;
}