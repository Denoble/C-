#include "counter.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<iomanip>
class Observer{
	
public:
	virtual void HandleLimitedReach();
	
private:
	char *ptr;
};
void Observer::HandleLimitedReach(){
	string msg("Limit has been reach");
	ptr = new char[strlen(msg.c_str())+1];
	strcpy_s(ptr,strlen(ptr)+1,msg.c_str());
		
		cout<<ptr<<endl;
}

class LimitedCounter: public Counter{
	
public:
	LimitedCounter(int y,int x);
	void setLimit(int y);
	LimitedCounter &operator++();
	LimitedCounter operator++(int);
	void setObserver(Observer* observer);
	
  
     
private:
	int upperLimit;
	Observer *ob;
	void notify();

};
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
	else
		if(count==upperLimit){
			notify();
			reset();
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
	else
		if(count==upperLimit){
			notify();
			reset();
	}
	return oldObject;
	
}
void LimitedCounter::notify(){
	Observer os();
	ob->HandleLimitedReach();
}
void LimitedCounter::setObserver(Observer *os){
	ob=os;
}
class CounterUser: public Observer{
public:
	CounterUser();
	void IncrementBy(int k);
	 void HandleLimitedReach();

private:
	LimitedCounter *lc;

};
void main() {
CounterUser *c = new CounterUser();
c->IncrementBy(12);
delete c;
system("pause");

} //OUTPUT: two times "Limit has been reached"
CounterUser::CounterUser():Observer(){
	lc= new LimitedCounter(0,5);
	lc->setObserver(this);

}
void CounterUser::IncrementBy(int k){
	for(int i=0;i<k;i++){
		lc->operator++();
		

	}
		
}
void CounterUser::HandleLimitedReach(){
	Observer::HandleLimitedReach();

	
} 



