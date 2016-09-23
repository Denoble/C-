#include<iostream>
#include<string>
using namespace std;
class Lab1{

	public:
			void f(){
				cout<<" Hello \n";

			}
			void f(int k){
				cout<<"Integer equals :"<<k <<endl;
			}
			void f(int g,string myname){
			
				
				f(g);
				cout<<"my name is "<<myname<<endl;
			}
			void  initialize_xy(double * num1, double *num2, double x, double y){
				*num1=x;
				*num2=y;

			}
			void initialize_xy(double *num1,double *num2){
				*num1=0.00;
				*num2=0.00;
			}
	private:
		int y;
		string name;
};
 typedef struct {
	int b;
	int  a;

} T;
void main(){
	Lab1 mylab1;
	string oneName;
	int num;int numberOfArrays;
	int * intArray=NULL;
	
	double euro,dollar;
	cout<<"Please enter your name\n";
	getline(cin,oneName);
	
	cout<<endl;
	cout<<"Enter integer\n";
	cin>>num;
	cout<<endl;
	mylab1.f(num,oneName);
	mylab1.initialize_xy(&euro,&dollar,45.098,30.782);
	cout<<"Enter integer\n";
	cin>>numberOfArrays;
	intArray=new int[numberOfArrays];
	for (int star = 0; star <numberOfArrays; star = star + 1) {
		int k=rand() % 100 ;
		intArray[star]=k;

	}
	for (int star = 0; star <numberOfArrays; star = star + 1){
		cout<<intArray[star]<<endl;
	}
	delete intArray;
	cout<<" Money values are dollar "<<dollar<<":euro "<<euro<<endl;
	mylab1.initialize_xy(&euro,&dollar);
	cout<<" Money values are dollar "<<dollar<<":euro "<<euro<<endl;
	 T s;
	s.a=12;
	s.b=45;
	cout<<s.a<<" " <<s.b<<endl;
	fflush(stdin);getchar();
}

