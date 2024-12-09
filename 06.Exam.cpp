// 03.Numbers
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <ostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


static vector<int> readInput() {
   
    string line;
    getline(cin, line);
    
    vector<int> numbers;
   
    stringstream ss(line);
    int num;

    while (ss >> num) {
        
        numbers.push_back(num);
    }

    return numbers;
}

int main() {
   
    vector<int> numbers = readInput();

    double avr = accumulate(numbers.begin(), numbers.end(), 0LL) / (double)numbers.size();
       
    vector<int> aboveAvr;
    
    for (int num : numbers) {
        
        if (num > avr) {
            aboveAvr.push_back(num);
        }
    }
        
    if (aboveAvr.empty()) {
    
        cout << "No" << endl;
        return 0;
    }
        
    sort(aboveAvr.begin(), aboveAvr.end(), greater<int>());
      
    for (size_t i = 0; i < min((size_t)(5), aboveAvr.size()); i++) {
       
        cout << aboveAvr[i];
       
        if (i < min((size_t)(5), aboveAvr.size()) - 1) {
            
            cout << " ";
        }
    }

    cout << endl;
    
    return 0; // Yabba-Dabba_Doo =)
}
