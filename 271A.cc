#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
    
    int number;

    cin >> number;

    while (true) {

        number = number + 1;

        int a = number / 1000; int b = number / 100 % 10; int c = number / 10 % 10; int d = number % 10;
        
            if (a != b && a != c && a != d && b != c && b != d && c != d){

                break;
            }
            else { continue; }
    }

    cout << number << endl;



    return 0;
}