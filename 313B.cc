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
const ll mod = 1e9+7;


typedef pair<ll,ll> pll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

int sp[100002];
int a[100002];

int main(){FIN;
  string s; cin>>s;
  int n = SZ(s);
  fore(i,1,n){
    if(s[i]==s[i-1]){
      sp[i]=sp[i-1]+1;
    }else{
      sp[i]=sp[i-1];
    }
  }
  /*
  fore(i,0,n){
    cout<<sp[i]<<" ";
  }*/
  int m; cin>>m;
  while(m--){
    int x,y; cin>>x>>y;
    cout<<sp[y-1]-sp[x-1]<<endl;
  }
  return 0;
}