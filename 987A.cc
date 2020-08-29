#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main(){
    int gems;
    string s;
    map <string,string> g;
    g["purple"] = "Power";
    g["green"] = "Time";
    g["blue"] = "Space";
    g["orange"] = "Soul";
    g["red"] = "Reality";
    g["yellow"] = "Mind";
    cin >> gems;
    map <string,string>::iterator it;
    while(gems--){
        cin >> s;
        it = g.find(s);
        if(it != g.end()){
            g.erase(it);
        }
    }
    cout << g.size() << endl;
    for(auto elem : g){
        cout << elem.second << endl;
    }
    return 0;
}