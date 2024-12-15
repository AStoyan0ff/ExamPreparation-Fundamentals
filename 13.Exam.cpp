// 02.Calculation
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
   
    int currentValue = 0; 
    int previousValue = 0; 
   
    string input;           

    getline(cin, input);    
    stringstream ss(input); 

    string operation;
   
    while (ss >> operation) {
        if (operation == "+" || operation == "-" || operation == "*" || operation == "/") {
           
            int buffer = currentValue;
            if (operation == "+") {
                currentValue = previousValue + currentValue;
                previousValue = buffer;
            }
            else if (operation == "-") {
                currentValue = previousValue - currentValue;
                previousValue = buffer;
            }
            else if (operation == "*") {
                currentValue = previousValue * currentValue;
                previousValue = buffer;
            }
            else if (operation == "/") {
                currentValue = previousValue / currentValue; 
                previousValue = buffer;
            }
        }
        else {
            
            previousValue = currentValue;
            currentValue = stoi(operation); 
        }
    }
        
    cout << currentValue << " " << previousValue << endl;

    return 0;
}
