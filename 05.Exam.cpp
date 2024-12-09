// 02.Secret Message
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <ostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    
    string date;
    getline(cin, date);

    unsigned result = 0;
       
    for (char c : date) {
        
        if (isdigit(c)) {
            
            result += c - '0';
        }
    }
       
    if ((result >= 'A' && result <= 'Z') || (result >= 'a' && result <= 'z')) {
        
        cout << (char)result << endl;
    }
    else {
        
        cout << result << endl;
    }

    return 0;
}
