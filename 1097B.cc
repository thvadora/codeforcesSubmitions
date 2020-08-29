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

const int MAX_N = 100;


int n;
int a[MAX_N];
int dp[MAX_N+600][MAX_N];

bool doit(int i, int value){
    if(i==n && value==0)return 1;
    if(i==n)return 0;
    if(~dp[value][i])return dp[value][i];
    int &res=dp[value][i];
    res=0;
    //cout<<"debug";
    res=res|doit(i+1,(value+a[i])%360);
    res=res|doit(i+1,(value-a[i]+360)%360);
    return res;
}

int main(){FIN;
    mm(dp,-1);cin>>n;
    fore(i,0,n)cin>>a[i];
    //cout<<"ja";
    if(doit(0,0))cout<<"YES";
    else cout<<"NO";
    return 0;
}