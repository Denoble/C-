#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>
#include<time.h>
#include<iomanip>
#ifdef _DEBUG // 			
#define _CRTDBG_MAP_ALLOC // 		
#include <crtdbg.h>
#endif
using namespace std;
class String{
	public:
		String(const char * name =" ");
		String(const String &b);
		void list();
		
	private:
		char  * c_string;
};
void f(String &s);
void f(int t);
void main(){
	int i = 0;
	_CrtMemState memory; // C/C++ runtime memory management state storage
	while (i < 1000) {
		f(i++);
		// dump memory management state
		_CrtMemCheckpoint(&memory); _CrtMemDumpStatistics(&memory);
	}
	_CrtDumpMemoryLeaks(); // check if there were memory leaks
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
void f(int i) {
	String s("abcdefghijklmnopqrstuvwxyz");
	if (i % 100 == 0)
	s.list();
}