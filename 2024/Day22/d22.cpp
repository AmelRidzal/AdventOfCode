#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;



typedef long long ull;
ull next_secret(ull);


int main(){

ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<ull> row;
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  

        stringstream ss(line);
        ull x;
        ss>>x;
        row.push_back(x);
    }


    
    //for (auto x : row) cout << x <<endl;
    

    for(ull i=0;i<row.size();i++){
        for(int j=0;j<2000;j++){
            row[i]=next_secret(row[i]);
            //cout<<row[i]<<endl;
        }
    }
    
    //for (auto x : row) cout << x <<endl;

    ull rez=0;
    for (auto x : row) rez+=x;

    cout<<rez;

    return 0;
}


ull next_secret(ull secret) {
    secret ^= (secret * 64);
    secret %= 16777216;

    secret ^= (secret / 32);
    secret %= 16777216;

    secret ^= (secret * 2048);
    secret %= 16777216;

    return secret;
}