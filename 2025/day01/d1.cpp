#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main(){
    ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<pair<char,int>> grid;  
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue; 

        stringstream ss(line);
        char c;
        long long int x;
        while (ss >> c >> x) {
            pair<char,int> temp;
            temp.first=c;
            temp.second=x;
            grid.push_back(temp);
        }
    }

    /*for (const auto& row : grid) {
         cout << row.first << " "<< row.second<< " ";
    }
    cout << "\n";*/

    int start=50;
    int rezzp1=0;

    //part1
    for(int i=0;i<grid.size();i++){
            if(grid.at(i).first=='L'){
                start-=grid.at(i).second;
            }else{
                start+=grid.at(i).second;
            }
            while(start<0){
                start+=100;
            }
            while(start>99){
                start-=100;
            }
            if(start==0){
                rezzp1++;
            }
        
    }

    //part2
    int rezzp2=0;
    start=50;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid.at(i).second;j++){
            if(grid.at(i).first=='L'){
                start--;
            }else{
                start++;
            }
            if(start<0){
                start+=100;
            }else if(start>99){
                start-=100;
            }
            if(start==0){
                rezzp2++;
            }
        }
    }

    cout<<"part1: "<<rezzp1<<endl;
    cout<<"part2: "<<rezzp2<<endl;
    return 0;
}