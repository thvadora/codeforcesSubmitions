#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define ll long long
#define pb push_back

int main(){
	int n,sum = 0;
	cin >> n;
	int grades[n];
	for (int i = 0; i < n; ++i){
		cin >> grades[i];
		sum+=grades[i];
	}
	double average = (double)sum/n;
	int r = round(average);
	int i = 0;
	if(r==5){
		cout << 0;
	} else {
		while(r!=5){
			sum+=1;
			average = (double)sum/n;
			r = round(average);
			i++;
		}
		sort(grades,grades+n);
		sum = 0;
		int res = 0;
		bool toy = false;
		for (int j = 0; j < n && !toy; ++j){
			sum = sum + (5-grades[j]);
			res++;
			if(sum >= i){
				toy = true;
			}		
		}
		cout << res;
	}
}