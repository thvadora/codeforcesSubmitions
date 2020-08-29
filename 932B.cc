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

#define infll (long long)1e7
#define infi  (int)2e9
#define int long long
#define endl '\n'
const ld pi = 3.14159265258979222846;
const ll mod = 1e9+7;
const ld EPS = 1e-18;


typedef pair<ll,ll> pr;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

const int MAX_N = 1e6+10;

int mtx[10][MAX_N];	

int get(int i){
	if(i<10)return i;
	int prod=1;
	while(i!=0){
		if(i%10)prod*=(i%10);
		i/=10;
	}
	return get(prod);
}

integer main(){
	fore(i,0,1000001){
		mtx[get(i)][i]++;
	}
	fore(i,0,10)fore(j,0,1000001)mtx[i][j]+=mtx[i][max(j-1,0ll)];
	int q; cin>>q;
	while(q--){
		int a,b,k; cin>>a>>b>>k;
		cout<<mtx[k][b]-mtx[k][a-1]<<endl;
	}
	return 0;
}