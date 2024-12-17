// *Mutate String 
#include <iostream>
#include <string>
#include <vector>
using namespace std;

static void transformString(string str1, string str2) {
    
    vector<string> printString; 
    int sizeString = str1.size();

    for (int idx = 0; idx < sizeString; idx++) {
        
        if (str1[idx] != str2[idx]) {
           
            string temp = str1.substr(0, idx) + str2[idx] + str1.substr(idx + 1);
                        
            bool isUnique = true;
            
            for (const string& ss : printString) {
                
                if (ss == temp) {
                    isUnique = false;
                    break;
                }
            }
                        
            if (isUnique) {
                cout << temp << endl;
                
                printString.push_back(temp);
                str1 = temp; 
            }
        }
    }
}

int main() {
    
    string input, target;
      
    getline(cin, input);
    getline(cin, target);
        
    if (input.size() != target.size()) {
        return 1; 
    }
           
    transformString(input, target);

    return 0;
}
