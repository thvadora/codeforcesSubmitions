#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
#define pb push_back
#define bs binary_search


int main(){
	ll n;
	cin >> n;
	ll a[n];
	ll sum = 0;
	for (int i = 0; i < n; ++i){
		cin>>a[i];
		sum+=a[i];
	}
	int llegada = sum / 2;
	if(sum % 2 != 0){
		llegada++;
	}
	ll i = 0;
	sum = 0;
	while(sum < llegada){
		sum = sum + a[i];
		i++;
	}
	cout << i;
	return 0;
}