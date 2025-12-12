#include <bits/stdc++.h>
using namespace std;

struct Region {
    int area;
    vector<int> presentCounts;
};

pair<vector<int>, vector<Region>> ParsePuzzleInput(const string& path) {
    ifstream file(path);
    if (!file) {
        throw runtime_error("Could not open file: " + path);
    }

    string wholeInput( (istreambuf_iterator<char>(file)),
                       istreambuf_iterator<char>() );

    // split blocks by double-newline
    vector<string> blocks;
    size_t start = 0;
    while (true) {
        size_t pos = wholeInput.find("\n\n", start);
        if (pos == string::npos) {
            blocks.push_back(wholeInput.substr(start));
            break;
        }
        blocks.push_back(wholeInput.substr(start, pos - start));
        start = pos + 2;
    }

    // last block = regions
    vector<string> regionLines;
    {
        stringstream ss(blocks.back());
        string r;
        while (getline(ss, r)) {
            if (!r.empty()) regionLines.push_back(r);
        }
    }
    blocks.pop_back();

    // --- Parse presentSizes ---
    vector<int> presentSizes;
    for (auto &b : blocks) {
        if (b.find('#') == string::npos) continue;
        int countHash = 0;
        for (char c : b)
            if (c == '#') countHash++;
        presentSizes.push_back(countHash);
    }

    // --- Parse regions ---
    vector<Region> regions;

    for (auto &line : regionLines) {
        // Split "WxH: a b c ..."
        auto pos = line.find(':');
        string dims = line.substr(0, pos);
        string counts = line.substr(pos + 1);

        // parse area = W * H
        auto xPos = dims.find('x');
        int w = stoi(dims.substr(0, xPos));
        int h = stoi(dims.substr(xPos + 1));
        int area = w * h;

        // parse present counts
        vector<int> presentCounts;
        stringstream ss(counts);
        int x;
        while (ss >> x) presentCounts.push_back(x);

        regions.push_back({area, presentCounts});
    }

    return {presentSizes, regions};
}

int GetMinTotalPresentArea(const vector<int>& presentCounts, const vector<int>& presentSizes) {
    int sum = 0;
    for (size_t i = 0; i < presentCounts.size(); i++) {
        sum += presentCounts[i] * presentSizes[i];
    }
    return sum;
}

long SolvePart1(const string& path) {
    auto [presentSizes, regions] = ParsePuzzleInput(path);

    long countFits = 0;
    for (auto &r : regions) {
        if (r.area >= GetMinTotalPresentArea(r.presentCounts, presentSizes))
            countFits++;
    }
    return countFits;
}

int main() {
    cout << SolvePart1("input") << "\n";
    return 0;
}
