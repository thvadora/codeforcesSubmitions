#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define remove_spaces(x) x.erase(std::remove(x.begin(), x.end(), ' '), x.end())
#define remove_q_signs(x) x.erase(std::remove(x.begin(), x.end(), '?'), x.end())

int exists(char array[],int n, char elem){
	int ex = 0;
	for (int i = 0; i < n && ex != 1; ++i){
		if(array[i] == elem){
			ex = 1;
		}
	}
return ex;
}

int main(int argc, char const *argv[]){
	char lower_letter[] = {'a','e', 'i', 'o', 'u','y'};
	string question;
	getline(cin,question);
	remove_spaces(question);
	remove_q_signs(question);
	for (int i = 0; i < question.length(); ++i){
		question[i] = tolower(question[i]);
	}
	int r = exists(lower_letter,6,question[question.length()-1]) ;
	if( r == 1){
		cout << "YES";
	} else {
		cout << "NO";
	}
	
	return 0;
}