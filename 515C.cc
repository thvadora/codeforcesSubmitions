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

const int MAX_N = 1e5+200;
string f[MAX_N];
string res;


int main(){FIN;
  f[0]="0";
  f[1]="0";
  f[2]="2";
  f[3]="3";
  f[4]="322";
  f[5]="5";
  f[6]="53";
  f[7]="7";
  f[8]="7222";
  f[9]="7332";
  int n; cin>>n;
  fore(i,0,n){
    char a; cin>>a;
    int x = a-'0';
    if(x==0 || x==1)continue;
    res+=f[x];
  }
  sort(ALL(res));
  reverse(ALL(res));
  fore(i,0,SZ(res)){
    cout<<res[i];
  }

  return 0;
}