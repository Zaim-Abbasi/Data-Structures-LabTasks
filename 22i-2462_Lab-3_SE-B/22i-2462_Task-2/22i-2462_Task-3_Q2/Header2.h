#pragma once
#include<iostream>
using namespace std;
void ToSearch(string word, int size, char key) {
	int position = -1;
	for (int i = 0; i < size; i++) {
		if (word[i] == key)
			position = i;
	}
	cout << "Character Found!!" << endl;
	cout << "Output:";
	for (int i = position; i < size; i++) {
		cout << word[i];
	}
	cout << endl;
}
