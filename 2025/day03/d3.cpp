#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;



typedef unsigned long long int ull;

int main(){

ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<vector<char>> grid;   
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  

        stringstream ss(line);
        vector<char> row;
        char x;
        while (ss >> x) {
            row.push_back(x-'0');
        }

        grid.push_back(row);
    }

    
    for (const auto& row : grid) {
        for (ull x : row) cout << x << " ";
        cout << "\n";
    }

    ull rez=0;
    for(ull i=0;i<grid.size();i++){
            ull cif1=0;
            ull cif2=0;
            ull cif3=0;
            ull cif4=0;
            ull cif5=0;
            ull cif6=0;
            ull cif7=0;
            ull cif8=0;
            ull cif9=0;
            ull cif10=0;
            ull cif11=0;
            ull cif12=0;
        ull marker=0;
        for(ull j=0;j<grid.at(i).size()-11;j++){
            if(grid.at(i).at(j)>cif1){
                cif1=grid.at(i).at(j);
                marker=j;
            }
        }
        for(ull j=marker+1;j<grid.at(i).size()-10;j++){
            if(grid.at(i).at(j)>cif2){
                cif2=grid.at(i).at(j);
                marker=j;
            }
        }
        for(ull j=marker+1;j<grid.at(i).size()-9;j++){
            if(grid.at(i).at(j)>cif3){
                cif3=grid.at(i).at(j);
                marker=j;
            }
        }
        for(ull j=marker+1;j<grid.at(i).size()-8;j++){
            if(grid.at(i).at(j)>cif4){
                cif4=grid.at(i).at(j);
                marker=j;
            }
        }
        for(ull j=marker+1;j<grid.at(i).size()-7;j++){
            if(grid.at(i).at(j)>cif5){
                cif5=grid.at(i).at(j);
                marker=j;
            }
        }
        for(ull j=marker+1;j<grid.at(i).size()-6;j++){
            if(grid.at(i).at(j)>cif6){
                cif6=grid.at(i).at(j);
                marker=j;
            }
        }
        for(ull j=marker+1;j<grid.at(i).size()-5;j++){
            if(grid.at(i).at(j)>cif7){
                cif7=grid.at(i).at(j);
                marker=j;
            }
        }
        for(ull j=marker+1;j<grid.at(i).size()-4;j++){
            if(grid.at(i).at(j)>cif8){
                cif8=grid.at(i).at(j);
                marker=j;
            }
        }
        for(ull j=marker+1;j<grid.at(i).size()-3;j++){
            if(grid.at(i).at(j)>cif9){
                cif9=grid.at(i).at(j);
                marker=j;
            }
        }
        for(ull j=marker+1;j<grid.at(i).size()-2;j++){
            if(grid.at(i).at(j)>cif10){
                cif10=grid.at(i).at(j);
                marker=j;
            }
        }
        for(ull j=marker+1;j<grid.at(i).size()-1;j++){
            if(grid.at(i).at(j)>cif11){
                cif11=grid.at(i).at(j);
                marker=j;
            }
        }
        for(ull j=marker+1;j<grid.at(i).size();j++){
            if(grid.at(i).at(j)>cif12){
                cif12=grid.at(i).at(j);
                marker=j;
            }
        }cout<<cif1<<cif2<<cif3<<cif4<<cif5<<cif6<<cif7<<cif8<<cif9<<cif10<<cif11<<cif12<<endl;
        rez=rez+cif1*100000000000+cif2*10000000000+cif3*1000000000+cif4*100000000+cif5*10000000+cif6*1000000+cif7*100000+cif8*10000+cif9*1000+cif10*100+cif11*10+cif12*1;
    
    }
    cout<<rez;
    return 0;
}