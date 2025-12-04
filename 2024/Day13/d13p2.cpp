#include <iostream>
#include <vector>
#include <cmath> // For round and fabs
#include <fstream>
#include <sstream>
using namespace std;
// Function to solve the system and return A and B
std::pair<long long, long long> solveSystem(
    long long ax, long long ay, long long bx, long long by,
    long long target_x, long long target_y) {

    double det = (double)ax * by - (double)bx * ay;

    if (std::fabs(det) < 1e-9) { // Check for near-zero determinant (no unique solution)
        return {-1, -1}; // Indicate no valid solution
    }

    double det_A = (double)target_x * by - (double)bx * target_y;
    double det_B = (double)ax * target_y - (double)target_x * ay;

    double val_A = det_A / det;
    double val_B = det_B / det;

    // Check if A and B are integers and non-negative
    if (std::fabs(val_A - std::round(val_A)) < 1e-9 &&
        std::fabs(val_B - std::round(val_B)) < 1e-9 &&
        val_A >= 0 && val_B >= 0) {
        return {(long long)std::round(val_A), (long long)std::round(val_B)};
    } else {
        return {-1, -1}; // Indicate no valid solution
    }
}



typedef unsigned long long int ull;

int main(){

ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<vector<ull>> grid;   
    string line;
        vector<ull> row;

    while (getline(file, line)) {
        if (line.empty()) continue;  

        stringstream ss(line);
        ull x;
        char c;
        ss>>c;
        if(c=='B'){
            for(ull i=0;i<9;i++){
                ss >> c;
            }
            ss>>x;
            row.push_back(x);
            for(ull i=0;i<3;i++){
                ss >> c;
            }
            ss>>x;
            row.push_back(x);
        }else if(c=='P'){
            for(ull i=0;i<7;i++){
                ss >> c;
            }
            ss>>x;
            x=x+10000000000000;
            row.push_back(x);
            for(ull i=0;i<3;i++){
                ss >> c;
            }
            ss>>x;
            x=x+10000000000000;
            row.push_back(x);
            grid.push_back(row);
            row.clear();

        }

    }

    ull rez=0;
    
    for (const auto& row : grid) {

    // Read input values for ax, ay, bx, by, target_x, target_y (for Part 1)
    long long ax=row[0], ay=row[1], bx=row[2], by=row[3], target_x=row[4], target_y=row[5];
    // ... input reading ...

    std::pair<long long, long long> result_part1 = solveSystem(ax, ay, bx, by, target_x, target_y);

    if (result_part1.first != -1) {
        long long A = result_part1.first;
        long long B = result_part1.second;
        long long price_part1 = 3 * A + B; // Example price calculation
        std::cout << "Part 1 Price: " << price_part1 << std::endl;
        rez+=price_part1;
    } else {
        std::cout << "Part 1: No valid solution found." << std::endl;
    }


}

cout<<rez;

    return 0;
}