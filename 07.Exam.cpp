// 01.MIn and Max Avr
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>   
using namespace std;

static vector<int> readNum(int N) {
    vector<int> num(N);
    
    for (int idx = 0; idx < N; idx++) {
        cin >> num[idx];
    }
    
    return num;
}

static int findOdd(const vector<int>& numbers) {
    int maxOdd = numeric_limits<int>::min(); // Min Value
   
    for (size_t idx = 0; idx < numbers.size(); idx++) {
       
        if (idx % 2 == 1) {
            maxOdd = max(maxOdd, numbers[idx]);
        }
    }
    
    return maxOdd;
}

static int findEven(const vector<int>& numbers) {
    int minEven = numeric_limits<int>::max(); // Max Value
    
    for (size_t idx = 0; idx < numbers.size(); idx++) {
        
        if (idx % 2 == 0) {
            minEven = min(minEven, numbers[idx]);
        }
    }
    
    return minEven;
}

static double calculateAvr(const vector<int>& numbers) {
    double results = 0;
    
    for (int number : numbers) {
        results += number;
    }
    return results / numbers.size(); // % cnt num
}

static void printReverse(const vector<int>& numbers) {
    
    for (auto it = numbers.rbegin(); it != numbers.rend(); it++) {
       
        cout << *it; 
        
        if (it + 1 != numbers.rend()) { 
           
            cout << " ";
        }
    }
    
    cout << endl;
}

int main() {
    
    int N;
    cin >> N; 

    vector<int> numbers = readNum(N);
        
    int maxOdd = findOdd(numbers);
    int minEven = findEven(numbers);
    double avr = calculateAvr(numbers);
        
    cout << setprecision(2) << fixed << (double)maxOdd << " "
        
        << (double)minEven << " " << avr << endl;
    
   printReverse(numbers);

    return 0;
}
