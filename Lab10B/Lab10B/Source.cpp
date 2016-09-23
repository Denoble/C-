#include<iostream>
#include<string>
#include<vector>
using namespace std;

void main(){
	string enterWordFromKeyboard;
	char* forbidWord = new char[5];
	forbidWord = "stop";
	int index = 0;
	vector<string>strArray;
	while (true){
		cout << "Enter a word from keyboard ! :" << endl;
		cin >> enterWordFromKeyboard;
		
		if (strcmp(enterWordFromKeyboard.c_str(), forbidWord) != 0){
			if (index < strArray.capacity()){
				strArray.at(index)=enterWordFromKeyboard;
				index++;
			}
			else{
				strArray.resize(index + 10);
				cout << "Please re-enter the word again" << endl;
				continue;
			}
				
		}
		else{
			cout << "stop encounter !" << endl;
			break;
		}
	}
	for (int k = 0; k < index; k++){
		cout << strArray.at(k) << endl;
	}
	cout << "Number of strings entered: " << index << endl;
	cout << "My system memory size of string object: " << sizeof(strArray) << endl;
	cout << "Number of elements in the vector array: " << strArray.size() << endl;
	cout << "Number of elements the vector can hold before memory reallocation: " << strArray.capacity() << endl;
	
	system("pause");
}