#include <bits/stdc++.h>

using namespace std;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pb push_back
#define bs binary_search
#define fs first 
#define sd second 
#define mp make_pair    
#define mt make_tuple

#define fore(i,a,b) for(ll i = a; i < b; i++)
#define rfore(i, a, b) for(ll i = a - 1; i >= b; i--)
#define mm(a,b) memset(a , b , sizeof a) 
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())
#define V(a) vector <a> 
#define P(a,b) pair<a,b>
#define M(a,b) map<a,b> 
#define S(a) set<a>

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

int dist[501][501], n;
V(int) v;


int main(){
    FIN;    

    
    cin>>n;
    int a[n][n];
    fore(i,0,n){
        fore(j,0,n){
            cin>>dist[i][j];
            //dist[i][j] = 1e9;
        }
    }

    int q = n;

    ll sum = 0;  
    fore(i,0,q){
        int x;
        dist[i][i] = 0;
        cin>>x;
        v.pb(x-1);
    }
    V(int) v2;
    ll res[q];
    for (int p = 0;p < n; p++) {
        
        int k = v[n -1 -p];
        v2.pb(k);
        
        for (int i  = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
        for(auto i : v2){
            for(auto j : v2){
               if(dist[i][j] != 1e9)sum+=dist[i][j];
            }
        }
        res[k] = sum;
        sum= 0;
    }

    fore(i,0,n){
        cout<<res[v2[n-1-i]]<<" ";
    }


    return 0;   
    
}