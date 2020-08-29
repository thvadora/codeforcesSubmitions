#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	set <int> st;
	while(n--){
		int x;
		cin>>x;
		st.insert(x);
	}
	auto it = st.begin();
	it++;
	if(it!=st.end())cout<<*it;
	else cout<<"NO";
	return 0;
}