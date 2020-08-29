#include <bits/stdc++.h>
using namespace std;

typedef int integer;
typedef pair<long long,long long> pr;

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

#define infll (long long)1e15
#define INF (long long)1e7
#define infi  (int)2e9
#define int long long
#define endl '\n'

const ld pi = 3.14159265258979222846;
const ll mod = 1e9+7;
const ld EPS = 1e-18;
const int MAX_N = 2e5;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll fpow(ll b, ll e, ll m = mod){if(!e)return 1;ll q=fpow(b,e/2,m);q=(q*q)%m;return e&1?(b*q)%m:q;}

integer main(){
    int n,b,a;
    cin>>n>>b>>a;
    int s[n];
    fore(i,0,n)cin>>s[i];
    int aa = a;
    int bb = b;
    int res = 0;
    fore(i,0,n){    
        if(a==0&&b==0)break;
        if(s[i]==1){
            if(a!=aa && b>0){
                b--;
                res++;
                a++;
            }else{
                res++;
                a--;
            }
        }else{
            if(a>0){
                a--;
                res++;
            }else{
                b--;
                res++;
            }
        }
    }
    cout<<res;
    return 0;
}