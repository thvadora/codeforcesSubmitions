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


int main(){FIN;
  string n; cin>>n;
  fore(i,0,SZ(n)){
    string tmp = n.substr(i,1);
    //cout<<tmp<<endl;
    int x = stoi(tmp);
    //cout<<x<<endl;
    if(x==8 || x==0){cout<<"YES"<<endl<<x; return 0;}
    fore(j,i+1,SZ(n)){
      string s = n.substr(j,1);
      string neww = tmp+s;
      //cout<<neww<<endl;
      int y = stoi(neww);
      //cout<<y<<endl;
      if(y%8==0){cout<<"YES"<<endl<<y; return 0;}
      fore(k,j+1,SZ(n)){
        string p = n.substr(k,1);;
        string newww = neww+p;
        //cout<<newww<<endl;
        int z = stoi(newww);
        //cout<<z<<endl;
        if(z%8==0){cout<<"YES"<<endl<<z; return 0;}
      }
    }
  }
  cout<<"NO";
  return 0;
}