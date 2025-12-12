#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

typedef unsigned long long int ull;

struct machine {
    vector<char> ind;                 // target as characters
    vector<vector<ull>> button;       // operations (indices)
    vector<ull> jols;                 // unused for the solver
};

int main() {

    ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<machine> grid;   
    string line;

    // -------------------------------
    // PARSING
    // -------------------------------
    while (getline(file, line)) {
        if (line.empty()) continue;  

        machine temp;
        stringstream ss(line);
        ull x;
        char c;

        ss >> c; // [
        ss >> c;

        // read ind until ']'
        while (c != ']') {
            temp.ind.push_back(c);
            ss >> c;
        }

        // read buttons until '{'
        while (c != '{') {
            ss >> c;
            vector<ull> row;

            if (c == '(') {
                do {
                    ss >> x;
                    ss >> c;
                    row.push_back(x);
                } while (c == ',');
            }

            temp.button.push_back(row);
        }

        // read jols until '}'
        do {
            ss >> x;
            ss >> c;
            temp.jols.push_back(x);
        } while (c == ',');

        grid.push_back(temp);
    }

    ull rez=0;
    // -------------------------------
    // PROCESS EACH MACHINE
    // -------------------------------
    for (const auto& row : grid) {

        int targetLen = row.ind.size();

        // Build target mask
        int target = 0;
        for (int i = 0; i < targetLen; i++) {
            if (row.ind[i] == '1' || row.ind[i] == '#')
                target |= (1 << i);
        }

        // Build operation bitmasks
        vector<int> ops;
        for (auto &b : row.button) {
            int mask = 0;
            for (ull idx : b) {
                if (idx < targetLen)
                    mask |= (1 << idx);
            }
            ops.push_back(mask);
        }

        int N = ops.size();

        // -------- BFS for minimum toggles --------
        const int MAXS = 1 << 10;
        vector<int> dist(MAXS, -1);
        vector<int> parentOp(MAXS, -1);
        vector<int> parentState(MAXS, -1);

        queue<int> q;
        dist[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            if (cur == target) break;

            for (int i = 0; i < N; i++) {
                int nxt = cur ^ ops[i];
                if (dist[nxt] == -1) {
                    dist[nxt] = dist[cur] + 1;
                    parentOp[nxt] = i;
                    parentState[nxt] = cur;
                    q.push(nxt);
                }
            }
        }

        // ------------------------------
        // OUTPUT
        // ------------------------------
        cout << "TARGET: ";
        for (char c : row.ind) cout << c << " ";
        cout << "\n";

        if (dist[target] == -1) {
            cout << "  No solution found.\n";
            continue;
        }

        // reconstruct solution
        vector<int> usedOps;
        int cur = target;

        while (cur != 0) {
            usedOps.push_back(parentOp[cur]);
            cur = parentState[cur];
        }
        rez+=usedOps.size() ;
        /*cout << "  Minimum operations = " << usedOps.size() << "\n";
        cout << "  Using buttons (0-based index): ";
        for (int op : usedOps) cout << op << " ";
        cout << "\n\n";*/
    }
    cout<<rez;

    return 0;
}
