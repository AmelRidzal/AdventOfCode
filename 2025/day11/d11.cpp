#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

typedef unsigned long long int ull;

void followTree(const vector<vector<string>> &, const string &, ull &);


int main() {

    ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<vector<string>> grid;   
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;

        vector<string> row;
        int n = line.size();
        int idx = 0;

        // take first 3 chars → index 0
        if (idx + 3 <= n) {
            row.push_back(line.substr(idx, 3));
            idx += 3;
        }

        // skip 2 chars
        idx += 2;

        // take next 3 chars → index 1
        if (idx + 3 <= n) {
            row.push_back(line.substr(idx, 3));
            idx += 3;
        }

        // now loop: skip 1, take 3, push...
        while (true) {
            idx += 1;                 // skip 1
            if (idx + 3 > n) break;    // not enough chars left
            row.push_back(line.substr(idx, 3));
            idx += 3;
        }

        grid.push_back(row);
    }

    // Print to verify
    /*for (const auto &row : grid) {
        for (const auto &s : row) {
            cout << s << " ";
        }
        cout << "\n";
    }*/
    ull rezultat = 0;
    followTree(grid, "you", rezultat);
    cout << "Result = " << rezultat << "\n";

    return 0;
}

void followTree(const vector<vector<string>> &grid, 
                const string &cur, 
                ull &rezultat)
{
    // find row where index 0 == cur
    const vector<string>* found = nullptr;

    for (const auto &row : grid) {
        if (!row.empty() && row[0] == cur) {
            found = &row;
            break;
        }
    }

    // not found -> stop
    if (found == nullptr) return;


    // check the rest of the indexes
    for (size_t i = 1; i < found->size(); i++) {
        const string &next = found->at(i);

        if (next == "out"){
                rezultat++;
                return;  // end of path
            }

        // recursively follow next string
        followTree(grid, next, rezultat);
    }
}

