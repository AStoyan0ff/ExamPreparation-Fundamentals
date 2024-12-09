// 02. Super Large Numbers Comparison
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ostream>
#include <list>
using namespace std;

static vector<string> split(const string& str) {
    
    vector<string> result;
    istringstream iss(str);
    string temp;
    
    while (iss >> temp) {
        result.push_back(temp);
    }
   
    return result;
}

int main() {
    
    string line, date;
       
    getline(cin, line);
    getline(cin, date);
       
    vector<string> myVectorAndrey = split(line);
    vector<string> myVectorStoyanov = split(date);
        
    size_t maxSize = max(myVectorAndrey.size(), myVectorStoyanov.size());
    string result;
       
    for (size_t idx = 0; idx < maxSize; idx++) {
       
        if (idx < myVectorAndrey.size() && idx < myVectorStoyanov.size()) {
           
            if (myVectorAndrey[idx].size() > myVectorStoyanov[idx].size()) {
                result += '<'; 
            }
            else if (myVectorAndrey[idx].size() < myVectorStoyanov[idx].size()) {
                result += '>'; 
            }
            else {
                
                if (myVectorAndrey[idx] == myVectorStoyanov[idx]) {
                    result += '=';
                }
                else if (myVectorAndrey[idx] < myVectorStoyanov[idx]) {
                    result += '>';
                }
                else {
                    result += '<';
                }
            }
        }
        else if (idx < myVectorAndrey.size()) {
            result += '+';
        }
        else {
            result += '-';
        }
    }
        
    cout << result << endl;

    return 0;
}

