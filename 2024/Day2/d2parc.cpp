#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<vector<int>> rows;   // each line becomes one vector<int>
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  // skip blank lines

        stringstream ss(line);
        vector<int> row;
        int x;

        while (ss >> x) {
            row.push_back(x);
        }

        rows.push_back(row);
    }

    // Print to confirm
    for (const auto& row : rows) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
