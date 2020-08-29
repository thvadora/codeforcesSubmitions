#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
#define ll long long
#define pb push_back

string a[1001],b[1001];

bool exists(string arr[], int n, string x){
	bool b = false;
	for (int i = 0; i < n && !b; ++i){
		if(arr[i] == x){
			b = true;
			a[i] = "yala";
		}
	}
	return b;
}

int main(){
	int n = 0,count = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> a[i];
	sort(a,a+n);
	for (int i = 0; i < n; ++i)cin >> b[i];
	sort(b,b+n);
	for (int i = 0; i < n; ++i){
		if(!exists(a,n,b[i])){
			count++;
		}		
	}
	cout << count;

	return 0;
}