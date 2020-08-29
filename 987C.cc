#include <iostream>
using namespace std;
#define ll long long

ll n,s[3010],c[3020];

int main(){
	cin >> n;
	ll res = 4e10;
	for(int i = 1; i <= n; i++)cin>>s[i];
	for (int i = 1; i <= n; i++)cin>>c[i];
	for (int i = 1; i <= n; ++i){
		ll minl = 4e10;
		ll minr = 4e10;
		for(int j = i-1; j > 0; j--)
			if(s[j] < s[i])minl=min(minl,c[j]);
		for(int j = i+1; j <= n; j++)
			if(s[j] > s[i])minr=min(minr,c[j]);
		res = min(res,c[i]+minl+minr);
	}
	if(res < 4e10)cout<<res;
	else cout<<-1;

	return 0;
}