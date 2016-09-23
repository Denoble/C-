#include<iostream>
#include<string>
#include<vector>
using namespace std;
template<class type1,class type2>
class TPair{
public:
	TPair();
	TPair(const type1& T1,const type2& T2);
	
	type1 getFirst() const;
	type2 getSecond() const;
	void displayPairs();
private:
	type1 first;
	type2 second;
};
template<typename type1, typename type2>
TPair<type1, type2>::TPair():first(type1()),second(type2()){

}
template<typename type1, typename type2>
TPair<type1, type2>::TPair(const type1& T1, const type2& T2): first(T1),second(T2){
	
	
	
}
template<typename type1, typename type2>
type1 TPair<type1, type2>::getFirst()const{
	return first;
	
}
template<typename type1, typename type2>
type2 TPair<type1, type2>::getSecond() const{
	return second;

}
template<typename type1, typename type2>
void TPair<type1, type2>::displayPairs(){
	cout << getFirst(); cout << "  ";
	cout << getSecond() << endl;
	
}
