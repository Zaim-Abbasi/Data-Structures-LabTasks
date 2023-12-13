#include<iostream>
#include "Header2.h"
using namespace std;
int main() {
	string word;
	char key;
	cout << "Enter a word:";
	cin >> word;
	int size = word.length();
	cout << "Enter a character to search:";
	cin >> key;
	ToSearch(word, size, key);
}