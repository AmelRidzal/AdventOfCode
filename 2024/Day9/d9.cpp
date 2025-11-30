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

    vector<int> vec;   // each line becomes one vector<int>
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  // skip blank lines

        stringstream ss(line);
        char x;
        while (ss >> x) {
            vec.push_back(x-48);
        }
    }

    for (int x : vec) cout << x << " ";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    
    vector<int> vecMain;

    bool free=false;
    int id=0;
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec.at(i);j++){
            if(free){
                vecMain.push_back('.');
            }else{
                vecMain.push_back(id);
            }
        }
        free=!free;
        if(free){
            id++;
            if(id==46){
                id=100000;
            }
            if(id==100001){
                id=47;
            }
        }
    }
    
    for (int x : vecMain) cout << x << " ";
    cout << "\n";
    cout << "\n";
    cout << "\n";

    

        for(int i=vecMain.size()-1;i>0;i--){
            if(vecMain.at(i)!='.'){
                int temp =vecMain.at(i);
                int idCount=0;
                while(temp ==vecMain.at(i)){
                    idCount++;
                    i--;
                    if(i<0){
                        break;
                    }
                }i++;
                for(int j=0;j<i;j++){
                    if(vecMain.at(j)=='.'){
                        int hold=j;
                        int dotCount=0;
                        while(vecMain.at(j)=='.'){
                            dotCount++;
                            j++;
                        }
                        if(dotCount>=idCount){
                            for(int k=0;k<idCount;k++){
                                vecMain.at(hold+k)=vecMain.at(i+k);
                                vecMain.at(i+k)='.';
                            }
                            //for (int x : vecMain) if(x==46)cout << "." << " ";else cout << x << " ";
                            //cout << "\n";
                            break;
                        }
                    }
                }
            }
        }
    
    
                        


    
    
    for (int x : vecMain) cout << x << " ";
    cout << "\n";
    cout << "\n";

    unsigned long long int rez=0;
    for(int i=0;i<vecMain.size();i++){
        if(vecMain.at(i)!='.'){
            if(vecMain.at(i)==100000){
                vecMain.at(i)=46;
            }
            rez=rez+(vecMain.at(i)*i);
        }
    }

    cout<< rez;

    return 0;
}