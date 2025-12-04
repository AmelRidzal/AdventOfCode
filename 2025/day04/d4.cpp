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
        char x;
        while (ss >> x) {
            row.push_back(x);
        }

        grid.push_back(row);
    }

    
    for (const auto& row : grid) {
        for (char x : row) cout << x << " ";
        cout << "\n";
    }
    ull rez=0;
bool removed=true;
    while(removed){
        removed=false;
        for(ull i=0;i<grid.size();i++){
            for(ull j=0;j<grid.at(i).size();j++){
                if(grid[i][j]=='@'){
                    int count=0;
                    if(i<grid.size()-1)
                    if(grid[i+1][j]=='@'){
                        count++;
                    }
                    if(i<grid.size()-1 && j<grid[i].size()-1)
                    if(grid[i+1][j+1]=='@'){
                        count++;
                    }
                    if(j<grid[i].size()-1)
                    if(grid[i][j+1]=='@'){
                        count++;
                    }
                    if(i>0)
                    if(grid[i-1][j]=='@'){
                        count++;
                    }
                    if(i>0 && j>0)
                    if(grid[i-1][j-1]=='@'){
                        count++;
                    }
                    if(j>0)
                    if(grid[i][j-1]=='@'){
                        count++;
                    }
                    if(i<grid.size()-1 && j>0)
                    if(grid[i+1][j-1]=='@'){
                        count++;
                    }
                    if(i>0 && j<grid[i].size()-1)
                    if(grid[i-1][j+1]=='@'){
                        count++;
                    }
                    if(count<4){
                        removed=true;
                        rez++;
                        grid[i][j]='x';
                    }
                }

        }
    }
}
    cout<<rez;

    return 0;
}