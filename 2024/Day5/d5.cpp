#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
void findRules(vector<int> &ret, int search, vector<pair<int,int>> &matrixA);

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

    
    long long int rez=0;
    bool correct=true;
    bool correct2=true;
    for(int i=0;i<matrixB.size();i++){
        correct=true;
        for(int j=0;j<matrixB.at(i).size();j++){
            correct2=true;
            vector<int> rules;
            findRules(rules,matrixB[i][j],matrixA);
            for(int k=j+1;k<matrixB.at(i).size();k++){
                for(const auto rule:rules){
                    if(matrixB[i][k]==rule){
                        correct=false;
                        int a=matrixB[i][k];
                        matrixB[i][k]=matrixB[i][j];
                        matrixB[i][j]=a;
                        j=-1;
                        correct2=false;
                        break;
                    }
                }
                if(!correct2)break;
            }
        }
        if(!correct){
            rez+=matrixB[i][matrixB.at(i).size()/2];
            std::cout << matrixB[i][matrixB.at(i).size()/2] << "\n";
        }
    }

        std::cout << rez << " ";
    return 0;
}


void findRules(vector<int> &ret, int search, vector<pair<int,int>> &matrixA){
    for(int i=0;i<matrixA.size();i++){
        if(matrixA.at(i).second==search){
            ret.push_back(matrixA.at(i).first);
        }
    }
}