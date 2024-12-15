//01.Fun Sequence
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

static void readNumbers(vector<int>& numbers, int size) {
    
    for (int idx = 0; idx < size; idx++) {
        
        int num;
        cin >> num;
        numbers.push_back(num);
    }
}

static double calculateAvrg(const vector<int>& numbers) {

    double result = 0;

    for (int num : numbers) {
        result += num;
    }
    
    return result / numbers.size();
}

static vector<int> findNumbers(const vector<int>& numbers, double avrg) {
    
    vector<int> sum;

    for (int num : numbers) {
        
        if (num % 2 == 0 && num < avrg) {
            sum.push_back(num);
        }
    }
    
    sort(sum.rbegin(), sum.rend());
    return sum;

}
int main() {

    int size; cin >> size;

    if (size <= 0) {
        cout << "No" << endl;
        return 0;
    }

    vector<int> numbers;
    readNumbers(numbers, size);

    double avrg = calculateAvrg(numbers);
    vector<int> findNum = findNumbers(numbers, avrg);

    if (findNum.empty()) {
        cout << "No" << endl;
    }
    else {
        for (size_t idx = 0; idx < findNum.size(); idx++) {

            cout << findNum[idx];
            
            if (idx < findNum.size() - 1) cout << " ";
        }
            
        cout << endl;
    }

	return 0;
}