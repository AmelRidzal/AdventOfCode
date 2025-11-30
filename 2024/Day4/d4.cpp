#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;


int main() {
    ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<string> rows;   
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  

        stringstream ss(line);
        rows.push_back(line);

    }

    long long int rez=0;
    /*for(int i=0;i<rows.size();i++){    //part one
        for(int j=0;j<rows.at(i).size();j++){
            if(rows[i][j]=='X'){
                if(j+3<rows.at(i).size())
                    if(rows[i][j+1]=='M' && rows[i][j+2]=='A' && rows[i][j+3]=='S'){rez++;}
                if(j+3<rows.at(i).size() && i+3<rows.size())
                    if(rows[i+1][j+1]=='M' && rows[i+2][j+2]=='A' && rows[i+3][j+3]=='S'){rez++;}
                if(i+3<rows.size())
                    if(rows[i+1][j]=='M' && rows[i+2][j]=='A' && rows[i+3][j]=='S'){rez++;}
                if(j-3>=0 && i+3<rows.size())
                    if(rows[i+1][j-1]=='M' && rows[i+2][j-2]=='A' && rows[i+3][j-3]=='S'){rez++;}
                if(j-3>=0)
                    if(rows[i][j-1]=='M' && rows[i][j-2]=='A' && rows[i][j-3]=='S'){rez++;}
                if(j-3>=0 && i-3>=0)
                    if(rows[i-1][j-1]=='M' && rows[i-2][j-2]=='A' && rows[i-3][j-3]=='S'){rez++;}
                if(i-3>=0)
                    if(rows[i-1][j]=='M' && rows[i-2][j]=='A' && rows[i-3][j]=='S'){rez++;}
                if(j+3<rows.at(i).size() && i-3>=0)
                    if(rows[i-1][j+1]=='M' && rows[i-2][j+2]=='A' && rows[i-3][j+3]=='S'){rez++;}
            }
        }
    }*/


    for(int i=1;i<rows.size()-1;i++){    
        for(int j=1;j<rows.at(i).size()-1;j++){
            if(rows[i][j]=='A'){
                if(rows[i-1][j-1]=='M' && rows[i-1][j+1]=='M' && rows[i+1][j+1]=='S' && rows[i+1][j-1]=='S'){rez++;}
                if(rows[i-1][j-1]=='M' && rows[i-1][j+1]=='S' && rows[i+1][j+1]=='S' && rows[i+1][j-1]=='M'){rez++;}
                if(rows[i-1][j-1]=='S' && rows[i-1][j+1]=='M' && rows[i+1][j+1]=='M' && rows[i+1][j-1]=='S'){rez++;}
                if(rows[i-1][j-1]=='S' && rows[i-1][j+1]=='S' && rows[i+1][j+1]=='M' && rows[i+1][j-1]=='M'){rez++;}
            }
        }
    }
   
        std::cout << rez << " ";
  

    return 0;
}


