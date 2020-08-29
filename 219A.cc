#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
#include <string>
#include <map>
using namespace std;
#define ll long long
#define pb push_back
#define bs binary_search


int main(){
    int k;
    string s;

    cin >> k >> s;
    map<char,int> m;

    for(auto a:s)m[a]++;

    for(auto a:m){
    	if(a.second%k!=0){
    		cout<<"-1";
    		return 0;
    	}
    }

    string az="";
    for(auto a:m)
    	az = az + string(a.second / k,a.first);
    while(k--){
    	cout << az;
    }
return 0;
}