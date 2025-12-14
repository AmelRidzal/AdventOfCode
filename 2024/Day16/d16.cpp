#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;



typedef long long int ull;
void goingUp(vector<vector<ull>>& , ull , ull , ull);
void goingDown(vector<vector<ull>>& , ull , ull , ull);
void goingLeft(vector<vector<ull>>& , ull , ull , ull);
void goingRight(vector<vector<ull>>& , ull , ull , ull);
bool checkRaskrsnica(vector<vector<ull>>& , ull , ull );

ull posEX,posEY;

int main(){

ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<vector<ull>> grid;   
    string line;
    ull posX,posY;

    while (getline(file, line)) {
        if (line.empty()) continue;  

        stringstream ss(line);
        vector<ull> row;
        char x;
        while (ss >> x) {
            if(x=='S'){
                posX=grid.size();
                posY=row.size();
            }
            if(x=='#'){
                row.push_back(-1);
            }
            else if(x=='E'){
                posEX=grid.size();
                posEY=row.size();
                row.push_back(numeric_limits<long long int>::max());
            }
            else{
                row.push_back(numeric_limits<long long int>::max());
            }
        }

        grid.push_back(row);
    }
    
    /*for (const auto& row : grid) {
        for (ull x : row) cout << x<<" ";
        cout << "\n";
    }*/
    grid[posX][posY]=0;
    if(grid[posX-1][posY]!=-1){
        goingUp(grid, posX-1, posY, 1001);
    }
    if(grid[posX+1][posY]!=-1){
        goingDown(grid, posX+1, posY, 1001);
    }
    if(grid[posX][posY-1]!=-1){
        goingLeft(grid, posX, posY-1, 1001);
    }
    if(grid[posX][posY+1]!=-1){
        goingRight(grid, posX, posY+1, 1);
    }
    
    /*for (int i=0;i<grid.size();i++) {
        for (int j=0;j<grid.at(i).size();j++) {
            if(grid[i][j]==-2){
                cout<<grid[i-1][j]<<" "<<grid[i][j-1]<<" "<<grid[i+1][j]<<" "<<grid[i][j+1]<<endl;
            }
        }
    }*/
   cout<<grid[posEX][posEY]<<endl;
    return 0;
}



void goingUp(vector<vector<ull>>& grid, ull posX, ull posY, ull score){
    if(posX==posEX && posEY==posY){
        if(grid[posX][posY]>=score)
            grid[posX][posY]=score;
        cout<<score<<endl;
        return;
    }
    grid[posX][posY]=score;
    score++;
    if(grid[posX-1][posY]!=-1){
        if(grid[posX-1][posY]>=score){
            goingUp(grid, posX-1, posY, score);

        }
    }
    score+=1000;
    if(grid[posX][posY+1]!=-1){
        if(grid[posX][posY+1]>=score){
            goingRight(grid, posX, posY+1, score);

        }
    }
    if(grid[posX][posY-1]!=-1){
        if(grid[posX][posY-1]>=score){
            goingLeft(grid, posX, posY-1, score);

        }
    }
    return;
}



void goingDown(vector<vector<ull>>& grid, ull posX, ull posY, ull score){
    if(posX==posEX && posEY==posY){
        if(grid[posX][posY]>=score)
            grid[posX][posY]=score;
        cout<<score<<endl;
        return;
    }
    grid[posX][posY]=score;
    score++;
    if(grid[posX+1][posY]!=-1){
        if(grid[posX+1][posY]>=score){
            goingDown(grid, posX+1, posY, score);
        }
    }
    score+=1000;
    if(grid[posX][posY+1]!=-1){
        if(grid[posX][posY+1]>=score){
            goingRight(grid, posX, posY+1, score);
        }
    }
    if(grid[posX][posY-1]!=-1){
        if(grid[posX][posY-1]>=score){
            goingLeft(grid, posX, posY-1, score);

        }
    }
    return;
}



void goingRight(vector<vector<ull>>& grid, ull posX, ull posY, ull score){
    if(posX==posEX && posEY==posY){
        if(grid[posX][posY]>=score)
            grid[posX][posY]=score;
        cout<<score<<endl;
        return;
    }
    grid[posX][posY]=score;
    score++;
    if(grid[posX][posY+1]!=-1){
        if(grid[posX][posY+1]>=score){
            goingRight(grid, posX, posY+1, score);

        }
    }
    score+=1000;
    if(grid[posX+1][posY]!=-1){
        if(grid[posX+1][posY]>=score){
            goingDown(grid, posX+1, posY, score);

        }
    }
    if(grid[posX-1][posY]!=-1){
        if(grid[posX-1][posY]>=score){
            goingUp(grid, posX-1, posY, score);

        }
    }
    return;
}



void goingLeft(vector<vector<ull>>& grid, ull posX, ull posY, ull score){
    if(posX==posEX && posEY==posY){
        if(grid[posX][posY]>=score)
            grid[posX][posY]=score;
        cout<<score<<endl;
        return;
    }
    grid[posX][posY]=score;
    score++;
    if(grid[posX][posY-1]!=-1){
        if(grid[posX][posY-1]>=score){
            goingLeft(grid, posX, posY-1, score);

        }
    }
    score+=1000;
    if(grid[posX+1][posY]!=-1){
        if(grid[posX+1][posY]>=score){
            goingDown(grid, posX+1, posY, score);

        }
    }
    if(grid[posX-1][posY]!=-1){
        if(grid[posX-1][posY]>=score){
            goingUp(grid, posX-1, posY, score);

        }
    }
    return;
}



