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

    vector<pair<char,int>> grid;   // each line becomes one vector<int>
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  // skip blank lines

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

    // Prlong long int to confirm
    for (const auto& row : grid) {
         cout << row.first << " "<< row.second<< " ";
    }
        cout << "\n";

    int rez=50;
    int rezz=0;
    for(int i=0;i<grid.size();i++){
        if(grid.at(i).first=='L'){
            for(int j=0;j<grid.at(i).second;j++){
            rez--;
        while(rez<0){
            rez+=100;
        }
        while(rez>99){
            rez-=100;
        }
        if(rez==0){
            rezz++;
        }
            }
        }else{
            for(int j=0;j<grid.at(i).second;j++){
            rez++;
        while(rez<0){
            rez+=100;
        }
        while(rez>99){
            rez-=100;
        }
        if(rez==0){
            rezz++;
        }
        }
    }
}

    cout<<rezz;

    return 0;
}