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

    vector<vector<long long int>> grid;   
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  

        stringstream ss(line);
        vector<long long int> row;
        long long int x;
        while (ss >> x) {
            row.push_back(x);
        }

        grid.push_back(row);
    }

    
    for (const auto& row : grid) {
        for (long long int x : row) cout << x << " ";
        cout << "\n";
    }

    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid.at(i).size();j++){


        }
    }

    return 0;
}