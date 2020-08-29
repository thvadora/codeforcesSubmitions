#include <bits/stdc++.h>

using namespace std;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pb push_back
#define bs binary_search
#define ft first 
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
typedef pair< int,int> pii;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }


bool f(pii a, pii b){
    return (a.first > b.first || (a.first == b.first && a.second < b.second ));
}

int main(){
    FIN;    
    int n;
    cin>>n;
    vector<pair<int,int> > v;
    fore(i,0,n){ 
        int s = 0;
        fore(j,0,4){
            int x;
            cin>>x;
            s+=x;
        }
        v.pb({s,i+1});
    }
    sort(ALL(v),f);
    fore(i,0,n){
        if(v[i].sd == 1){
            cout<<i+1;
        }
    }
    return 0;
}