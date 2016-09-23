/* vdestructor.cpp -- Polymorphism and virtual destructor */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person {
public:
	Person(char *name0 = "", int age0=0);
	virtual ~Person();
	virtual void sayHello() const;

private:
	char name[20];
	int age;
};

class Female: public Person {
public:
	Female(char *name0="", int age0=0, int noOfSkirts=0, const char *maidenName0=NULL);
	virtual ~Female();
	virtual void sayHello() const;
private:
	int numberOfSkirts;
	char *maidenName;
};

class Male: public Person {
public:
	Male(char *name0="", int age0=0, int numberOfTies0=0);
	virtual ~Male();
	virtual void sayHello() const;
private:
	int numberOfTies;
};

void main(void) {
	Person *personArray[2];

	Male *matti = new Male("Matti", 20, 5);
	Female *maija = new Female("Maija", 19, 10, "xxxxxxxx");
	personArray[0] = matti;       //assignment is OK Person* <- Male*
	personArray[1] = maija;       //assignment is OK„ Person* <- Female*
	for (int i = 0; i < 2 ; i++) {
		personArray[i]->sayHello(); //they say hello as defined in derived class
	}
	for (int i = 0; i < 2 ; i++)
		delete personArray[i];
}

//Member functions of person
Person::Person(char *name0, int age0) {
	strcpy(name,name0);
	age  = age0;
}
Person::~Person() {
	cout << "\nDestructor of class Person is done ";
}
void Person::sayHello() const{
	cout << "\nHi, my name is " <<  name ;
}

//Member functions of female
Female::Female(char *name0, int age0, int noOfSkirts0, const char *maidenName0): Person(name0, age0) {
	numberOfSkirts = noOfSkirts0;
	if (maidenName0) {
		maidenName = new char[strlen(maidenName0) + 1];
		strcpy(maidenName, maidenName0);
	}
	else
		maidenName = NULL;
};
Female::~Female() {
	if (maidenName)
		delete maidenName;
	cout << "\nDestructor of class Female is done ";
	//destructor of base class is called automatically
}
void Female::sayHello() const {
	Person::sayHello();
	cout << " (a curtsey)";
}

//Member functions of male
Male::Male(char *name0, int age0, int noOfTies0) : Person(name0, age0) {
	numberOfTies = noOfTies0;
}
Male::~Male() {
	cout << "\nDestructor of class Male is done ";
	//destructor of base class is called automatically
}
void Male::sayHello() const{
	Person::sayHello();
	cout << " (a deep bow)";
}
