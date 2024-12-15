// 03.Train Compopsition
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

static void printTrain(const vector<string>& train) {
    cout << "|";
   
    for (const auto& wagon : train) {
        if (wagon.empty()) {
            cout << " |"; 
        }
        else {
            cout << wagon << "|";
        }
    }
    cout << endl;
}

static void moveWagon(vector<string>& train, int oldPos, int newPos) {
    oldPos -= 1;  
    newPos -= 1;
        
    string wagon = train[oldPos];
    
    train.erase(train.begin() + oldPos); 
    train.insert(train.begin() + newPos, wagon); 
    
    printTrain(train); 
}

static void leaveWagon(vector<string>& train, int wagonPos) { // erese wagon
    wagonPos -= 1;  
    train.erase(train.begin() + wagonPos);
    
    printTrain(train); 

}

int main() {
    
    vector<string> train; 
    string input;
       
    while (getline(cin, input)) {
        if (input == "end") {
            break; 
        }
        else if (input == "empty") {
            train.push_back(""); // empty wagon
        }
        else {
            train.push_back(input); // add wagon
        }
    }
       
    while (getline(cin, input)) {
        
        if (input == "E") {
            break; 
        }
        else if (input == "P") {
            printTrain(train); 
        }
        else if (input[0] == 'M') {
            int oldPos, newPos;
            stringstream ss(input);
            char cmd;
            ss >> cmd >> oldPos >> newPos; 
           
            
            moveWagon(train, oldPos, newPos);
           
        }
        else if (input[0] == 'L') {
            int wagonPos;
            stringstream ss(input);
            char cmd;
            ss >> cmd >> wagonPos; 
           
            
            leaveWagon(train, wagonPos); // erese wagon
        }
    }

    return 0;
}
