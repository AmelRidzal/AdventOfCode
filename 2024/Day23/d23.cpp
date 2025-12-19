#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;



typedef unsigned long long int ull;
bool checkSame(vector<pair<string,string>>&,ull,ull,ull,vector<vector<string>>&);

int main(){

ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<pair<string,string>> grid;   
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  

        stringstream ss(line);
        string s1,s2;
        char c;
        ss>>c;
        s1=s1+c;
        ss>>c;
        s1=s1+c;
        ss>>c;
        ss>>c;
        s2=s2+c;
        ss>>c;
        s2=s2+c;

        grid.push_back({s1,s2});
    }

    sort(grid.begin(),grid.end());
    
    //for (auto x : grid) cout << x.first << " "<<x.second<<endl;
    
    vector<vector<string>> tempRez;

    for(int i=0;i<grid.size();i++){
        for(int j=i+1;j<grid.size();j++){
            if(grid[i].first==grid[j].first ||
                grid[i].second==grid[j].first ||
                grid[i].first==grid[j].second ||
                grid[i].second==grid[j].second)
            for(int k=j+1;k<grid.size();k++){
                checkSame(grid,i,j,k,tempRez);
            }
        }       
    }

    sort(tempRez.begin(),tempRez.end());

    vector<vector<string>> rez;
    for(int i=0;i<tempRez.size();i++){
        if(tempRez[i][0][0]=='t' || tempRez[i][1][0]=='t' || tempRez[i][2][0]=='t'){
            rez.push_back(tempRez[i]);
        }
    }
    /*for(auto row:rez){
        for(auto x:row){
            cout<<x<<" ";
        }
        cout<<endl;
    }*/
   cout<<rez.size();


    return 0;
}


bool checkSame(vector<pair<string,string>>& grid,ull x,ull y,ull z,vector<vector<string>>&rez){
    string xf=grid[x].first,yf=grid[y].first,zf=grid[z].first;
    string xs=grid[x].second,ys=grid[y].second,zs=grid[z].second;
    vector<string> row;
    if(xf==yf){
        row.push_back(xf);
        row.push_back(xs);
        row.push_back(ys);
        if(xs==zf && ys==zs){
            rez.push_back(row);
            return true;
        }
        if(xs==zs && ys==zf){
            rez.push_back(row);
            return true;
        }
        row.clear();
    }
    if(xf==ys){
        row.push_back(xf);
        row.push_back(xs);
        row.push_back(yf);
        if(xs==zf && yf==zs){
            rez.push_back(row);
            return true;
        }
        if(xs==zs && yf==zf){
            rez.push_back(row);
            return true;
        }
        row.clear();
    }
    if(xf==zf){
        row.push_back(xf);
        row.push_back(xs);
        row.push_back(ys);
        if(xs==yf && ys==zs){
            rez.push_back(row);
            return true;
        }
        if(xs==ys && yf==zs){
            rez.push_back(row);
            return true;
        }
        row.clear();
    }
    if(xf==zs){
        row.push_back(xf);
        row.push_back(xs);
        row.push_back(zf);
        if(xs==yf && ys==zf){
            rez.push_back(row);
            return true;
        }
        if(xs==ys && yf==zf){
            rez.push_back(row);
            return true;
        }
        row.clear();
    }
    return false;
}



