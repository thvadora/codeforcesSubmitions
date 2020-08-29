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
#define fs first 
#define sd second 
#define mp make_pair    

#define fore(i,a,b) for(ll i = a; i < b; i++)
#define rfore(i, a, b) for(ll i = a - 1; i >= b; i--)
#define forev(a,b) fore(i,0,b)cout<<a[i]<<" "; 
#define mm(a,b) memset(a , b , sizeof a) 
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())

#define infi  2e9
#define int long long
#define endl '\n'
const ld pi = 3.14159265358979323846;
const ll mod = 1e9+7;
const ll INF = 1e10;

typedef pair<ll,ll> pll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

const int MAXN = 2000;
const int K=20;

int used[MAXN];

integer main(){
	string s; cin>>s;
	int ones,zeros; ones=0; zeros=0;
    fore(i,0,SZ(s)){
        if(s[i]-'0'){
        	ones++;
        	//cout<<"pos:"<<i<<" : "<<ones<<endl;
            if(ones==1)cout<<"1 2"<<endl;
            if(ones==2)cout<<"2 2"<<endl;
            if(ones==3)cout<<"3 2"<<endl;
            if(ones>=4){
            	cout<<"4 2"<<endl;
            	ones=0;
            }
        }else{
        	zeros++;
            if(zeros==1)cout<<"1 1"<<endl;
            if(zeros>=2){
            	cout<<"3 1"<<endl;
            	zeros=0;
            }
        }
    }
}