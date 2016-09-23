#include<iostream>
#include<string>
#include<time.h>

using namespace std;
class Dice{
	public:
		void initialize();
		float roll();
	private:
		float outCome;
};
class Counter{
	public:
		
		int getCount();
		void reset();
		void increment();
	private:
		int count;
};
class Inspector{
	public:
		void setLimits(float y,float x);
		bool isInLimits(float y);
	private:
		float maxNum;
		float minNum;
};
void main( ) {
	Dice dice;
	Counter counter1, counter2, i;
	Inspector inspector;
	dice.initialize();
	counter1.reset(); counter2.reset(), i.reset();
	inspector.setLimits(0, 0.5);
	srand(time(0));
	while (i.getCount() < 100) {
		if (inspector.isInLimits(dice.roll()))
			counter1.increment();
		else
			counter2.increment();
		i.increment();
	}
	cout << counter1.getCount()<<endl;
	cout << counter2.getCount();
	fflush(stdin);getchar();
}
void Dice::initialize(){
	outCome=0.0;
}
float Dice::roll(){
	int num=rand()%10;
	outCome= num*0.1;
	return outCome;
}
void Counter::reset(){
	count=0;
}
void Counter::increment(){
	count++;
}
int Counter::getCount(){
	return count;
}
void Inspector::setLimits(float x,float y){
	minNum=x;maxNum=y;
}
bool Inspector::isInLimits(float y){
	if(y>minNum && y<maxNum)
		return true;
	else
		return false;
}