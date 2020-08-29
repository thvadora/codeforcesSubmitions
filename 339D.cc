#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define pb push_back
#define NEUT 0
#define caca ios::sync_with_stdio(false);
int oper(int x, int y,int type){
	if(type%2==0)return x|y;
	return x^y; 
}
int n,m;
struct STree { // segment tree for min over integers
	vector<int> st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void init(int k, int s, int e, int *a,int type){
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a,type+1);init(2*k+1,m,e,a,type+1);
		st[k]=oper(st[2*k],st[2*k+1],type+1);
	}
	void upd(int k, int s, int e, int p, int v,int type){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v,type+1);
		else upd(2*k+1,m,e,p,v,type+1);
		st[k]=oper(st[2*k],st[2*k+1],type+1);
	}
	int query(int k, int s, int e, int a, int b,int type){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b,type+1),query(2*k+1,m,e,a,b,type+1),type+1);
	}
	void init(int *a,int type){init(1,0,n,a,type);}
	void upd(int p, int v,int type){upd(1,0,n,p,v,type);}
	int query(int a, int b,int type){return query(1,0,n,a,b,type);}
}; 

int main(){caca;
	cin>>n>>m;int a[1000001];
	int type=n%2; n=1<<n;
	//cout<<"type"<<(11 | 26)<<endl;
	for (int i = 0; i < n; ++i)cin>>a[i];
	STree st(n);
	st.init(a,type);
	while(m--){
		int u,v;cin>>u>>v;u--;
		st.upd(u,v,type);
		cout<<st.query(0,n+1,type)<<endl;
	}
	return 0;
}