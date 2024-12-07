//01. Below Average Only
#include <iostream>
#include <sstream>
#include <ostream>
#include <vector>
#include <list>
#include <iomanip>
using namespace std;


int main() {

    int N;
    cin >> N;
        
    vector<int> arr(N);
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
        
    double sum = 0;
   
    for (int num : arr) {
        sum += num;
    }
    double average = sum / N;
        
    vector<int> belowAvg;
    
    for (int num : arr) {
        
        if (num <= average) {
            belowAvg.push_back(num);
        }
    }

   
    int evenSum = 0, oddSum = 0;
    
    for (size_t i = 0; i < belowAvg.size(); i++) {
        
        if (i % 2 == 0) { 
            evenSum += belowAvg[i];
        }
        else {          
            oddSum += belowAvg[i];
        }
    }
        
    int result = evenSum * oddSum;
    
    cout << result << endl;


	return 0;
}
