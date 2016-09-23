//: C04:Intset.cpp
// Simple use of STL set
#include <set>
#include <iostream>
#include<vector>
#include<time.h>
#include<algorithm>
#include <string>
#include <fstream>

using namespace std;
int *t;

int randGen_1() {
	return rand() % 10 + 1;
}
//Function object
class RandGen_2 {
public:
	RandGen_2() : numbers() { srand(time(NULL)); }
	int operator()();
private:
	vector<int> numbers;
};
void printInt(int);
void PrintNoDublicate(int);
void main(void) {
	vector<int> numbers(7);
	vector<int>numbers2(7);
	vector<int>similarNumbers(7);
	RandGen_2 randGen_2;
	RandGen_2 randGen_3;
	generate(numbers.begin(), numbers.end(), randGen_2);

	
	cout << "First lotto row: " ;
	copy(numbers.begin(), numbers.end(),ostream_iterator<int>(cout, " "));
	generate(numbers2.begin(), numbers2.end(), randGen_3);
	
	cout << endl;
	cout << "Second lotto row: ";
	copy(numbers2.begin(), numbers2.end(), ostream_iterator<int>(cout, " "));
	cout <<"\n"<< "Same number:" << endl;
	
	sort(numbers.begin(), numbers.end());
	sort(numbers2.begin(), numbers2.end());
	
	vector<int>::iterator iter;
	 iter=set_intersection(numbers.begin(),numbers.end(),numbers2.begin(),numbers2.end(),similarNumbers.begin());
	 similarNumbers.resize(iter-similarNumbers.begin());
	
	t =new int;
	*t = 1;
	for_each(similarNumbers.begin(), similarNumbers.end(), PrintNoDublicate);
	
	system("pause");
}
int RandGen_2::operator()() {
	int number;
	do {
		number = rand() % 37 + 1;
	} while (find(numbers.begin(), numbers.end(), number) != numbers.end());
	numbers.push_back(number);
	return number;
}
void printInt(int n){
	cout << n << endl;

}
void PrintNoDublicate(int i){
	cout << "Nr " << *t << " : " << i << endl;
	(*t)++;
	
}
