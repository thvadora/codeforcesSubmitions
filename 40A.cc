#include <iostream>
#include <math.h>
using namespace std;


int main(){
	int x,y,xp,yp;
	float s = 0;
	cin >> x >> y;

	xp = x;
	yp = y;
	x = xp*xp + yp*yp;
	s = sqrt((float)x);
	y = s;

	if(y*y == x){
		cout << "black";

	} else if(xp * yp > 0){
		if(y % 2 == 0){
			cout << "black";
		} else {
			cout << "white";
		}
	} else if(xp * yp < 0){
		if(y % 2 == 1){
			cout << "black";
		} else {
			cout << "white";
		}
	} else { 
		cout << "black";
	}
	return 0;
}