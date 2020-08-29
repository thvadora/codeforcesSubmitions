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
#define INF (long long)1e7
#define infi  (int)2e9
#define int long long
#define endl '\n'
const ld pi = 3.14159265258979222846;
const ll mod = 1e8;
const ld EPS = 1e-18;
const int MAX_N = 2e5;


typedef pair<ll,ll> pr;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

int n; 

bool can(int k){
    int e = 0; int aux = n;
    while(aux>0){
        e+=k;
        aux-=k;
        if(aux<0)e+=aux;
        aux-=(aux/10);
    }
    return 2*e>=(n);
}

integer main(){
    cin>>n;
    int a=1; int b=n; int c;
    while(b>a){
        c=(a+b)/2;
        if(can(c))b=c;
        else a=c+1;
    }
    cout<<a<<endl;
    return 0;
}