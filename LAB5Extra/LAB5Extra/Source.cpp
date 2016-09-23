#include <iostream>
#include <fstream>
#include<string>
#include <stdlib.h>
#include<time.h>

#define _CRT_RAND_S
#ifdef _DEBUG // Active only in Debug Configuration
#define _CRTDBG_MAP_ALLOC // Visual Studio Mem Leak detector activated
#include <crtdbg.h>
#endif
using namespace std;
class SpeechSelector{
	public:
		string * groupG(string * ss);
		string *groupA(string *ss);
		string *groupS(string *ss);
		string groupV(string *ss);
		string *sourceSpeech(string filename);
		string speechPage(string filename);
		string generateSpeach(string filename);
		string page,readword;
	private:
		int counter;
};

int  random(int n);
int randomize();
string page,readword,presidentSpeech;
void main(){

	SpeechSelector presidentSpeech;
 cout << presidentSpeech.speechPage("oracle.dat") << endl;
 
#ifdef _DEBUG
if (_CrtDumpMemoryLeaks())
cout << "WARNING: There was memory leak in your program" << endl;
else
cout << "Your program has no memory leaks, congratulations!" << endl;
#endif
 unsigned int value,no;
 errno_t err= rand_s(&value);
 cout<<<<endl;
system("PAUSE");
 
 
 
  //cout<<index<<endl;
 
	system("pause");
}
int  random(int n){
	
	
	int y= rand()%n;
	return y;

}
int randomize(){
	srand(time(0));
	int y= rand()%15+4;
	return y;
}
string* SpeechSelector::sourceSpeech(string ff){
	string *speechSource=new string[93];
	int index=0;int counter=0;
	ifstream dbfile(ff);
	while(!dbfile.eof()){
		dbfile>>readword;
		page.append(readword);
		speechSource[index]=readword;
		index++;
	}
	return speechSource;

}
string SpeechSelector::speechPage(string filename){
	ifstream dbfile(filename);
	while(!dbfile.eof()){
		dbfile>>readword;
		page.append(readword);
	
	}

	return page;
}
string * SpeechSelector::groupA(string *ss){
	string * strAA=new string[100];
  for(int i=25;i<93;i++){
	string mst =ss[i];
	strAA[counter]=ss[i];
	counter++;
	if(mst=="[S]"){
		cout<<"breaking loop"<<endl;
		cout<<"At array number:"<<i<<endl;
		counter=0;
		break;
	}
 }
  return strAA;

}
string* SpeechSelector::groupG(string *ss){
	string * strGG=new string[25];
 for(int i=1;i<100;i++){
	 string mst =ss[i];
	strGG[counter]=ss[i];
	counter++;
	if(mst=="[A]"){
		cout<<"breaking loop"<<endl;
		cout<<"At array number:"<<i<<endl;
		counter=0;
		break;
	}
	
 }
 return strGG;

}
string * SpeechSelector::groupS(string *ss){
	string * strSS = new string[100];
  for(int i=43;i<100;i++){
	 string mst =ss[i];
	strSS[counter]=ss[i];
	counter++;
	if(mst=="[V]"){
		cout<<"breaking loop"<<endl;
		cout<<"At array number:"<<i<<endl;
		counter=0;
		break;
	}
 }
  return strSS;
}
string SpeechSelector::groupV(string *ss){
	
 string *strVV = new string[27];
 string speechstr;
  for(int i=66;i<93;i++){
	 string mst =ss[i];
	strVV[counter]=ss[i];
	counter++;
 }
  
  
  counter=0;
  return speechstr;
}
string SpeechSelector::generateSpeach(string filename){
	string *sourceString=sourceSpeech(filename);
	string * strG=groupG(sourceString);
	string* strA=groupA(sourceString);
	string *strS=groupS(sourceString);
	string strV=groupV(sourceString);
	errno_t rand_s(40);
	return strV;
}