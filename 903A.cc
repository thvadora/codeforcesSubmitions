#include <iostream>
#include <vector>
using namespace std;
#define pb push_back

int n;
vector <string> s;

int main(){
	cin >> n;
	int a,b;
	int xi;
	while(n--){
		cin >> xi;
		bool b = false;
		for (int i = 0; i < 33 && !b; ++i){
			for (int j = 0; j < 33 && !b; ++j){
				if(3*i + 7*j == xi){
					s.pb("YES");
					b = true;
				}	
			}
		}
		if(!b){
			s.pb("NO");
		}
	}
	for(int i = 0; i < s.size(); ++i){
	cout << s[i] << endl;
	}

}