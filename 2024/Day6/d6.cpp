#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;


void printGrid(vector<vector<char>>&);

int main() {
    ifstream file("input");
    if (!file) {
        cerr << "Failed to open file\n";
        return 1;
    }

 vector<vector<char>> grid;
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;

        vector<char> row(line.begin(), line.end());
        grid.push_back(row);
    }

    // Print matrix to verify
    for (const auto& row : grid) {
        for (char c : row) cout << c;
        cout << "\n";
    }
        cout << "\n";

    int x,y;
    bool found=false;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid.at(i).size();j++){
            if(grid.at(i).at(j)=='^'){
                x=i;y=j;
                break;
            }
        }
        if(found){
            break;
        }
    }
    int xs=x,ys=y;

    int rezz=0;
    bool end = false;
    int direction=0; //0 up, 1 right, 2 down, 3 left
    while(!end){
        switch (direction)
        {
        case 0:
            if(grid.at(x).at(y)=='-'){
                grid.at(x).at(y)='+';
            }else{
                grid.at(x).at(y)='|';
            }
            for(int k=y+1;k<grid.at(x).size()-1;k++){
                /*if(grid.at(x).at(k)=='-'){
                    rezz++;
                    printGrid(grid);
                    break;
                }else*/ if(grid.at(k).at(y)=='#'){
                    break;
                }else if(grid.at(x).at(k)=='+'){
                    if(grid.at(x).at(k+1)=='#'){
                    rezz++;
                    //printGrid(grid);
                    break;
                    }
                }
            }
            
            
            //kretanje
            if(x==0){
                end=true;
                break;
            }else if(grid.at(x-1).at(y)=='#'){
                grid.at(x).at(y)='+';
                direction=1;
                y++;
            }else{
                x--;
            }
            break;

        case 1:
            if(grid.at(x).at(y)=='|'){
                grid.at(x).at(y)='+';
                rezz++;
            }else{
                grid.at(x).at(y)='-';
            }
                for(int k=x+1;k<grid.size()-1;k++){
                    /*if(grid.at(k).at(y)=='|'){
                        rezz++;
                        printGrid(grid);
                        break;
                    }else*/ if(grid.at(k).at(y)=='#'){
                        break;
                    }else if(grid.at(k).at(y)=='+'){
                        if(grid.at(k+1).at(y)=='#'){
                        rezz++;
                        //printGrid(grid);
                        break;
                        }
                    }
                }
            

            if(y==grid.at(x).size()-1){
                end=true;
                break;
            }else if(grid.at(x).at(y+1)=='#'){
                grid.at(x).at(y)='+';
                direction=2;
                x++;
            }else{
                y++;
            }
            break;

        case 2:
            if(grid.at(x).at(y)=='-'){
                grid.at(x).at(y)='+';
                rezz++;
            }else{
                grid.at(x).at(y)='|';}
                for(int k=y-1;k>0;k--){
                    /*if(grid.at(x).at(k)=='-'){
                        rezz++;
                        printGrid(grid);
                        break;
                    }else */if(grid.at(k).at(y)=='#'){
                        break;
                    }else if(grid.at(x).at(k)=='+'){
                        if(grid.at(x).at(k-1)=='#'){
                        rezz++;
                        //printGrid(grid);
                        break;
                        }
                    }
                }
            

            if(x==grid.size()-1){
                end=true;
                break;
            }else if(grid.at(x+1).at(y)=='#'){
                grid.at(x).at(y)='+';
                direction=3;
                y--;
            }else{
                x++;
            }
            break;

        case 3:
            if(grid.at(x).at(y)=='|'){
                grid.at(x).at(y)='+';
                rezz++;
            }else{
                grid.at(x).at(y)='-';}
                for(int k=x-1;k>0;k--){
                    /*if(grid.at(k).at(y)=='|'){
                        rezz++;
                        printGrid(grid);
                        break;
                    }else */if(grid.at(k).at(y)=='#'){
                        break;
                    }else if(grid.at(k).at(y)=='+'){
                        if(grid.at(k-1).at(y)=='#'){
                        rezz++;
                        //printGrid(grid);
                        break;
                        }
                    }
                }
            

            if(y==0){
                end=true;
                break;
            }else if(grid.at(x).at(y-1)=='#'){
                grid.at(x).at(y)='+';
                direction=0;
                x--;
            }else{
                y--;
            }
            break;
        


        default:
            break;
        }
    }

    printGrid(grid);
    cout<<rezz;
    return 0;
}


void printGrid(vector<vector<char>> &grid){
for (const auto& row : grid) {
        for (char c : row) {cout << c;}
        cout << "\n";
    }
        cout << "\n";
}
    

