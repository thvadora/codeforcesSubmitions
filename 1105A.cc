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
    int n; cin>>n; int a[n];
    fore(i,0,n)cin>>a[i];
    pair <int,int> test[102];
    fore(i,1,102){
        int t=i;
        int cost=0;
        fore(j,0,n){
            int x,y,z; x=abs(a[j]-(-1+t)); y=abs(a[j]-(t)); z=abs(a[j]-(1+t));
            cost+=min(x,min(y,z));
        }
        test[i]=mp(t,cost);
        //cout<<"t: "<<t<<" cost: "<<cost<<endl;
    }
    pair <int,int> res; int mn=MAX_N;
    fore(i,1,102){
        if(mn>test[i].sd){
            res=test[i];
            mn=test[i].sd;
        }
    }
    cout<<res.fs<<" "<<res.sd;
    return 0;
}