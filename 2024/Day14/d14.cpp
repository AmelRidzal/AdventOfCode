#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;



typedef  long long int ull;

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
        ull x;
        char c;
        ss>>c>>c>>x;
        row.push_back(x);
        ss>>c>>x;
        row.push_back(x);
        ss>>c>>c>>x;
        row.push_back(x);
        ss>>c>>x;
        row.push_back(x);


        grid.push_back(row);
    }

    
    for (const auto& row : grid) {
        for (ull x : row) cout << x << " ";
        cout << "\n";
    }

    ull rez=0;
    for(ull i=0;i<grid.size();i++){
        grid.at(i).at(0)+=grid.at(i).at(2)*8179;
        while(grid.at(i).at(0)>=101)grid.at(i).at(0)-=101;
        while(grid.at(i).at(0)<0)grid.at(i).at(0)+=101;
        grid.at(i).at(1)+=grid.at(i).at(3)*8179;
        while(grid.at(i).at(1)>=103)grid.at(i).at(1)-=103;
        while(grid.at(i).at(1)<0)grid.at(i).at(1)+=103;
    }
        cout << "\n";




        
    vector<vector<char>> griddd;
    vector<char> rowww;
            
    for(int j=0;j<101;j++){
        rowww.push_back('.');
    }
    for(int i=0;i<103;i++){
        griddd.push_back(rowww);
    }

    
    for (vector<ull> row : grid) {
        /*if(row.at(1)>100 || row.at(0)>100){
            row.at(1)++;
        }*/
        if(griddd.at(row.at(1)).at(row.at(0))=='.'){
            griddd.at(row.at(1)).at(row.at(0))='1';
        }else{
            griddd.at(row.at(1)).at(row.at(0))++;
        }
    }

    
    for (const auto& row : griddd) {
        for (char x : row) cout << x ;
        cout << "\n";
    }


    ull q1=0,q2=0,q3=0,q4=0;
    for(int i=0;i<griddd.size()/2;i++){
        for(int j=0;j<griddd.at(i).size()/2;j++){
            if(griddd.at(i).at(j)!='.'){
                q1=q1+griddd.at(i).at(j)-'0';
            }
        }
    }
    for(int i=griddd.size()/2+1;i<griddd.size();i++){
        for(int j=0;j<griddd.at(i).size()/2;j++){
            if(griddd.at(i).at(j)!='.'){
                q2=q2+griddd.at(i).at(j)-'0';
            }
        }
    }
    for(int i=0;i<griddd.size()/2;i++){
        for(int j=griddd.at(i).size()/2+1;j<griddd.at(i).size();j++){
            if(griddd.at(i).at(j)!='.'){
                q3=q3+griddd.at(i).at(j)-'0';
            }
        }
    }

    for(int i=griddd.size()/2+1;i<griddd.size();i++){
        for(int j=griddd.at(i).size()/2+1;j<griddd.at(i).size();j++){
            if(griddd.at(i).at(j)!='.'){
                q4=q4+griddd.at(i).at(j)-'0';
            }
        }
    }

    rez=q1*q2*q3*q4;
    cout<<rez;
    return 0;
}