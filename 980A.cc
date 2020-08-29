#include <iostream>
#include <string>
using namespace std;
int main(){
  string s;
  cin >> s;
  int countl=0;
  int counto=0;
  for(int i=0;i<s.length();i++){
      if(s[i]=='-'){
          countl++;
      }
  }
  counto=s.length()-countl;
  if(countl == 0 || counto == 0){
      cout <<  "YES";
  } else if(countl % counto == 0){
      cout << "YES";
  } else {
      cout << "NO";
  }
    
return 0;
}