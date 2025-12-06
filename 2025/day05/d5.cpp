#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;



int main(){

ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<vector<ull>> grid;  
    vector<ull> vec; 
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  
        bool readingFirst=true;
        stringstream ss(line);
        vector<ull> row;
        ull x;
        char c;

        if (line.find('-') == string::npos) {
            readingFirst = false;
        }

        if(readingFirst){
            ss >> x;
            row.push_back(x);
            ss>>c;
            ss >> x;
            row.push_back(x);
            grid.push_back(row);
        }else{
            ss >> x;
            vec.push_back(x);
        }

    }

    /*
    for (const auto& row : grid) {
        for (ull x : row) cout << x << " ";
        cout << "\n";
    }
        cout << "\n";
        for (ull x : vec) cout << x << " ";
        cout << "\n";*/

        ull rez=0;
    //for(ull i=0;i<grid.size();i++){
        /*for(ull j=0;j<vec.size();j++){
            if(vec.at(j)!=-1){
                if(vec.at(j)>=grid[i][0] && vec.at(j)<=grid[i][1]){
                    rez++;
                    cout<<vec.at(j)<<" ";
                    vec.at(j)=-1;
                }
            }
        }*/



    //}
    vector<vector<ull>> grid2;
    
    sort(grid.begin(),grid.end());
    for(ull i=0;i<grid.size();i++){
        for(ull j=i+1;j<grid.size();j++){
            if(grid[i][0]<=grid[j][0] && grid[i][1]<=grid[j][1] && grid[i][1]>=grid[j][0]){
                grid[i][1]=grid[j][1];
                grid.erase(grid.begin()+j);
                i=-1;
                break;
            }else if(grid[i][0]>=grid[j][0] && grid[i][1]>=grid[j][1] && grid[i][0]<=grid[j][1]){
                grid[j][1]=grid[i][1];
                grid.erase(grid.begin()+i);
                i=-1;
                break;
            }else if(grid[i][0]<=grid[j][0] && grid[i][1]>=grid[j][1]){
                grid.erase(grid.begin()+j);

            }
        }
        sort(grid.begin(),grid.end());
    }

    for(ull i=0;i<grid.size();i++){
        rez+= grid[i][1]-grid[i][0]+1;
    }



    for(ull i=0;i<grid.size();i++){
        for(ull x:grid.at(i)){
            cout<<x<<" ";
        }
        cout<<endl;
    }


cout<<rez;
    return 0;
}


