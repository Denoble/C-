#include<iostream>
#include<string>

using namespace std;
class String{
	friend ostream &operator<<(ostream &out, const String &alphabet);
	public:
		static int objectCounter;
		String( const char* name );
		 String();
		String(const String &b);
		
		void list();
		
		~String();
		String& operator=(const String &str);
		String& operator+(const String &str);
		String& operator++();
		String& operator++(int);
		char& operator[](int k);
		const static int MAX_STRING_LENGTH=10;
		 
	
		char  * c_string;
};
void f(String s);
void display();
void main(){
	display();
	{

		String array[4];
		display();
	}

	display();
	fflush(stdin);getchar();
}
int String::objectCounter=0;
String::String( const char * name){
	
	c_string= new char[strlen(name)+1];
	string str(name);
	str.resize(MAX_STRING_LENGTH);
	strcpy_s(c_string,str.length()+1,str.c_str());
	objectCounter++;
	
	
}
String::String(){
	c_string=new char;
	string str(c_string);
	str.resize(MAX_STRING_LENGTH);
	strcpy_s(c_string,str.length()+1,str.c_str());
	objectCounter++;
}
void String:: list(){
	cout<<c_string<<endl;
}
void f(String s){
	s.list();
}

String::String(const String &b){
	c_string=new char[strlen(b.c_string)+1];
	string str(b.c_string);
	str.resize(MAX_STRING_LENGTH);
	strcpy_s(c_string,str.length()+1,str.c_str());
	objectCounter++;
}
String::~String(){
	
	cout<<"freeing memory"<<endl;
	objectCounter--;
	//delete c_string;
	
}
ostream &operator<<(ostream &out, const String &alphabet){
	cout<< alphabet.c_string<<endl;
	return out;

}
String &String::operator=(const String &str){
	c_string=str.c_string;
		
	return *this;
}
String &String::operator+(const String &str){
	
	string first(c_string); string second(str.c_string);
	first+=second;
	c_string=new char[strlen(first.c_str())+1];
	strcpy_s(c_string,first.length()+1,first.c_str());
	
	return *this;
}
String& String::operator++(){
	string str(c_string);
	str+="X";
	int y=strlen(str.c_str());
	++y;
	c_string=new char[y+1];
	strcpy_s(c_string,str.length()+1,str.c_str());
	return *this;
}
String& String::operator++(int){
	string str(c_string);
	str+="X";
	int y=strlen(str.c_str());
	
	c_string=new char[y];
	strcpy_s(c_string,str.length()+1,str.c_str());
	y++;
	return *this;
}
char& String::operator[](int k){
	return c_string[k];
 }
void display(){

	cout<<String::objectCounter<<endl;
}

