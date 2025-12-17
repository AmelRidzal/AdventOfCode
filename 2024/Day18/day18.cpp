#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;



typedef  long long int ull;
void goingUp(vector<vector<ull>>& , ull , ull , ull);
void goingDown(vector<vector<ull>>& , ull , ull , ull);
void goingLeft(vector<vector<ull>>& , ull , ull , ull);
void goingRight(vector<vector<ull>>& , ull , ull , ull);

ull posEX=71,posEY=71;


int main(){

ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<pair<ull,ull>> cords; 
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  

        stringstream ss(line);
        ull x1;
        ull x2;
        char c;
        ss>>x1>>c>>x2;
        cords.push_back({x1,x2});
    }

    vector<vector<ull>> grid;   
    vector<ull> row;   
    for(int i=0;i<posEX;i++){
        row.push_back(999999);
    }
    for(int i=0;i<posEX;i++){
        grid.push_back(row);
    }
    //just manualy fount it for part 2;
    for(int i=0;i<=2892;i++){
        grid[cords[i].second][cords[i].first]=-1;
    }
    cout<<cords[2892].first<<" "<<cords[2892].second<<endl;

    /*for (const auto& row : grid) {
        for (ull x : row) cout << x << " ";
        cout << "\n";
    }*/

    grid[0][0]=0;
    if(grid[0+1][0]!=-1){
        goingDown(grid, 1, 0, 1);
    }
    if(grid[0][1]!=-1){
        goingRight(grid, 0, 1, 1);
    }
    
        
    /*for (const auto& row : grid) {
        for (ull x : row) cout << x << " ";
        cout << "\n";
    }*/

    cout<<grid[posEX-1][posEY-1];


    return 0;
}



void goingUp(vector<vector<ull>>& grid, ull posX, ull posY, ull score){
    if(posX==posEX && posEY==posY){
        if(grid[posX][posY]>score)
            grid[posX][posY]=score;
        //cout<<score<<endl;
        return;
    }
    grid[posX][posY]=score;
    score++;
    if(posX>0)
    if(grid[posX-1][posY]!=-1){
        if(grid[posX-1][posY]>score){
            goingUp(grid, posX-1, posY, score);

        }
    }
    if(posY<grid.size()-1)
    if(grid[posX][posY+1]!=-1){
        if(grid[posX][posY+1]>score){
            goingRight(grid, posX, posY+1, score);

        }
    }
    if(posY>0)
    if(grid[posX][posY-1]!=-1){
        if(grid[posX][posY-1]>score){
            goingLeft(grid, posX, posY-1, score);

        }
    }
    return;
}



void goingDown(vector<vector<ull>>& grid, ull posX, ull posY, ull score){
    if(posX==posEX && posEY==posY){
        if(grid[posX][posY]>score)
            grid[posX][posY]=score;
        //cout<<score<<endl;
        return;
    }
    grid[posX][posY]=score;
    score++;
    if(posX<grid.size()-1)
    if(grid[posX+1][posY]!=-1){
        if(grid[posX+1][posY]>score){
            goingDown(grid, posX+1, posY, score);
        }
    }
    if(posY<grid.size()-1)
    if(grid[posX][posY+1]!=-1){
        if(grid[posX][posY+1]>score){
            goingRight(grid, posX, posY+1, score);
        }
    }
    if(posY>0)
    if(grid[posX][posY-1]!=-1){
        if(grid[posX][posY-1]>score){
            goingLeft(grid, posX, posY-1, score);

        }
    }
    return;
}



void goingRight(vector<vector<ull>>& grid, ull posX, ull posY, ull score){
    if(posX==posEX && posEY==posY){
        if(grid[posX][posY]>score)
            grid[posX][posY]=score;
        //cout<<score<<endl;
        return;
    }
    grid[posX][posY]=score;
    score++;
    if(posY<grid.size()-1)
    if(grid[posX][posY+1]!=-1){
        if(grid[posX][posY+1]>score){
            goingRight(grid, posX, posY+1, score);

        }
    }
    if(posX<grid.size()-1)
    if(grid[posX+1][posY]!=-1){
        if(grid[posX+1][posY]>score){
            goingDown(grid, posX+1, posY, score);

        }
    }
    if(posX>0)
    if(grid[posX-1][posY]!=-1){
        if(grid[posX-1][posY]>score){
            goingUp(grid, posX-1, posY, score);

        }
    }
    return;
}



void goingLeft(vector<vector<ull>>& grid, ull posX, ull posY, ull score){
    if(posX==posEX && posEY==posY){
        if(grid[posX][posY]>score)
            grid[posX][posY]=score;
        //cout<<score<<endl;
        return;
    }
    grid[posX][posY]=score;
    score++;
    if(posY>0)
    if(grid[posX][posY-1]!=-1){
        if(grid[posX][posY-1]>score){
            goingLeft(grid, posX, posY-1, score);

        }
    }
    if(posX<grid.size()-1)
    if(grid[posX+1][posY]!=-1){
        if(grid[posX+1][posY]>score){
            goingDown(grid, posX+1, posY, score);

        }
    }
    if(posX>0)
    if(grid[posX-1][posY]!=-1){
        if(grid[posX-1][posY]>score){
            goingUp(grid, posX-1, posY, score);

        }
    }
    return;
}
