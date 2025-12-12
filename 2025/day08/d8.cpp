#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include<cmath>
#include <tuple>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;



typedef  long long int ull;
unordered_map<int,int> countElements(const vector<int>& ) ;
vector<pair<int,int>> topThree(const unordered_map<int,int>& );
ull findDistance(vector<ull> , vector<ull> );

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
        ss>>x>>c;
        row.push_back(x);
        ss>>x>>c;
        row.push_back(x);
        ss>>x;
        row.push_back(x);
        grid.push_back(row);
    }

    
    /*for (const auto& row : grid) {
        for (ull x : row) cout << x << " ";
        cout << "\n";
    }*/

    //min que
    priority_queue<tuple<ull, int, int>, vector<tuple<ull, int, int>>, greater<tuple<ull, int, int>>> dgrid;   

    ull max=0;
    for(ull i=0;i<grid.size()-1;i++){
        cout<<i<<endl;
        tuple<ull, int, int> drow;   
        for(ull j=i+1;j<grid.size();j++){
            ull temp =findDistance(grid[i],grid[j]);
            drow = make_tuple(temp,i,j);
            dgrid.push(drow);
        }
    }

    vector<int> loops;
    
    for(int k=0;k<grid.size();k++){
        loops.push_back(-1);
    }
    
    for(int k=0;k<1000;k++){
        cout<<k<<endl;
        tuple<ull, int, int> tempRow = dgrid.top();
        dgrid.pop();
        ull a=get<1>(tempRow);
        ull b=get<2>(tempRow);
        if(loops[a]==-1 && loops[b]==-1){
            loops[a]=a;
            loops[b]=a;
        }else if(loops[a]==-1){
            loops[a]=loops[b];
        }else if(loops[b]==-1){
            loops[b]=loops[a];
        }else if(loops[a]!=loops[b]){
            int hodl=loops[b];
            for(int i=0;i<loops.size();i++){
                if(loops[i]==hodl){
                    loops[i]=loops[a];
                }
            }
        }
    }
    
    /*for(auto x:loops){
        cout<<x<<" ";
    }*/
    
    ull rezp1=1;
    auto freq = countElements(loops);
    auto top3 = topThree(freq);
    for (auto& [value, count] : top3) {
        cout << value << " → " << count << " times\n";
        rezp1*=count;
    }
    cout<<rezp1;
    return 0;
}

ull findDistance(vector<ull> first, vector<ull> second){
    ull dx= first[0]-second[0];
    ull dy= first[1]-second[1];
    ull dz= first[2]-second[2];
    ull kv= pow(dx,2)+pow(dy,2)+pow(dz,2);
    return kv;
}

unordered_map<int,int> countElements(const vector<int>& v) {
    unordered_map<int,int> freq;

    for (int x : v) {
        if (x == -1) continue;   // ignore -1
        freq[x]++;
    }

    return freq;
}


vector<pair<int,int>> topThree(const unordered_map<int,int>& freq) {
    vector<pair<int,int>> items(freq.begin(), freq.end());

    sort(items.begin(), items.end(),
         [](auto& a, auto& b) { return a.second > b.second; });

    if (items.size() > 3) items.resize(3);

    return items;
}
