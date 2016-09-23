#include<iostream>
#include<string>
#include<cstdlib>
#include<iomanip>
#include"counter.h"
using namespace std;
class LimitedCounter: public Counter{
	
public:
	LimitedCounter(int y,int x);
	void setLimit(int y);
	LimitedCounter &operator++();
	LimitedCounter operator++(int);
private:
	int upperLimit;
	


};
class RoundupCounter: public Counter{
	public:
	RoundupCounter(int y,int x);
	void setLimit(int y);
	RoundupCounter &operator++();
	RoundupCounter operator++(int);
  
     
private:
	int upperLimit;
	
	
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
LimitedCounter::LimitedCounter(int xx,int yy):Counter(xx){
	
	setLimit(yy);
}
void LimitedCounter::setLimit(int yy){
	upperLimit=yy;

}
LimitedCounter& LimitedCounter::operator++(){
	int count=getCount();
	if(count<upperLimit){
		Counter::operator++();
	}
	return *this;
}
LimitedCounter LimitedCounter:: operator++(int){
	LimitedCounter oldObject =*this;
	int count=getCount();
	if(count<upperLimit){
	
		
		Counter::operator++(0);
	}
	return oldObject;
	
}

