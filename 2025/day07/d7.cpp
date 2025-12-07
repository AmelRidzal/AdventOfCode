#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;



typedef  long long int ull;
void lookDown(vector<vector<char>>&, ull , ull , ull& );

int main(){

ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    int posX=0,posY=0;

    vector<vector<ull>> grid;   
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  

        stringstream ss(line);
        vector<ull> row;
        char x;
        while (ss >> x) {
            if(x=='S'){
                posX=grid.size();
                posY=row.size();
            row.push_back(1);
            }
            else if(x=='.')
            row.push_back(0);
            else{row.push_back(-1);}
        }
        //if (line.find('-') == string::npos) {readingFirst = false;}

        grid.push_back(row);
    }

    
    /*for (const auto& row : grid) {
        for (ull x : row) cout << x << " ";
        cout << "\n";
    }*/

    grid[posX+1][posY]=1;
    ull rez=0;
    for(ull i=1;i<grid.size()-1;i++){
        for(ull j=0;j<grid.at(i).size();j++){
            if(grid[i][j]!=0  && grid[i][j]!=-1){
                if(grid[i+1][j]==0){
                    grid[i+1][j]=grid[i][j];
                }else if(grid[i+1][j]==-1){
                    //rez++;
                    if(grid[i+1][j+1]==0){
                        grid[i+1][j+1]=grid[i][j];
                    }else{
                        grid[i+1][j+1]=grid[i+1][j+1]+grid[i][j];
                    }
                    if(grid[i+1][j-1]==0){
                        grid[i+1][j-1]=grid[i][j];
                    }else{
                        grid[i+1][j-1]=grid[i+1][j-1]+grid[i][j];
                    }
                }else{grid[i+1][j]=grid[i+1][j]+grid[i][j];}
            }

        }
    }


        cout << "\n";
        cout << "\n";
        cout << "\n";
        
    
    for (const auto& row : grid) {
        for (ull x : row) cout << x << " ";
        cout << "\n";
    }

        for(ull j=0;j<grid.at(0).size();j++){
            if(grid[grid.size()-1][j]!=0){
                rez+=grid[grid.size()-1][j];
            }
        }

    //lookDown(grid,posX+1,posY,rez);
        cout << "\n";
        cout << "\n";
        cout << "\n";

cout<<rez;
    return 0;
}

void lookDown(vector<vector<char>>&grid, ull posX, ull posY, ull& rez){
        if(posX+1 ==grid.size()-1){
            rez++;return;
        }

    while(grid[posX+1][posY]!=-1){
        posX++;
        if(posX+1 ==grid.size()){
            rez++;return;
        }
    }
    if(posY+1<grid.at(0).size())
        lookDown(grid,posX,posY+1,rez);
    if(posY-1>=0)
        lookDown(grid,posX,posY-1,rez);

}