#include <iostream>
using namespace std;

int n,k;
int a[101];

int main(){
	cin >> n >> k;
	for (int i = 0; i < n; ++i)cin>>a[i];
	bool can = true;
	int i = 0;
	int j = n-1;
	int count = 0;
	while(can && i <= j){
		if(a[i] <= k){
			i++;
			count++;
		}else if(a[j] <= k){
			j--;
			count++;
		}else{
			can = false;
		}
	}
	cout << count;
	return 0;
}