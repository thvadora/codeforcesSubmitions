#include <bits/stdc++.h>
using namespace std;

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
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

#define infll 1e18
#define infi  2e9
#define pi 3.14159265359 
const ll mod =  1e9+7;
#define eps  1e-6

typedef pair<ll,ll> pll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

ll e2[100005];
int par[100005];

ll solve(int n,int m){
    if(n == 0)return 0;
    if(n == m)return e2[n]-1;
    return (((e2[n]-1)+((e2[n]-1)* (e2[m-n]-1))%mod)%mod);
}

int main(){FIN;
    e2[0] = 1;
    fore(i,1,100005){
        e2[i] = (e2[i-1]*2)%mod;
    }
    int n,q;cin>>n>>q;
    string s;
    cin>>s;
    fore(i,0,n){
        par[i+1] = par[i] + (s[i] == '1');
    }

    while(q--){
        int a,b;cin>>a>>b;

        cout<<solve(par[b]-par[a-1],b-a+1)<<endl;

    }


	return 0;
}