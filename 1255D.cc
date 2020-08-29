#include <bits/stdc++.h>
using namespace std;
 
typedef int integer;

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
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
const ld pi = acos(-1);
const long long MOD = 1e9+7;
const ld EPS = 1e-9;
const int MAXN = 2e5;
 
typedef pair<ll,ll> pr;
 
int gcd(int a, int b) { return b == 0 ? a : gcd(b,a%b); } 
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int fpow(int b, int e, int m=MOD){if(!e)return 1;int q=fpow(b,e/2,m);q=(q*q)%m;return e&1?(b*q)%m:q;}
void printgraph(vector <int> g[], int n){fore(i,0,n){for(auto x:g[i]){cout<<i<<" "<<x<<endl;}}}

string s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

integer main(){FIN;
    int t; cin>>t;
    while(t--){
        int n,m,k; cin>>n>>m>>k;
        int c[n][m]; mm(c,0);
        int cnt = 0;
        fore(i,0,n){
            fore(j,0,m){
                char b; cin>>b;
                c[i][j]=(b=='R');
                cnt+=(b=='R');
            }
        }
        int num = 0;
        fore(i,cnt,cnt*k){
            if(i%k==0){
                num = i;
                break;
            }
        }
        char res[n][m];
        int bad = num-cnt;
        int good = k - bad;
        int c_bad = (num/k)-(cnt%k>0);
        int c_good = num/k;
        int letter = 0;
        int ready = 0;
        if(bad<0){
            bad=0; c_bad=0; good=k; c_good=cnt;
        }
        //cout<<"bad: "<<bad<<" c_bad: "<<c_bad<<" good: "<<good<<" c_good: "<<c_good<<endl;
        int j=0; int i=0;
        while(j<m){
            if(j%2==0){
                i = 0;
            }else{
                i = n-1;
            }

            while(i>=0 && i<n){
                if(bad>0){
                    ready+=c[i][j];
                    res[i][j]=s[letter];
                    if(ready==c_bad){
                        bad--;
                        letter++;
                        ready=0;
                    }
                }else{
                    ready+=c[i][j];
                    res[i][j]=s[letter];
                    if(ready==c_good){
                        good--;
                        if(good>0)letter++;
                        ready=0;
                    }
                }


                if(j%2==0){
                    i++;
                }else{
                    i--;
                }
            }
            j++;
        }
        /*fore(j,0,m){
            fore(i,0,n){
                if(bad>0){
                    ready+=c[i][j];
                    res[i][j]=s[letter];
                    if(ready==c_bad){
                        bad--;
                        letter++;
                        ready=0;
                    }
                }else{
                    ready+=c[i][j];
                    res[i][j]=s[letter];
                    if(ready==c_good){
                        good--;
                        if(good>0)letter++;
                        ready=0;
                    }
                }
            }
        }*/
        fore(k,0,n){
            fore(t,0,m){
                cout<<res[k][t];
            }
            cout<<endl;
        }
    }
	return 0;
}