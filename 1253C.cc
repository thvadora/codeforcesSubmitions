#include <bits/stdc++.h>
using namespace std;
 
typedef int integer;

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
#define bs binary_search
#define up upper_bound
#define lw lower_bound
#define fst first 
#define snd second 
#define mp make_pair    
 
#define fore(i,a,b) for(ll i = a; i < b; i++)
#define rfore(i, a, b) for(ll i = a - 1; i >= b; i--)
#define forev(a,b) fore(i,0,b)cout<<a[i]<<" "; 
#define mm(a,b) memset(a , b , sizeof a) 
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())
 
#define infll (long long)1e7
#define INF (long long)1e13
#define infi  (int)2e9
#define int long long
#define endl '\n'
const ld pi = acos(-1);
const long long MOD = 1e9+7;
const ld EPS = 1e-9;
const int MAXN = 2e5;
 
typedef pair<ll,ll> pr;
 
int gcd(int a, int b) { return b == 0 ? a : gcd(b,a%b); } 
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int fpow(int b, int e, int m=MOD){if(!e)return 1;int q=fpow(b,e/2,m);q=(q*q)%m;return e&1?(b*q)%m:q;}
void printgraph(vector <int> g[], int n){fore(i,0,n){for(auto x:g[i]){cout<<i<<" "<<x<<endl;}}}

int n,m;
int a[MAXN];
int dp[MAXN];
int fm[MAXN];

int sum(int l, int r){
    return dp[r+1]-dp[l];
}

int get(int k){
    if(k<0)return 0;
    return fm[k];
}

integer main(){FIN;
    cin>>n>>m; int p = n;
    fore(i,0,n){
        cin>>a[i];
    }
    sort(a,a+n);
    fore(i,0,n){
        dp[i+1]=dp[i]+a[i];
    }
    int used = 0;
    int cur = 0;
    /*fore(i,0,n){
        used++;
        if(used<=m){
            cout<<"1 -- "<<a[i]<<endl;
            cur+=a[i];
            cout<<"cur: "<<cur<<endl;
        }else{
            cout<<"2 -- "<<a[i]<<endl;
            used=0;
            cur=sum(i-m,i+1)+(cur-sum(i-m+1,i));
            cout<<"cur: "<<cur<<endl;
        }
        //cout<<cur<<" ";
    }*/
    fore(i,0,n){
        fm[i]=sum(0,i)+get(i-m);
        cout<<fm[i]<<" ";
    }
	return 0;
}