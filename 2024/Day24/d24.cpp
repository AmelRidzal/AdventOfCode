#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


typedef long long int ull;
bool checkBelong(vector<pair<string,ull>>& ,string );
int findIndex(vector<pair<string,ull>>& ,string );

int main(){

ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<pair<string,ull>> list; 
    vector<vector<string>> target;   
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  

        stringstream ss(line);
        if (line.find('-') == string::npos){
            string s;
            char c1,c2,c3;
            ull x;
            ss>>c1>>c2>>c3;
            s=s+c1+c2+c3;
            ss>>c1>>x;
            list.push_back({s,x});
        }else{
            vector<string> row;
            string s;
            char c1,c2,c3;
            ss>>c1>>c2>>c3;
            s=s+c1+c2+c3;
            row.push_back(s);
            if(checkBelong(list,s)){
                list.push_back({s,-1});
            }
            s.clear();
            ss>>c1>>c2;
            if(c1!='O'){
                ss>>c3;
                s=s+c1+c2+c3;
            }else{
                s=s+c1+c2;
            }
            row.push_back(s);
            s.clear();
            ss>>c1>>c2>>c3;
            s=s+c1+c2+c3;
            row.push_back(s);
            if(checkBelong(list,s)){
                list.push_back({s,-1});
            }
            s.clear();
            ss>>c1>>c1>>c1>>c2>>c3;
            s=s+c1+c2+c3;
            row.push_back(s);
            if(checkBelong(list,s)){
                list.push_back({s,-1});
            }
            s.clear();
            target.push_back(row);
        }



    }

    
    //for (auto x : list) cout << x.first << " "<<x.second<<endl;

        
    /*for (const auto& row : target) {
        for (string x : row) cout << x << " ";
        cout << "\n";
    }*/

    while(target.size()!=0)
        for (int i=0;i<target.size();i++){
            auto row =target[i];
            string s1=row[0], s2=row[2], s3=row[3];
            string op=row[1];
            ull x1=findIndex(list,s1);
            ull x2=findIndex(list,s2);
            ull x3=findIndex(list,s3);
            if(list[x1].second!=-1 && list[x2].second!=-1){
                if(op=="AND"){
                    list[x3].second=list[x1].second+list[x2].second;
                    if(list[x3].second!=0)list[x3].second--;
                }else if(op=="XOR"){
                    list[x3].second=list[x1].second^list[x2].second;
                }else if(op=="OR"){
                    list[x3].second=list[x1].second+list[x2].second;
                    if(list[x3].second==2)list[x3].second--;
                }
                target.erase(target.begin()+i);
                i--;
            }
            
        }
    sort(list.begin(),list.end());
    for (auto x : list) cout << x.first << " "<<x.second<<endl;
    ull rez=0;
    ull counter=0;
    for(int i=0;i<list.size();i++){
        if(list[i].first[0]=='z'){
            if(list[i].second==1)
                rez=rez+pow(2,counter);
            counter++;
        }
    }
    cout<<rez;


    return 0;
}

bool checkBelong(vector<pair<string,ull>>& list,string s){
    for(auto x: list){
        if(x.first==s){
            return false;
        }
    }
    return true;
}

int findIndex(vector<pair<string,ull>>& list,string s){
    for(int i=0;i<list.size();i++){
        if(list[i].first==s){
            return i;
        }
    }
    return -1;
}