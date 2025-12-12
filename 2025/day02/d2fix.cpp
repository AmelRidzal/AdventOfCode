#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include<math.h>
using namespace std;


bool isTwoPartRepeat(long long );

bool isRepeatedPattern(std::string s) {
    return (s + s).find(s, 1) < s.length();
}

int main(){

    ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<pair<long long int,long long int>> grid;   
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  

        stringstream ss(line);
        pair<long long int,long long int> row;
        long long int x1;
        long long int x2;
        char c1,c2;
        while (ss >> x1>>c1>>x2>>c2) {
            row.first=x1;
            row.second=x2;
            grid.push_back(row);
        }
    }

    
    /*for (const auto& row : grid) {
        cout << row.first << " "<<row.second;
        cout << "\n";
    }*/

    //part1
    long long int rezp1=0;
    for(int i=0;i<grid.size();i++){
        for(long long int j=grid.at(i).first;j<=grid.at(i).second;j++){
            string s=to_string(j);
            if(s.size()%2==0){
                string s1=s.substr(0,s.size()/2);
                string s2=s.substr(s.size()/2, s.size()/2);
                if(s1==s2 ){
                    rezp1+=j;
                }
            }    
        }
    }


    //part 2
    long long int rezp2=0;
    for(int i=0;i<grid.size();i++){
        for(long long int j=grid.at(i).first;j<=grid.at(i).second;j++){
            string s=to_string(j);
            if(s.size()>1 && isRepeatedPattern(s)){
                rezp2+=j;
            }
        }
    }

    cout << "\n";
    cout<<"part1: "<<rezp1<<endl;
    cout<<"part2: "<<rezp2<<endl;

    return 0;
}


