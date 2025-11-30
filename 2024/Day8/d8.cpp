#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int findAntinodes(vector<vector<char>>&, int, int,vector<pair<int,int>>&);

void overlapKords(int , int , vector<pair<int,int>>&);

int main(){

ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<vector<char>> grid;   // each line becomes one vector<int>
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  // skip blank lines

        stringstream ss(line);
        vector<char> row;
        char c;
        while (ss >> c) {
            row.push_back(c);
        }

        grid.push_back(row);
    }

    // Prlong long int to confirm
    for (const auto& row : grid) {
        for (char x : row) cout << x << " ";
        cout << "\n";
    }
    cout << "\n";

    vector<pair<int,int>> overlap;

    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid.at(i).size();j++){
            if(grid[i][j]!='.' && grid[i][j]!='#'){
                findAntinodes(grid,i,j,overlap);
            }
        }
    }
    for (const auto& row : grid) {
        for (char x : row) cout << x << " ";
        cout << "\n";
    }

    for (const auto& p : overlap) {
        cout << p.first << " "<<p.second<<endl;
    }

    int rezz=0;//overlap.size();
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid.at(i).size();j++){
            if( grid[i][j]!='.'){
                rezz++;
            }
        }
    }

    cout<<rezz;
    return 0;
}

int findAntinodes(vector<vector<char>>&grid, int x, int y, vector<pair<int,int>>&overlap){
     for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid.at(i).size();j++){
            if(grid[i][j]==grid[x][y] && i!=x && j!=y){
                int a=abs(x-i);
                int b=abs(y-j);
                int tempa=a;
                int tempb=b;
                if(x>i && y>j){
                    tempa=a;
                    tempb=b;
                    while(x+tempa<grid.size() && y+tempb<grid.at(x).size()){
                        if(grid[x+tempa][y+tempb]=='.' || grid[x+tempa][y+tempb]=='#'){
                            grid[x+tempa][y+tempb]='#';
                        }else{
                            overlapKords(x+tempa,y+tempb,overlap);
                        }
                        tempa+=a;
                        tempb+=b;
                    }
                    tempa=a;
                    tempb=b;
                    while(i-tempa>=0 && j-tempb>=0){
                        if(grid[i-tempa][j-tempb]=='.' || grid[i-tempa][j-tempb]=='#'){
                            grid[i-tempa][j-tempb]='#';
                        }else{
                            overlapKords(i-tempa,j-tempb,overlap);
                        }
                        tempa+=a;
                        tempb+=b;
                    }
                }
                if(x>i && y<j){
                    tempa=a;
                    tempb=b;
                    while(x+tempa<grid.size() && y-tempb>=0){
                        if(grid[x+tempa][y-tempb]=='.' || grid[x+tempa][y-tempb]=='#'){
                            grid[x+tempa][y-tempb]='#';
                        }else{
                            overlapKords(x+tempa,y-tempb,overlap);
                        }
                        tempa+=a;
                        tempb+=b;
                    }
                    tempa=a;
                    tempb=b;
                    while(i-tempa>=0 && j+tempb<grid.at(x).size()){
                        if(grid[i-tempa][j+tempb]=='.' || grid[i-tempa][j+tempb]=='#'){
                            grid[i-tempa][j+tempb]='#';
                        }else{
                            overlapKords(i-tempa,j+tempb,overlap);
                        }
                        tempa+=a;
                        tempb+=b;
                    }
                }
                
            }
        }
    }
    return 0;
}

void overlapKords(int x, int y, vector<pair<int,int>>& vec){
    bool check = true;
    for(int i=0;i<vec.size();i++){
        if(vec.at(i).first==x && vec.at(i).second==y){
            check=false; 
            break;
        }
    }
    if(check){
        pair<int,int> temp;
        temp.first=x;
        temp.second=y;
        vec.push_back(temp);
    }
}