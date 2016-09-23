#include<iostream>
#include<string>
#include<cstdlib>
#include<iomanip>
using namespace std;
class String{
	friend ostream &operator<<(ostream &out, const String &alphabet);
	public:
		String(const char * name =" ");
		String(const String &b);
		void list();
		~String();
		String& operator=(const String &str);
		String& operator+(const String &str);
		String& operator++();
		String& operator++(int);
		char& operator[](int k);
	private:
		char  * c_string;
};
void f(String &s);
void main(){
	String s1("abcedfg");
	String s2("hijklmno");
	String sum;
	cout << "String 1 is:" << s1 << endl;
	cout << "String 2 is:" << s2 << endl;
	sum = s1 + s2;
	cout << "Sum is :" << sum; // output should be
	// abcdefghijklmn
	// This should also work
	sum = sum;
	cout << "Sum is still :" << sum<<endl; // output should
	// still be abcdefghijklmn
	
	cout << s1++ << endl;
	cout << ++s1 << endl;
	for (int i = 0 ; i < 7 ; i++)
	cout << s1[i] << " " ;
	s1[4] = 'X';
	for (int i = 0 ; i < 7 ; i++)
	cout << s1[i] << " " ;
	
	fflush(stdin);getchar();
}
String::String(const char *name){
	c_string=new char[strlen(name)+1];
	strcpy(c_string,name);
	const int MAX_STRING_LENGTH=10;
	
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
ostream &operator<<(ostream &out, const String &alphabet){
	cout<< alphabet.c_string<<endl;
	return out;

}
String &String::operator=(const String &str){
	if (this != &str){
		delete c_string;
		c_string = new char[strlen(str.c_string)+1];
		strcpy(c_string, str.c_string);
		
	}

		
	return *this;
}
String &String::operator+(const String &str){
	
	string first(c_string); string second(str.c_string);
	first+=second;
	c_string=new char[strlen(first.c_str())+1];
	strcpy(c_string,first.c_str());
	
	return *this;
}
String& String::operator++(){
	string str(c_string);
	str+="X";
	int y=strlen(str.c_str());
	++y;
	c_string=new char[y+1];
	strcpy(c_string,str.c_str());
	return *this;
}
String& String::operator++(int){
	string str(c_string);
	str+="X";
	int y=strlen(str.c_str());
	
	c_string=new char[y];
	strcpy(c_string,str.c_str());
	y++;
	return *this;
}
char& String::operator[](int k){
	return c_string[k];
 }

