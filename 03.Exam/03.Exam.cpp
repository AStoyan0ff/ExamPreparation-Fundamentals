//03.Machine Commands
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    
    vector<int> myVector; 
    string line;

    while (getline(cin, line)) {
       
        if (line == "end") {
            break; 
        }

        if (line == "sum") {
            int a = myVector.back(); myVector.pop_back();
            int b = myVector.back(); myVector.pop_back();
            
            myVector.push_back(a + b);
        }
        else if (line == "subtract") {
           
            int a = myVector.back(); myVector.pop_back();  //(a - b) add the result back...
            int b = myVector.back(); myVector.pop_back();
            
            myVector.push_back(a - b);
        }
        else if (line == "concat") {
            int a = myVector.back(); myVector.pop_back();
            int b = myVector.back(); myVector.pop_back();
            
            string concatResult = to_string(b) + to_string(a);
            myVector.push_back(stoi(concatResult));
        }
        else if (line == "discard") {
            myVector.pop_back();
        }
        else {
            myVector.push_back(stoi(line)); // String to Integer ... 
        }
    }
        
    for (int num : myVector) {
        
        cout << num << endl;
    }

    return 0;       //Yabba-Dabba-Doo =)
}
