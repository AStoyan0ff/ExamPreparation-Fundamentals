//02.Special Items
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <vector>
using namespace std;

static bool isMagicSymbol(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

static string processStr(const string& input) {
    
    stringstream resultStream; 
    string currWord;
    char lastChar = '\0'; 

    for (size_t i = 0; i < input.size(); i++) {
        char c = input[i];

        if (c == ' ') {
           
            if (!currWord.empty()) {
                resultStream << currWord << ' ';
                currWord.clear();
                lastChar = '\0'; // Нулирам последния символ за следващата дума... 
            }
        }
        else {
           
            if (c != lastChar || isMagicSymbol(c)) {
                currWord += c;
                lastChar = c;
            }
        }
    }
        
    if (!currWord.empty()) {
       
 resultStream << currWord;
    }

    return resultStream.str();
}

int main() {
    
    string input;
    getline(cin, input);

    string result = processStr(input);

    cout << result << endl;

    return 0;
}
