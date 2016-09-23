#include<iostream>
#include<string>
#include<cstdlib>
#include<iomanip>
#include"counter.h"
using namespace std;
class LimitedCounter{
	friend ostream &operator<<(ostream &out, const LimitedCounter &lc);
public:
	LimitedCounter(int y,int x);
	void setLimit(int x,int y);
	LimitedCounter &operator++();
	LimitedCounter operator++(int);
    bool operator<(const int &c2) const;
	~LimitedCounter();
	//LimitedCounter& operator=(const LimitedCounter &lc);
	LimitedCounter(const LimitedCounter &ref);
    void reset();
	int getCount() const;
	 
private:
	int upperLimit;
	int initValue;
	Counter count;
	int currentValue;
	Counter * obj;
};

void main(){
	LimitedCounter lc(0, 5); //initial value 0, upper limit 5
	cout << lc++ << endl; //output should be 0
	cout << ++lc << endl; //output should be 2
	lc.reset();
	for (int i = 0; i < 9; i++) {
		lc++;
	cout << lc << endl;
	}
	
	cout << lc.getCount() << endl;
	cout << (lc < 7);//Testing the comparison operator
	cout << (lc < 1);//Testing the comparison operator
	system("pause");
}
LimitedCounter::LimitedCounter(int xx,int yy){
	
	setLimit(xx,yy);
	obj = new Counter(yy);
	 


	
}
void LimitedCounter::setLimit(int xx,int yy){
	upperLimit=yy;
	initValue=xx;
	count=Counter(xx);
	currentValue=getCount();
}
LimitedCounter& LimitedCounter::operator++(){
	if(currentValue<upperLimit){
		++(*this).currentValue;
	}
	return *this;
}
LimitedCounter LimitedCounter:: operator++(int){
	LimitedCounter oldObject(0,1);
	if(currentValue<upperLimit){
	
		oldObject= *this;
		(*this).currentValue++;
	}
	return oldObject;
	
}
void LimitedCounter:: reset() {// resets LimitedCounter
	count.reset();
}
bool  LimitedCounter:: operator<(const int &lc2) const{
	return count.operator<(Counter(lc2));

}
int LimitedCounter::getCount()const{
	return this->count.getCount();
}
ostream &operator<<(ostream &out, const LimitedCounter &lc){
	cout<<lc.currentValue<<endl;
	return out;
}
LimitedCounter::~LimitedCounter(){
	delete obj;
}

LimitedCounter::LimitedCounter(const LimitedCounter &object){
	
	upperLimit = object.upperLimit;

	initValue=object.initValue;
	 count=object.count;
	 currentValue=object.currentValue;
	 obj=object.obj;
	

	
}

