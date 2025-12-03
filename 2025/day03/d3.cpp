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

    /*for(ull i=0;i<grid.size();i++){
            ull cif1=grid.at(i).at(0);
            ull cif2=grid.at(i).at(1);
            ull cif3=grid.at(i).at(2);
            ull cif4=grid.at(i).at(3);
            ull cif5=grid.at(i).at(4);
            ull cif6=grid.at(i).at(5);
            ull cif7=grid.at(i).at(6);
            ull cif8=grid.at(i).at(7);
            ull cif9=grid.at(i).at(8);
            ull cif10=grid.at(i).at(9);
            ull cif11=grid.at(i).at(10);
            ull cif12=grid.at(i).at(11);
        for(ull j=12;j<grid.at(i).size();j++){
            bool ckeck=false;
            if(cif2>cif1 &&  j<grid.at(i).size()-1){
                cif1=cif2;
                cif2=cif3;
                cif3=cif4;
                cif4=cif5;
                cif5=cif6;
                cif6=cif7;
                cif7=cif8;
                cif8=cif9;
                cif9=cif10;
                cif10=cif11;
                cif11=cif12;
                cif12=grid.at(i).at(j+1);
                j++;
                ckeck=true;
            } 
            if(cif3>cif2 &&  j<grid.at(i).size()-1){
                cif2=cif3;
                cif3=cif4;
                cif4=cif5;
                cif5=cif6;
                cif6=cif7;
                cif7=cif8;
                cif8=cif9;
                cif9=cif10;
                cif10=cif11;
                cif11=cif12;
                cif12=grid.at(i).at(j+1);
                j++;
                ckeck=true;
            } 
            if(cif4>cif3 &&  j<grid.at(i).size()-1){
                cif3=cif4;
                cif4=cif5;
                cif5=cif6;
                cif6=cif7;
                cif7=cif8;
                cif8=cif9;
                cif9=cif10;
                cif10=cif11;
                cif11=cif12;
                cif12=grid.at(i).at(j+1);
                j++;
                ckeck=true;
            } 
            if(cif5>cif4 &&  j<grid.at(i).size()-1){
                cif4=cif5;
                cif5=cif6;
                cif6=cif7;
                cif7=cif8;
                cif8=cif9;
                cif9=cif10;
                cif10=cif11;
                cif11=cif12;
                cif12=grid.at(i).at(j+1);
                j++;
                ckeck=true;
            } 
            if(cif6>cif5 &&  j<grid.at(i).size()-1){
                cif5=cif6;
                cif6=cif7;
                cif7=cif8;
                cif8=cif9;
                cif9=cif10;
                cif10=cif11;
                cif11=cif12;
                cif12=grid.at(i).at(j+1);
                j++;
                ckeck=true;
            } 
            if(cif7>cif6 &&  j<grid.at(i).size()-1){
                cif6=cif7;
                cif7=cif8;
                cif8=cif9;
                cif9=cif10;
                cif10=cif11;
                cif11=cif12;
                cif12=grid.at(i).at(j+1);
                j++;
                ckeck=true;
            } 
            if(cif8>cif7 &&  j<grid.at(i).size()-1){
                cif7=cif8;
                cif8=cif9;
                cif9=cif10;
                cif10=cif11;
                cif11=cif12;
                cif12=grid.at(i).at(j+1);
                j++;
                ckeck=true;
            } 
            if(cif9>cif8 &&  j<grid.at(i).size()-1){
                cif8=cif9;
                cif9=cif10;
                cif10=cif11;
                cif11=cif12;
                cif12=grid.at(i).at(j+1);
                j++;
                ckeck=true;
            } 
            if(cif10>cif9 &&  j<grid.at(i).size()-1){
                cif9=cif10;
                cif10=cif11;
                cif11=cif12;
                cif12=grid.at(i).at(j+1);
                j++;
                ckeck=true;
            } 
            if(cif11>cif10 &&  j<grid.at(i).size()-1){
                cif10=cif11;
                cif11=cif12;
                cif12=grid.at(i).at(j+1);
                j++;
                ckeck=true;
            } 
            if(cif12>cif11 &&  j<grid.at(i).size()-1){
                cif11=cif12;
                cif12=grid.at(i).at(j+1);
                j++;
                ckeck=true;
            } 
            if(grid.at(i).at(j)>cif12){
                cif12=grid.at(i).at(j);
                j++;
                ckeck=true;
            }

            if(ckeck){j--;}

        }

        cout<<cif1<<cif2<<cif3<<cif4<<cif5<<cif6<<cif7<<cif8<<cif9<<cif10<<cif11<<cif12<<endl;
        rez=rez+cif1*100000000000+cif2*10000000000+cif3*1000000000+cif4*100000000+cif5*10000000+cif6*1000000+cif7*100000+cif8*10000+cif9*1000+cif10*100+cif11*10+cif12*1;
    }*/

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