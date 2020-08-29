#include <iostream>
using namespace std;

int main(void) {
int n,x,y,z;
int totalx=0;
int totaly=0; 
int totalz=0;

    cout <<""  << endl;
    cin >> n;
	
    if (1<=n<=100) {   
      
      for (int i=0; i<n; i++ ){
      
        
         
         cout <<"";
         cin >>x;
         cout <<"";
         cin >>y;
         cout <<""<< endl;
         cin >>z;
             
              if (-100<=x<=100 && -100<=y<=100 && -100<=z<=100){

               totalx += x;
               totaly += y;
               totalz += z;
               }
                 else {

                        cout <<"NO"<< endl;                        

                      }
               
       }

 if (totalx==0 && totaly==0 && totalz==0){

                    cout <<"YES"<< endl;

                  }
                  else {
                   
                    cout <<"NO"<< endl;

                  }

    }
else {
    
     cout <<"NO"<< endl;
    }
  
}