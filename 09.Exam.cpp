// 03.Counting Cattle
#include <iostream>
#include <sstream>
#include <ostream>
#include <vector>
#include <string>
#include <iomanip>
#include <list>
using namespace std;

struct Animal {
    
    char code;
    int size;
};

int main() {
    
    string inputLine;
    getline(cin, inputLine);

    vector<Animal> cows;
    vector<Animal> sheep;
    vector<Animal> others;
       
    for (size_t idx = 0; idx < inputLine.size(); idx += 3) {
        
        char code = inputLine[idx];
        int size = inputLine[idx + 1] - '0'; 

        if (code == 'C') {
            cows.push_back({ code, size });
        }
        else if (code == 'S') {
            sheep.push_back({ code, size });
        }
        else {
            others.push_back({ code, size });
        }
    }
           
    auto calculateAvr = [](const vector<Animal>& animals) {
        
        if (animals.empty()) 
            return 0.0;

        int totalSize = 0;
        
        for (const auto& animal : animals) {
            totalSize += animal.size;
        }
        
        return (double)totalSize / animals.size();
    };
        
    double avgrCows = calculateAvr(cows);
    double avgrSheep = calculateAvr(sheep);
    double avgrOthers = calculateAvr(others);
        
    if (!cows.empty()) {
        cout << cows.size() << " cows: ";
        
        for (const auto& cow : cows) {
            cout << cow.code << cow.size << " ";
        }
        cout << "with avg. size " << setprecision(2) << fixed << avgrCows << endl;
    }
    else {
        cout << "no cows!" << endl;
    }

    if (!sheep.empty()) {
        cout << sheep.size() << " sheep: ";
        
        for (const auto& shep : sheep) {
            cout << shep.code << shep.size << " ";
        }
        cout << "with avg. size " << setprecision(2) << fixed << avgrSheep << endl;
    }
    else {
        cout << "no sheep!" << endl;
    }

    if (!others.empty()) {
        cout << others.size() << " others: ";
        
        for (const auto& other : others) {
            cout << other.code << other.size << " ";
        }
        cout << "with avg. size " << setprecision(2) << fixed << avgrOthers << endl;
    }
    else {
        cout << "no others!" << endl;
    }

    return 0;
}
