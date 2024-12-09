// 03.Punctuation
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

static bool isPunctuation(char c) {
   
    const string punctuation = R"(!"#$%&'()*+,-./:;<=>?@[]^_`{}~)";
    return punctuation.find(c) != string::npos;
}

static int cntPunctuation(const string& sentence) {
    return count_if(sentence.begin(), sentence.end(), isPunctuation);
}


static map<int, vector<string>> processEss(const string& text) {
    
    vector<string> sentences;
    string currSentence;
        
    for (char c : text) {
        if (c == '|') {
            
            if (!currSentence.empty()) {
               
                sentences.push_back(currSentence);
                currSentence.clear();
            }
        }
        else {
           
            currSentence += c;
        }
    }
       
    map<int, vector<string>> groupSentences;
    
    for (const string& sentence : sentences) {
       
        int punctuationIdx = cntPunctuation(sentence);
        groupSentences[punctuationIdx].push_back(sentence);
    }

    return groupSentences;
}

int main() {
   
    string text;
    getline(cin, text);
        
    map<int, vector<string>> groupSentences = processEss(text);

    
    for (const auto& entry : groupSentences) {
        
        cout << entry.first << " symbol sentences: " << entry.second.size() << endl;
    }

    return 0;
}
