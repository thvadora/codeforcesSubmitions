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
#define All(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())

#define infll 1e17
#define infi  2e9
const ld pi = 3.14159265358979323846;
const ll mod = 1e9+7;


typedef pair<ll,ll> pii;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

const ll MAX_N = 100;

int main(){FIN;
    ll n; cin>>n;
    ll a[n]; bool b[n];
    mm(b,0);
    fore(i,0,n){
        string s;cin>>s;
        ll x=0; ll y=0;
        bool q=false,p=false;
        fore(j,0,SZ(s)){
            x+=(s[j] =='(');
            x-=(s[j] ==')');
            if(x<0)p=true;
        }
        rfore(j,SZ(s),0){
            y-=(s[j]=='(' );
            y+=(s[j] == ')');
            if(y<0)q=true;
        }
        if(!(q&&p)){
            a[i] = x; b[i] = 1;
        } 
    }
    map <ll,ll> mpp;
    fore(i,0,n){
        if(b[i])mpp[a[i]]++;
    }
    ll res=0;
    for(auto x : mpp){
        if(x.fs==0)res+=x.sd/2;
        if(x.fs>0)res+=min(x.sd,mpp[-x.fs]);
    }
    cout<<res;

    return 0;
}