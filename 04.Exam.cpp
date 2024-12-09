// 01. Shooting
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main() {

    string input;
    getline(cin, input);

    istringstream iss(input);

    vector<int> targets;
    int value;

    while (iss >> value) {
        targets.push_back(value);
    }

    int shotTargetCnt = 0;

    string cmd;

    while (getline(cin, cmd) && cmd != "End") {
        int index = stoi(cmd);

        if (index >= 0 && index < (int)(targets.size()) && targets[index] != -1) {

            int shotValue = targets[index];
            targets[index] = -1;
            shotTargetCnt++;

            for (int i = 0; i < (int)(targets.size()); i++) {
                if (targets[i] == -1)
                    continue;

                if (targets[i] > shotValue) {
                    targets[i] -= shotValue;
                }
                else {
                    targets[i] += shotValue;
                }
            }
        }
    }

    cout << "Shot targets: " << shotTargetCnt << " -> ";

    for (int target : targets) {
        cout << target << " ";
    }

    cout << endl;

    return 0; //Yabba-Dabba-Doo =)
}
