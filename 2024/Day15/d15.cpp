#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;



typedef unsigned long long int ull;
void moveLeft(vector<vector<char>>& , ull& , ull& );
void moveRight(vector<vector<char>>& , ull& , ull& );
void moveUp(vector<vector<char>>& , ull& , ull& );
void moveDown(vector<vector<char>>& , ull& , ull& );

int main(){

ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<vector<char>> grid;
    vector<char> input;   
    string line;

    ull posX,posY;

    while (getline(file, line)) {
        if (line.empty()) continue;  

        bool readingFirst=false;

        if (line.find('#') != string::npos) {
            readingFirst = true;
        }

        stringstream ss(line);
        vector<char> row;
        char x;
        if(readingFirst){
            while (ss >> x) {
                if(x=='@'){
                    posX=grid.size();
                    posY=row.size();
                }
                row.push_back(x);
            }

            grid.push_back(row);
        }else{
            while (ss >> x) {
                input.push_back(x);
            }

        }
    
    }
    vector<vector<char>> newGrid;
        for(int i=0;i<grid.size();i++){
            vector<char> newRow;
            for(int j=0;j<grid.at(i).size();j++){
                if(grid[i][j]=='#'){
                    newRow.push_back('#');
                    newRow.push_back('#');
                }else if(grid[i][j]=='O'){
                    newRow.push_back('[');
                    newRow.push_back(']');
                }else if(grid[i][j]=='.'){
                    newRow.push_back('.');
                    newRow.push_back('.');
                }else if(grid[i][j]=='@'){
                    posX=newGrid.size();
                    posY=newRow.size();
                    newRow.push_back('@');
                    newRow.push_back('.');
                }
            }
            newGrid.push_back(newRow);
        }


    
    for (const auto& row : newGrid) {
        for (char x : row) cout << x << " ";
        cout << "\n";
    }
    cout << "\n";
    for (char x : input) cout << x << " ";
    cout << "\n";

    cout<<posX<<" "<<posY;
    cout << "\n";


    for(ull i=0;i<input.size();i++){
        if(input.at(i)=='<')
            moveLeft(newGrid,posX,posY);
        else if(input.at(i)=='>')
            moveRight(newGrid,posX,posY);
        else if(input.at(i)=='v')
            moveDown(newGrid,posX,posY);
        else if(input.at(i)=='^')
            moveUp(newGrid,posX,posY);
    }
        
        for (const auto& row : newGrid) {
            for (char x : row) cout << x << " ";
            cout << "\n";
        }
        cout << "\n";

        ull rez=0;

        for(int i=0;i<newGrid.size();i++){
            for(int j=0;j<newGrid.at(i).size();j++){
                if(newGrid[i][j]=='O'){
                    rez+=100*i+j;
                }
            }
        }
            cout<<rez;

    return 0;
}

void moveLeft(vector<vector<char>>& grid, ull& posX, ull& posY){
    bool canMove=false;
    int i;
    for(i=posY;i>=0;i--){
        if(grid[posX][i]=='.'){
            canMove=true;
            break;
        }else if(grid[posX][i]=='#'){
            break;
        }
    }

    if(canMove){
        while(i!=posY){
            grid[posX][i]=grid[posX][i+1];
            i++;
        }
        grid[posX][posY]='.';
        posY--;
    }
}


void moveRight(vector<vector<char>>& grid, ull& posX, ull& posY){
    bool canMove=false;
    int i;
    for(i=posY;i<grid.at(posX).size();i++){
        if(grid[posX][i]=='.'){
            canMove=true;
            break;
        }else if(grid[posX][i]=='#'){
            break;
        }
    }

    if(canMove){
        while(i!=posY){
            grid[posX][i]=grid[posX][i-1];
            i--;
        }
        grid[posX][posY]='.';
        posY++;
    }
}


void moveDown(vector<vector<char>>& grid, ull& posX, ull& posY){
    bool canMove=true;
    bool resetha=true;
    int i;
    vector<ull> checkPos;
    checkPos.push_back(posY); 
    for(i=posX;i<grid.size();i++){
        canMove=true;
        for(auto y:checkPos){
            if(grid[i][y]=='#'){
                resetha=true;
                canMove=false;
                break;
            }
            if(grid[i][y]=='['){
                checkPos.push_back(y+1);
                canMove=false;
            }
            if(grid[i][y]==']'){
                checkPos.push_back(y-1);
                canMove=false;
            }
        }
        if(resetha || canMove){
            break;
        }
    }

    if(canMove){
        while(i!=posX){
            grid[i][posY]=grid[i-1][posY];
            i++;
        }
        grid[posX][posY]='.';
        posX++;
    }
}

void moveUp(vector<vector<char>>& grid, ull& posX, ull& posY){
    bool canMove=true;
    bool resetha=true;
    int i;
    vector<vector<pair<ull,ull>>> checkPos;
    pair<ull,ull> temp;
    temp.first=posX;
    temp.second=posY;

    for(int i=posX;i>=0;i++){
        if()
    }

    
}