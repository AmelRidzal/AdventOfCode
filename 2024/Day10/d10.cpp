#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void findPath(vector<vector<long long int>> &, int , int , int &, vector<vector<long long int>>&,int ,int);
void addToPaths(int ,int , int , int , vector<vector<long long int>>&);




int main(){

ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<vector<long long int>> grid;   // each line becomes one vector<int>
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  // skip blank lines

        stringstream ss(line);
        vector<long long int> row;
        char c;
        while (ss >> c) {
            row.push_back(c-'0');
        }

        grid.push_back(row);
    }

    // Prlong long int to confirm
    for (const auto& row : grid) {
        for (long long int x : row) cout << x << " ";
        cout << "\n";
    }

    
    vector<vector<long long int>> paths;

    int rez=0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid.at(i).size();j++){
            if(grid.at(i).at(j)==0){
                findPath(grid,i,j,rez, paths,i,j);
            }

        }
    }
    for (const auto& row : paths) {
        for (long long int x : row) cout << x << " ";
        cout << "\n";
    }

    cout<<rez<<endl;
    cout<<paths.size();
    return 0;
}

void findPath(vector<vector<long long int>> &grid, int x, int y, int &rez, vector<vector<long long int>>& paths, int xs, int ys){
    if(x+1<grid.size()){
        if(grid.at(x).at(y)+1==grid.at(x+1).at(y)){
            if(grid.at(x+1).at(y)==9){
                addToPaths(xs,ys,x+1,y,paths);
                rez++;
            }else{
                findPath(grid,x+1,y,rez,paths,xs,ys);
            }
        }
    }
    if(y+1<grid.at(x).size()){
        if(grid.at(x).at(y)+1==grid.at(x).at(y+1)){
            if(grid.at(x).at(y+1)==9){
                addToPaths(xs,ys,x,y+1,paths);
                rez++;
            }else{
                findPath(grid,x,y+1,rez,paths,xs,ys);
            }
        }
    }

    if(x-1>=0){
        if(grid.at(x).at(y)+1==grid.at(x-1).at(y)){
            if(grid.at(x-1).at(y)==9){
                addToPaths(xs,ys,x-1,y,paths);
                rez++;
            }else{
                findPath(grid,x-1,y,rez,paths,xs,ys);
            }
        }
    }
    if(y-1>=0){
        if(grid.at(x).at(y)+1==grid.at(x).at(y-1)){
            if(grid.at(x).at(y-1)==9){
                addToPaths(xs,ys,x,y-1,paths);
                rez++;
            }else{
                findPath(grid,x,y-1,rez,paths,xs,ys);
            }
        }
    }
}


void addToPaths(int xs,int ys, int xe, int ye, vector<vector<long long int>>&paths){
    bool check=true;
    for(int i=0;i<paths.size();i++){
        if(paths.at(i).at(0)==xs && paths.at(i).at(1)==ys && paths.at(i).at(2)==xe && paths.at(i).at(3)==ye){
            check=false;
            break;
        }
    }
    if(check){
        vector<long long int> temp;
        temp.push_back(xs);
        temp.push_back(ys);
        temp.push_back(xe);
        temp.push_back(ye);
        paths.push_back(temp);
    }
}
