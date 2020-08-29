#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
#define ll long long
#define pb push_back
#define fs first
#define sd second

int main(){
	ll n;cin>>n;int a[n];
	for (int i = 0; i < n; ++i)cin>>a[i];
	for (int i = 0; i < n; ++i){
		if(a[i]%2==0)a[i]--;
	}
	for (int i = 0; i < n; ++i){
		cout<<a[i]<<" ";
	}
	return 0;
}