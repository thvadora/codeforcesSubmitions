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
#define secondd second 
#define mp make_pair    
 
#define fore(i,a,b) for(ll i = a; i < b; i++)
#define rfore(i, a, b) for(ll i = a - 1; i >= b; i--)
#define forev(a,b) fore(i,0,b)cout<<a[i]<<" "; 
#define mm(a,b) memset(a , b , sizeof a) 
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())
 
#define infll (long long)1e13
#define INF (long long)1e13
#define infi  (int)2e9
#define int long long
#define endl '\n'
const ld pi = acos(-1);
const long long MOD = 1e9+7;
const ld EPS = 1e-9;
const int MAXN = 2e6;
 
typedef pair<ll,ll> pr;
 
int gcd(int a, int b) { return b == 0 ? a : gcd(b,a%b); } 
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int fpow(int b, int e, int m=MOD){if(!e)return 1;int q=fpow(b,e/2,m);q=(q*q)%m;return e&1?(b*q)%m:q;}
void printgraph(vector <int> g[], int n){fore(i,0,n){for(auto x:g[i]){cout<<i<<" "<<x<<endl;}}}
void printvec(vector<int> v){for(auto x: v){cout<<x<<" ";}cout<<endl;}
void printmap(map<int, int> v){for(auto x: v){cout<<x.fst<<" "<<x.snd<<endl;}cout<<endl;}

integer main(){FIN;
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int n = SZ(s); int a[n];
        if(n==1){
            cout<<s<<endl;
            continue;
        }
        fore(i,0,n)a[i]=s[i]-'0';
        int i = 0; int par = 1; int impar = 1;
        fore(i,1,n)if(a[i]&1){impar=i; break;}
        fore(i,1,n)if(!(a[i]&1)){par=i; break;}
        int times = 0; vector<int> res;
        while(times<n && i<n){
            if(a[i]==-1){i++;continue;}
            if(a[i]&1){
                int p = a[i];
                par = max(i+1,par);
                if(par>=n){
                    res.pb(p);
                    times++;
                    i++;
                    continue;
                }
                while(((a[par]==-1) || a[par]&1) && par<n)par++;
                if(a[par]<=a[i]){p=a[par]; a[par]=-1;i--;}
                res.pb(p);
                times++;
            }else{
                int p = a[i];
                impar = max(i+1,impar);
                if(impar>=n){
                    res.pb(p);
                    times++;
                    i++;
                    continue;
                }
                while(((a[impar]==-1) || !(a[impar]&1)) && impar<n)impar++;
                if(a[impar]<=a[i]){p=a[impar]; a[impar]=-1; i--;}
                res.pb(p);
                times++;
            }
            i++;
        }
        for(auto x:res)cout<<x;
        cout<<endl;
    }
    return 0;
}