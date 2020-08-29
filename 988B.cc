#include <iostream>
#include <algorithm>
#include <set>
#include <stdbool.h>
#include <map>
#include <string>
using namespace std;


int main(int argc, char const *argv[]){

	int n; 
	cin >> n;
	string s;
    pair<int,string> p[n];
	
    for(int i = 0; i < n; i++){
    	cin >> s;
    	p[i].first = s.size();
    	p[i].second = s;
    }
    sort(p,p+n);	
    for(int i = 0; i < n-1; i++){
    	if((p[i+1].second).find(p[i].second) == string::npos){
    		cout <<"NO";
    		return 0;
    	}
    }
    cout <<"YES"<<endl;
    for(int i = 0; i < n;i++){
    	cout<< p[i].second<<"\n";
    }
	return 0;
}