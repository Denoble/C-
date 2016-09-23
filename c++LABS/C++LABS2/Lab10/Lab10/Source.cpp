#include<iostream>
#include<string>
#include"Header.h"
using namespace std;
int main(void) {
	
	TPair<string,string> intPair("Ahmed","Mubutu");
	 
	TPair<int, TPair<string, string>>par(4, intPair);
	cout << par.getFirst(); cout << " "; cout << intPair.getFirst(); cout << " "; cout << intPair.getSecond()<<endl;
	vector<string>nstr;
	
	system("pause");
	return 0;
}