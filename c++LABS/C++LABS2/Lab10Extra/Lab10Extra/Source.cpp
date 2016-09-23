#include<iostream>
#include<string>
#include<vector>
using namespace std;
void main(){
	vector<vector<int>>intDDArray(2);
	int NoElementInDDArray = 0;
	int index = 0;

		vector<int>intArray(4); 
		vector<int>intArray1(4);
		int input; string inputString;
		for (int i=0; i < 4; i++){
			cout << "Enter integer from keyboard:" << endl;
			cin >> inputString;
			input = stoi(inputString);
			intArray.at(i) = input;
		}
		intDDArray.at(index) = intArray;
		index++;
		for (int i = 0; i < 4; i++){
			cout << "Enter integer from keyboard:" << endl;
			cin >> inputString;
			input = stoi(inputString);
			intArray1.at(i) = input;
		}
		intDDArray.at(index) = intArray1;
		index++;
		cout << " " << endl;
	for (int k = 0; k < index; k++){
		for (int i = 0; i < 4; i++){
			cout << intDDArray.at(k).at(i) <<" ";
			
		}
		cout << " " << endl;
	
	}
	system("pause");
}