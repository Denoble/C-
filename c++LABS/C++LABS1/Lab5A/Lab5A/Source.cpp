#include <string>
#include <iostream>
using namespace std;

class String {
	friend ostream &operator<<(ostream &out, const String &s);
	public:
		String(char *v);
		String();
		String (const String &s);
		~String();
		friend String operator+(const String &s1, const String &s2);
		const String &operator=(const String &s);
		
		String operator++();
		operator char*();
		String operator++(int);
		char& operator[](int);
		void list();
	private:
		char *c_string;

};

void f(String s);
void main() {
	String s;
	char name[30];
	s = "Matti"; //Conversion c-string -> String
	cout << s;
	strcpy(name, s); //Conversion String -> c-string
	cout << name;
	system("pause");
}

void String::list(){
	cout << c_string;
}
String::String(char *v){
	c_string = new char[strlen(v)+1];
	strcpy(c_string ,v);
}
String::~String(){
	
	delete c_string;
}
String::String(const String &s){
	   c_string = new char[strlen(s.c_string)+1];
	   strcpy(c_string, s.c_string);
	   //c_string = s.c_string;
}
String::String(){
	c_string = new char;
}
const String& String::operator=(const String &s){
	if(this != &s){
		delete c_string;
		c_string = new char[strlen(s.c_string)+1];
		strcpy(c_string, s.c_string);
	}
	return *this;
}
String operator+(const String &s1, const String &s2){
	String s3;
	s3.c_string = new char[strlen(s1.c_string)+strlen(s2.c_string)+2];
	strcpy(s3.c_string, s1.c_string);
	strcat(s3.c_string, s2.c_string);
	return s3;
}

//friend String operator+(const String &s1, const String &s2);
ostream &operator<<(ostream &out, const String &s){
	out << s.c_string;
	return out;
}
String String::operator++(int d){
	String old = *this ;
	*this = *this + String("x");
	return old;
}
String String::operator ++(){
	*this = *this + String("x");
	return *this;
}

char& String::operator[](int i){
	return c_string[i];
}

String::operator char*(){
	 return c_string;
}




void f(String s){
	s.list();
}