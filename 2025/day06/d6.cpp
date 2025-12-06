#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;



typedef unsigned long long int ull;

int main(){

ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<vector<ull>> grid;   
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  

        stringstream ss(line);
        vector<ull> row;
        ull x;
        while (ss >> x) {
            row.push_back(x);
        }
        //if (line.find('-') == string::npos) {readingFirst = false;}

        grid.push_back(row);
    }

    
    for (const auto& row : grid) {
        for (ull x : row) cout << x << " ";
        cout << "\n";
    }

    for(ull i=0;i<grid.size();i++){
        for(ull j=0;j<grid.at(i).size();j++){


        }
    }

    return 0;
}