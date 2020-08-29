#include <iostream>
using namespace std;
int dp[40096];

int main() {
	int n,a,b,c;
	cin >> n >> a >> b >> c;
	dp[a] = 1;
	dp[b] = 1;
	dp[c] = 1;
	for(int i = 1; i < n; i++){
		if(dp[i]){
			dp[i+a] = max(dp[i]+1, dp[i+a]);
			dp[i+b] = max(dp[i]+1, dp[i+b]);
			dp[i+c] = max(dp[i]+1, dp[i+c]);
		}
	}
	cout << dp[n];

}