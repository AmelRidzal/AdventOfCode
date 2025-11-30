#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ifstream file("input");
    if (!file) {
        cerr << "Failed to open file\n";
        return 1;
    }

    vector<pair<int,int>> matrixA;      // first part: rows like 47|53
    vector<vector<int>> matrixB;        // second part: rows like 75,47,61,...

    string line;
    bool readingFirst = true;

    while (getline(file, line)) {
        if (line.empty()) continue;

        // Detect transition between the two parts
        if (line.find('|') == string::npos && line.find(',') != string::npos) {
            readingFirst = false;
        }

        if (readingFirst) {
            // ---------- PART 1: pairs separated by "|" ----------
            int a, b;
            char sep;
            stringstream ss(line);
            ss >> a >> sep >> b;   // reads "47|53"
            matrixA.push_back({a, b});
        } 
        else {
            // ---------- PART 2: rows separated by "," ----------
            vector<int> row;
            stringstream ss(line);
            string num;

            while (getline(ss, num, ',')) {
                row.push_back(stoi(num));
            }

            matrixB.push_back(row);
        }
    }

    // Debug print
    cout << "Matrix A (pairs):\n";
    for (auto &p : matrixA) {
        cout << p.first << " | " << p.second << "\n";
    }

    cout << "\nMatrix B (rows):\n";
    for (auto &row : matrixB) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
