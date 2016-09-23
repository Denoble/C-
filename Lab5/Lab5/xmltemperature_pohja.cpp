// Exercise 5

#include <iostream>
#include <fstream>
#include<string>
using namespace std;
string page;
string findLocation( string xx, string yy);

int main (void) {
	
	string  line, location, temperature;
	ifstream inputFile("weather.xml");
	while(!inputFile.eof()){
		inputFile>>line;
		page.append(line);
		
	}
	location = findLocation(page,"location");
	cout<<location<<endl;
	location = findLocation(page, "temp_c");
	cout << location << endl;
	
	cout<<"\n"<<endl;
	
	
	system("pause");
}
string findLocation(string page,string yy){
	string mystr,mystr1,myFstr;
	int y,k,z;
	mystr="<"+yy+">";
	mystr1="</"+yy+">";
	y=page.find(mystr)+mystr.length();
	k=page.find(mystr1);
	z=k-y;
	myFstr=page.substr(y,z);
	return myFstr;
}