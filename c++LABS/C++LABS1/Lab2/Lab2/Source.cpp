#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>
#include<iomanip>
using namespace std;
class Time{
	public:
		void read(string whatTodo);
		Time subtract(Time time);
		bool lessThan(Time time);
		void display();

	private:
		int hour;
		int min;

};
int main(){
	Time time1, time2, duration;
	time1.read("Enter start time  in this format hh mm");
	time2.read("Enter end time  in this format hh mm");
	if (time1.lessThan(time2)) {
		duration = time2.subtract(time1);
		cout << "Starting time was ";
		time1.display();
	}
	else {
		duration = time1.subtract(time2);
		cout << "Starting time was ";
		time1.display();
	}
	cout << "Duration was ";
	duration.display();

	fflush(stdin);getchar();
	return 0;
}
void Time::read(string whatToDo){
	cout<< whatToDo<<endl;
	cin>>hour>>min;
}
Time Time::subtract(Time time){
	Time timeDiff;int time3;
	int time2 = hour*60+min;
	int time1= time.hour*60+time.min;
	time3=time2-time1;
	timeDiff.hour=time3/60;
	timeDiff.min=time3%60;
	return timeDiff;
}
bool Time::lessThan(Time time){
	return (hour<time.hour)?true:false;
}
void Time::display(){
	cout<<hour<< ":"<<min<<endl;
}