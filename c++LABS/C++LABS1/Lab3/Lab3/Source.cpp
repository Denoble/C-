#include<iostream>
#include<string>
#include<cstdlib>
#include<iomanip>
using namespace std;
class String{
	public:
		String(const char * name =" ");
		String(const String &b);
		void list();
		~String();
	private:
		char  * c_string;
};
void f(String &s);
void main(){
	String s("abcdefg");

	s.list();
	f(s);
	s.list();
	fflush(stdin);getchar();
}
String::String(const char *name){
	c_string=new char[strlen(name)+1];
	strcpy(c_string,name);
	
}
void String:: list(){
	cout<<c_string<<endl;
}
void f(String &s){
	s.list();
}

String::String(const String &b){
	c_string=new char[strlen(b.c_string)+1];
	strcpy(c_string,b.c_string);
}
String::~String(){
	
	cout<<"freeing memory"<<endl;
	delete c_string;
}