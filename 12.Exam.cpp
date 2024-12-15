// 01. How Many Vowels
#include <iostream>
#include <string>
#include <sstream>
#include <ostream>
#include <vector>
#include <list>
#include <map>
#include <cctype>
#include <algorithm>
using namespace std;

static vector<char> reedFunction(int N) {
	vector<char> myVector(N);

	for (int idx = 0; idx < N; idx++) {
		cin >> myVector[idx];
	}
	return myVector;
}

static bool isVowel(char c) {
	char lowChar = tolower(c); // Conversion to lowerCase 'A' -> 'a'

	return	
		lowChar == 'a' || 
		lowChar == 'e' || 
		lowChar == 'i' ||
		lowChar == 'o' || 
		lowChar == 'u' || 
		lowChar == 'y';
}

int main() {

	int N; cin >> N;

	vector<char> myVector = reedFunction(N);

	int volwelCnt = 0;
	int noVolwelCnt = 0;

	for (char c : myVector) {

		if (isalpha(c)) {
			
			if (isVowel(c)) {
				volwelCnt++;
			}
			else {
				noVolwelCnt++;
			}
		}
	}

	cout << volwelCnt << ' ' << noVolwelCnt << endl;
	return 0;
}