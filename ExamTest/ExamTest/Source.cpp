#include<string>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<time.h>
using namespace std;
class Person{
public:
	Person(char* s,int i);
	
	void operator()(int i);
	void display();
private:
	 string name;
	int age;

};
vector<int> cont2;
int addToContainer(int b){
	srand(time(NULL));
	int y =rand() % 100 + 2;
	cont2.push_back(b + y);
	return b+y;
}
bool sortVect(const int &i, const int &k){
	return i < k;
}
void main(){
	
	vector<int>doubleArray;
	Person p("joyce",4);
	for (int i = 0; i < 10; i++){
		addToContainer(i);
	}
	for_each(doubleArray.begin(), doubleArray.end(), p);
	//copy(doubleArray.begin(), doubleArray.end(), back_inserter(cont2));
	copy(cont2.begin(), cont2.end(), ostream_iterator<int>(cout, "\n "));
	sort(cont2.begin(), cont2.end(), sortVect);
	cout << "sorting array" << endl;
	copy(cont2.begin(), cont2.end(), ostream_iterator<int>(cout, "\n "));
	
	try{

	}
	catch (exception e){
		cout << e.what() << endl;
		auto_ptr<int>k  (new int(10));
	}
	
	system("pause");

}
Person::Person( char* s,int i){
	string m(s);
	name = m;
	 age = i;
}
void Person::operator()( int b){
	srand(time(NULL));
	int y = rand() % 100 + 1;
	cont2.push_back(y + b);
	

}
void Person::display(){
	cout << "Name : " << this->name << endl;
	cout << "Age  :" << this->age << endl;
}