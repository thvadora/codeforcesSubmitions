#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    double x,y;
    cin >> x >> y;
    double log_x = log(x);
    double log_y = log(y);
    if(x==y){
        cout << '=';
    } else if(y*log_x > x*log_y){
        cout << '>';
    } else if(y*log_x == x*log_y){
        cout << '=';
    } else {
        cout << '<';
    }

    return 0;
}