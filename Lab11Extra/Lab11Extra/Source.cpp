#include <iostream>
#include<vector>
#include<time.h>
#include <fstream>
#include<string>
#include<iterator>
#include<algorithm>
#include<map>
//#include<sstream>
using namespace std;
class RandGen_2 {
public:
	RandGen_2() : numbers() { srand(time(NULL)); }
	int operator()();
private:
	vector<int> numbers;
};
class Athlete{
public :
	Athlete();
	bool isLaterThan(Athlete runner1, Athlete runner2);
	
	void ReadName(string yy);
	void ReadTime();
	bool better(Athlete &at1, Athlete &at2);
	void ReadNum(Athlete& r);
	void display();
private:
	string name;
	int time;
	
	int num;
};
Athlete *a;
char* name;
char* minString;
int index;
struct field_reader : ctype<char> { // specify '\n' as the only separator
	field_reader() : ctype<char>(get_table()) {}
	static ctype_base::mask const *get_table() {
		static vector<ctype_base::mask>
			rc(table_size, ctype_base::mask());
		rc['\n'] = ctype_base::space;
		return &rc[0];
	}
};
ifstream myfile("athlete-1.txt");
vector<string>names;
vector<int> numbers(10);
vector<Athlete>athletes;
void InstantiateAthlete(Athlete &r);
void main(){
	
	
	vector<string>::iterator strt;
	vector<Athlete>::iterator it;
	 index = 0;
	 
	myfile.imbue(locale(locale(), new field_reader()));// use our own separator list
	istream_iterator<string> iit(myfile);
	copy(iit, istream_iterator<string>(), names.begin());
	RandGen_2 randGen_2;
	generate(numbers.begin(), numbers.end(), randGen_2);

	for_each(names.begin(), names.end(), InstantiateAthlete);
	
	
	
	
	system("pause");
}
int randGen_1() {
	return rand() % 10 + 1;
}
//Function object

int RandGen_2::operator()() {
	int number;
	do {
		number = rand() % 10 + 1;
	} while (find(numbers.begin(), numbers.end(), number) != numbers.end());
	numbers.push_back(number);
	return number;
}
Athlete::Athlete(){
	
}
void Athlete::display(){
	cout << this->num << " " << this->name  << "  " << this->time << "  " <<  endl;
}
bool Athlete::isLaterThan(Athlete runner1, Athlete runner2){
	
	return runner1.time < runner2.time;
}
void Athlete::ReadName( string yy){
	 a->name = yy;
	 
	 ReadTime();
	 ReadNum(*this);
}
void Athlete::ReadTime(){
	cout << " \n Give time for " << this->name << " :";
	char* timeStr = new char[5];
	
	cin >> timeStr;
	this->time = atoi(timeStr);
	

}
void Athlete::ReadNum(Athlete& r){
	r.num = numbers.at(index);
}
void InstantiateAthlete(string yy){
	Athlete r();
    
	
}
