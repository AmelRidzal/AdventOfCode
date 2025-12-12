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

    vector<pair<ull,ull>> grid;   
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  

        stringstream ss(line);
        pair<ull,ull> row;
        ull x;
        char c;

        ss>>x>>c;
        row.first=x;
        ss>>x;
        row.second=x;

        grid.push_back(row);
    }

    pair<ull,ull> filler;
    
    /*for (const auto& row : grid) {
        cout << row.first << " "<< row.second;
        cout << "\n";
    }*/
    ull max=0;

    for(ull i=0;i<grid.size();i++){
        for(ull j=i+1;j<grid.size();j++){
            pair<ull,ull> a=grid[i],b=grid[j];
            //cout<<a.first<<" "<<a.second<<" "<<b.first<<" "<<b.second<<endl;
            if(a.first>b.first){
                ull temp=a.first;
                a.first=b.first;
                b.first=temp;
            }
            if(a.second>b.second){
                ull temp=a.second;
                a.second=b.second;
                b.second=temp;
            }
            /*bool check=false;
            for(ull k=0;k<grid.size();k++){
                if(k==i || k==j)continue;
                if(grid[k].first>=a.first && grid[k].first<b.first && grid[k].second>=a.second && grid[k].second<b.second){
                    check=true;
                    break;
                }
                
            }*/
            //if(!check){
                ull temp1=(b.first-a.first+1)*(b.second-a.second+1);
                //cout<<temp1<<endl;
                if(max < temp1){
                    max=temp1;
                }
            //}
        }
    }
    cout<<max;
    return 0;
}


