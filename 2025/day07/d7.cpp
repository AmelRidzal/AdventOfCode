#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;



typedef  long long int ull;
//void lookDown(vector<vector<char>>&, ull , ull , ull& );

int main(){

ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    int posX=0,posY=0;

    vector<vector<char>> gridp1;   
    vector<vector<ull>> gridp2;   
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  

        stringstream ss(line);
        vector<char> rowp1;
        vector<ull> rowp2;
        char x;
        while (ss >> x) {
            rowp1.push_back(x);
            if(x=='S'){
                posX=gridp2.size();
                posY=rowp2.size();
                rowp2.push_back(1);
            }
            else if(x=='.'){
                rowp2.push_back(0);
            }
            else{
                rowp2.push_back(-1);
            }
        }
        gridp1.push_back(rowp1);
        gridp2.push_back(rowp2);
    }

    /*for (const auto& row : gridp2) {
        for (ull x : row) cout << x << " ";
        cout << "\n";
    }*/

    //part1
    ull rezp1 = 0;

    for (ull i=0;i<gridp1.size()-1;i++) {
        for (ull j=0; j<gridp1.at(i).size();j++) {
            if (gridp1[i][j]=='S' || gridp1[i][j] =='|') {
                if (gridp1[i+1][j]=='.') {
                    gridp1[i+1][j]='|';
                } else if (gridp1[i+1][j] =='^') {
                    rezp1++;
                    if (gridp1[i+1][j+1] =='.') {
                        gridp1[i+1][j+1] ='|';
                    }
                    if (gridp1[i+1][j-1] =='.') {
                        gridp1[i+1][j-1] ='|';
                    }
                }
            }
        }
    }


    //part2
    gridp2[posX+1][posY]=1;
    ull rezp2=0;
    for(ull i=1;i<gridp2.size()-1;i++){
        for(ull j=0;j<gridp2.at(i).size();j++){
            if(gridp2[i][j]!=0  && gridp2[i][j]!=-1){
                if(gridp2[i+1][j]==0){
                    gridp2[i+1][j]=gridp2[i][j];
                }else if(gridp2[i+1][j]==-1){
                    //rez++;
                    if(gridp2[i+1][j+1]==0){
                        gridp2[i+1][j+1]=gridp2[i][j];
                    }else{
                        gridp2[i+1][j+1]=gridp2[i+1][j+1]+gridp2[i][j];
                    }
                    if(gridp2[i+1][j-1]==0){
                        gridp2[i+1][j-1]=gridp2[i][j];
                    }else{
                        gridp2[i+1][j-1]=gridp2[i+1][j-1]+gridp2[i][j];
                    }
                }else{
                    gridp2[i+1][j]=gridp2[i+1][j]+gridp2[i][j];
                }
            }

        }
    }

    /*    cout << "\n";
        cout << "\n";
        cout << "\n";
        
    
    for (const auto& row : gridp2) {
        for (ull x : row) cout << x << " ";
        cout << "\n";
    }*/

        for(ull j=0;j<gridp2.at(0).size();j++){
            if(gridp2[gridp2.size()-1][j]!=0){
                rezp2+=gridp2[gridp2.size()-1][j];
            }
        }

    //lookDown(gridp2,posX+1,posY,rezp2);



    cout<<"part1: "<< rezp1<<endl;
    cout<<"part2: "<< rezp2<<endl;
    return 0;
}

/*void lookDown(vector<vector<char>>&grid, ull posX, ull posY, ull& rez){
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

}*/