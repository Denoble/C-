
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
int UseCounter(LimitedCounter* cc,int n);
int UseCounter(RoundupCounter* cc,int j);
void main(){
	
	LimitedCounter counterA(0, 5);
		RoundupCounter counterB(0, 5);
		Counter counterc(0);
		UseCounter(&counterA, 8); UseCounter(&counterB, 8);
	cout << "Counter A: " << counterA << endl; // output should be 5
	cout << "Counter B: " << counterB << endl; // output should be 2
	
	
	
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
	
		oldObject= *this;
		Counter::operator++(0);
	}
	return oldObject;
	
}
RoundupCounter::RoundupCounter(int x,int y): Counter(x){
	setLimit(y);
}
void RoundupCounter::setLimit(int y){
	upperLimit=y;
}
RoundupCounter &RoundupCounter:: operator++(){
	int no= getCount();
	
	if(no<upperLimit){
		Counter::operator++();
	}
	else
		reset();
	return *this;
}
RoundupCounter RoundupCounter:: operator++(int){
	int no= getCount();
	RoundupCounter old =*this;
	if(no<upperLimit){
		Counter::operator++(0);
	}
	else
		reset();
	return old;
}

int UseCounter(RoundupCounter* cc,int i){
	int k,b=0;
	for(k=0;k<i;k++){
		cc->operator++();
		b=cc->getCount();
	}
	return b;
 }
int UseCounter(LimitedCounter* cc,int i){
	int k,b=0;
	for(k=0;k<i;k++){
		cc->operator++();
		b=cc->getCount();
	}
	return b;
 }
