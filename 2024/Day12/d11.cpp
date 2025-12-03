#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;



typedef unsigned long long int ull;
void getNeighbor(vector<vector<char>>&, vector<vector<char>>&, int , int , char );
void clearVec(vector<vector<char>>&);
ull getRegionSize(vector<vector<char>>&);
ull getRegionFence(vector<vector<char>>&);
ull getRegionFencev2(vector<vector<char>>&);

int main(){

ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<vector<char>> grid;   
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  

        stringstream ss(line);
        vector<char> row;
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

    vector<vector<char>> temp;
    for(ull i=0;i<grid.size();i++){
        vector<char> miniTemp;
        for(ull j=0;j<grid.at(i).size();j++){
            miniTemp.push_back('.');
        }
        temp.push_back(miniTemp);
    }

    ull rez=0;

    for(ull i=0;i<grid.size();i++){
        for(ull j=0;j<grid.at(i).size();j++){
            if(grid.at(i).at(j)!='.'){
                char c=grid.at(i).at(j);
                grid.at(i).at(j)='.';
                temp.at(i).at(j)=c;
                getNeighbor(grid,temp,i,j,c);

                ull regionSize=getRegionSize(temp);
                ull regionFende=getRegionFencev2(temp);
                rez=rez+regionFende*regionSize;

                for (const auto& row : temp) {
                    for (char x : row) cout << x << " ";
                    cout << "\n";
                }
                cout<<regionSize<<" "<<regionFende;
                cout << "\n";

                clearVec(temp);
            }
        }
    }

    cout<<rez;

    return 0;
}

void getNeighbor(vector<vector<char>>&grid, vector<vector<char>>&temp, int x, int y, char c){
    if(x+1<grid.size()){
        if(c==grid[x+1][y]){
            temp[x+1][y]=c;
            grid[x+1][y]='.';
            getNeighbor(grid,temp,x+1,y,c);
        }
    }
    if(x-1>=0){
        if(c==grid[x-1][y]){
            temp[x-1][y]=c;
            grid[x-1][y]='.';
            getNeighbor(grid,temp,x-1,y,c);
        }
    }
    if(y+1<grid.at(x).size()){
        if(c==grid[x][y+1]){
            temp[x][y+1]=c;
            grid[x][y+1]='.';
            getNeighbor(grid,temp,x,y+1,c);
        }
    }
    if(y-1>=0){
        if(c==grid[x][y-1]){
            temp[x][y-1]=c;
            grid[x][y-1]='.';
            getNeighbor(grid,temp,x,y-1,c);
        }
    }
}

void clearVec(vector<vector<char>>&grid){
    for(ull i=0;i<grid.size();i++){
        for(ull j=0;j<grid.at(i).size();j++){
            grid[i][j]='.';
        }
    }

}


ull getRegionSize(vector<vector<char>>&grid){
    ull ret=0;
    for(ull i=0;i<grid.size();i++){
        for(ull j=0;j<grid.at(i).size();j++){
            if(grid[i][j]!='.'){
                ret++;
            }
        }
    }
    return ret;
}

ull getRegionFence(vector<vector<char>>&grid){
    ull ret=0;
    for(ull i=0;i<grid.size();i++){
        for(ull j=0;j<grid.at(i).size();j++){
            if(grid[i][j]!='.'){
                if(i==0){
                    ret++;
                }else if(grid[i-1][j]=='.'){
                    ret++;
                }
                if(j==0){
                    ret++;
                }else if(grid[i][j-1]=='.'){
                    ret++;
                }
                if(i==grid.size()-1){
                    ret++;
                }else if(grid[i+1][j]=='.'){
                    ret++;
                }
                if(j==grid.at(i).size()-1){
                    ret++;
                }else if(grid[i][j+1]=='.'){
                    ret++;
                }
            }
        }
    }

    
    return ret;
}


using ull = unsigned long long;

using ull = unsigned long long;

ull getRegionFencev2(vector<vector<char>>& grid) {
    ull ret = 0;
    int n = grid.size();
    int m = grid[0].size();

    // Direction vectors: up, down, left, right
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] != '.'){     // only count 'I' cells
                for(int d = 0; d < 4; d++){
                    int nx = i + dx[d];
                    int ny = j + dy[d];

                    // if neighbor is out of bounds → fence
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                        ret++;
                    }
                    // if neighbor is '.' → fence
                    else if(grid[nx][ny] == '.'){
                        ret++;
                    }
                }
            }
        }
    }

    return ret;
}
