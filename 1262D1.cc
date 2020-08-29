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
#define INF (long long)1e13
#define infi  (int)2e9
#define int long long
#define endl '\n'
const ld pi = 3.14159265258979222846;
const ll mod = 1e9+7;
const ld EPS = 1e-18;
const int MAXN = 3e5;


typedef pair<ll,ll> pr;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b));}

vector< pair<int,int> > v;
vector<int> vv[MAXN];

bool f(pair<int,int> a, pair<int,int> b){
    if(a.fst>b.fst)return true;
    if(a.fst==b.fst && a.snd<=b.snd)return true;
    return false;
}

integer main(){
    int t; t=1;
    while(t--){
        int n; cin>>n;
        vector<int> norm;
        fore(i,0,n){
            int a; cin>>a;
            norm.pb(a);
            v.pb({a,i});
        }
        sort(ALL(v),f);
        fore(i,1,n+1){
            int put=0;
            for(auto x:v){
                if(put==i)break;
                vv[i].pb(x.snd);
                put++;
            }
        }
        fore(i,0,n+1)sort(ALL(vv[i]));
        /*fore(i,1,n+1){
            for(auto x:vv[i]){
                cout<<x<<" ";
            }
            cout<<endl;
        }*/
        int q; cin>>q;
        while(q--){
            int k,pos; cin>>k>>pos; pos--;
            //cout<<"k: "<<k<<" pos: "<<pos<<endl;
            cout<<norm[vv[k][pos]]<<endl;
        }
    }
    return 0;
}