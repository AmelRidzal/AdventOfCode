#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
bool reqTest(vector<long long int> &, long long int, int);
long long int concatenation(long long int , long long int );

int main() {
    ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<vector<long long int>> rows;   // each line becomes one vector<int>
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  // skip blank lines

        stringstream ss(line);
        vector<long long int> row;
        long long int x;
        char c;
        ss >> x;
        row.push_back(x);
        ss >> c;
        while (ss >> x) {
            row.push_back(x);
        }

        rows.push_back(row);
    }

    // Prlong long int to confirm
    for (const auto& row : rows) {
        for (long long int x : row) cout << x << " ";
        cout << "\n";
    }
    long long int rez = 0;

    for(int i=0;i<rows.size();i++){
        if(rows.at(i).size()==3 && (rows[i][0]==rows[i][1]+rows[i][2] || rows[i][0]==rows[i][1]*rows[i][2] || rows[i][0]==concatenation(rows[i][1],rows[i][2]))){
            rez+=rows[i][0];
        }else{
            if(reqTest(rows.at(i), rows[i][1]+rows[i][2], 3)){
                rez+=rows[i][0];
            }else if(reqTest(rows.at(i), rows[i][1]*rows[i][2], 3)){
                rez+=rows[i][0];
            }else if(reqTest(rows.at(i),concatenation(rows[i][1],rows[i][2]), 3)){
                rez+=rows[i][0];
            }
        }
    }
   

cout<<rez;

    return 0;
}

bool reqTest(vector<long long int> &vec, long long int pre, int stage){
    if(stage>= vec.size() || pre>vec[0]){
        return false;
    }
    if(vec.size()==stage+1 && (vec[0]==pre+vec[stage] || vec[0]==pre*vec[stage] || vec[0]==concatenation(pre,vec[stage]))){
            return true;
        }else{
            if(reqTest(vec, pre+vec[stage], stage+1)){
                return true;
            }else if(reqTest(vec, pre*vec[stage], stage+1)){
                return true;
            }else if(reqTest(vec, concatenation(pre,vec[stage]), stage+1)){
                return true;
            }else{
                return false;
            }
        }
}

long long int concatenation(long long int first, long long int second){
    long long int temp = second;
    int digits = 1;

    while (temp > 0) {
        digits *= 10;
        temp /= 10;
    }

    return first * digits + second;


}
