#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;



typedef unsigned long long int ull;
long long int strToInt(string );

int main(){

ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<string> grid; 
    vector<char> sign;  
    string line;
    bool readingFirst=true;

    while (getline(file, line)) {
        if (line.empty()) continue;  

        if (line.find('+') != string::npos) {readingFirst = false;}
        if(readingFirst){
        /*stringstream ss(line);
        vector<ull> row;
        ull x;
        while (ss >> x) {
            row.push_back(x);
        }*/

        grid.push_back(line);
    }else{ 
        stringstream ss(line);
        char x;
        while (ss >> x) {
            sign.push_back(x);
        }
    }
}

    
    for (const auto& row : grid) {
        cout << row <<endl;
    }
        for (char x : sign) cout << x << " ";
                cout << "\n";

    ull rez=0;

    vector<vector<ull>> newRez;
    vector<string> vecString;
    for(int i=grid.at(0).size()-1;i>=0;i--){
        bool empty=true;
        string s;
        vector<ull> tempVec;
        for(ull j=0;j<grid.size();j++){
            s+=grid[j][i];
        }
        vecString.push_back(s);
        
    }

    cout<<" stringove"<<endl;
    for (const auto& row : vecString) {
        cout<<row<<" ";
        cout <<endl;
    }

    vector<vector<long long int>> finalFormat;
        vector<long long int> tempp;
    for(int i=0;i<vecString.size();i++){
            long long int x = strToInt(vecString.at(i));
            cout<<x<<endl;
        if(x!=0){
            tempp.push_back(x);
        }else{
            finalFormat.push_back(tempp);
            tempp.clear();
        }
    }
            finalFormat.push_back(tempp);

    
    cout<<" ull"<<endl;
    for (const auto& row : finalFormat) {
            for(ull a:row) cout<<a<<" ";
        cout <<endl;
    }

    cout<<endl<<endl<<finalFormat.size()<<endl;
    for(int i=0;i<finalFormat.size();i++){
        ull temp=0;
        if(sign.at(sign.size()-i-1)=='*'){ 
            temp++;
        }
        cout<<finalFormat.at(i).size()<<endl;
        for(int j=0;j<finalFormat.at(i).size();j++){
            cout<<sign.at(sign.size()-i-1)<<" ";
            if(sign.at(sign.size()-i-1)=='+'){
                temp+=finalFormat[i][j];
            }else{
                temp*=finalFormat[i][j];
            }
        }
        rez+=temp;
    }

    cout<< rez;

    return 0;
}

long long int strToInt(string s){
    long long int ret=0;
    for(char c:s){
        if(c<='9' && c>='0')
        ret=ret*10+c-'0';
    }
    return ret;
}