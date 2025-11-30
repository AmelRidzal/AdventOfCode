#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;





int main(){

ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<vector<long long int>> grid;   // each line becomes one vector<int>
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  // skip blank lines

        stringstream ss(line);
        vector<long long int> row;
        long long int x;
        while (ss >> x) {
            row.push_back(x);
        }

        grid.push_back(row);
    }

    // Prlong long int to confirm
    for (const auto& row : grid) {
        for (char x : row) cout << x << " ";
        cout << "\n";
    }
    return 0;
}