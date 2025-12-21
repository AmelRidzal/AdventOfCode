#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;



typedef long long int ull;

int main(){

ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<vector<ull>> locks; 
    vector<vector<ull>> keys;   
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  

        vector<ull> row;
        char c1,c2,c3,c4,c5;
        ull x[5]={-1,-1,-1,-1,-1};
        bool lock=true;
        if(line==".....")lock=false;
        for(int i=0;i<7;i++){
            stringstream ss(line);
            ss>>c1>>c2>>c3>>c4>>c5;
            //cout<<c1<<c2<<c3<<c4<<c5<<endl;
            if(i!=6){
                getline(file, line);
            }
            if(c1=='#')x[0]++;
            if(c2=='#')x[1]++;
            if(c3=='#')x[2]++;
            if(c4=='#')x[3]++;
            if(c5=='#')x[4]++;
            
        }
        //cout<<endl;
        row.push_back(x[0]);
        row.push_back(x[1]);
        row.push_back(x[2]);
        row.push_back(x[3]);
        row.push_back(x[4]);

        if(lock)
            locks.push_back(row);
        else keys.push_back(row);
    }

    
    /*for (const auto& row : locks) {
        for (ull x : row) cout << x << " ";
        cout << "\n";
    }
    for (const auto& row : keys) {
        for (ull x : row) cout << x << " ";
        cout << "\n";
    }*/

    ull rez=0;
    for(ull i=0;i<locks.size();i++){
        for(ull j=0;j<keys.size();j++){
            bool check=true;
            for(int k=0;k<5;k++){
                if(locks[i][k]+keys[j][k]>5){
                    check=false;
                    break;
                }
            }
            if(check)rez++;
        }
    }

    cout<<rez;
    return 0;
}