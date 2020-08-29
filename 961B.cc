#include <iostream>
using namespace std;

typedef struct position{
	long long i;
	long long j;
} positions;

typedef struct clase{
	long long awake;
	long long q_theo;
} lecture;

positions max_tech(lecture array[], long long n, long long k){
	long long maximum = 0;
	long long sum  = 0;
	position pos;
	for (int i = 0; i < k; i++){
		if(array[i].awake == 0){
			sum = sum + array[i].q_theo;
		}
	}
	pos.i = 0;
	pos.j = k-1;
	maximum = sum;
	for (int i = 1; i <= n-k; i++){
		//cout << array[i-1].q_theo << " " << array[i+k-1].q_theo << endl;
		if(array[i-1].awake == 0){
			sum = sum - array[i-1].q_theo;
		}
		if(array[i+k-1].awake == 0){
			sum = sum + array[i+k-1].q_theo;
		}
		if(maximum < sum){
		pos.i = i;
		pos.j = i+k-1;
		maximum = sum;
		}
	}

return pos;
}

int main(){
	long long n = 0, k = 0;
	cin >> n >> k;
	lecture array[n+10];
	long long count = 0;
	for (int i = 0; i < n; i++){
		cin >> array[i].q_theo;
	}
	for (int i = 0; i < n; i++){
		cin >> array[i].awake;
	}
	positions technique;
	technique = max_tech(array,n,k);
	//	cout << technique.i << technique.j << endl;
	for (int i = 0; i < n; i++){
		if(array[i].awake == 1 && (i < technique.i || i > technique.j)){
			count = count + array[i].q_theo;
		}
		if(i >= technique.i && i <= technique.j){
			count = count + array[i].q_theo;
		}
	}

	cout << count << endl;

	return 0;
}