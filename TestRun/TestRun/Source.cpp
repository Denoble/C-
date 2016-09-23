#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>
#include<iomanip>
using namespace std;
class Hellow{
	
	private:
		
		void printGreeting(){
			greeting="Hello world";
			
		}
	public:
		string i;  string greeting;
		void addToGreeting(){
			 printGreeting();
			for(int k=0;k<2;k++){
				cout<<" Enter digit "<<endl;
				cin>>i;

				greeting=greeting +" "+ i;
			}
			cout<< greeting<<endl;
		}
};
void main(){
	Hellow myg;
	myg.addToGreeting();
	string u =myg.greeting;
	cout<< u <<endl;
	cout<<pow(4.5,2)<<endl;
	fflush(stdin);getchar();
}