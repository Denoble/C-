#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include<math.h>
using namespace std;
void main(){
	ofstream nameFile;
	char name[50];
	char age[10];
	time_t now = time(NULL);
	struct tm *st;
	char dateTime[30];
	
	 nameFile.open("Test.txt");
	 
		cout << "Please enter your name \n" << endl;
		cin.getline(name, 50);
		nameFile << name << endl;
		cout << "Please enter your age \n" << endl;
		cin.getline(age, 10);
		nameFile << age << endl;
	
		nameFile.close();

	
}