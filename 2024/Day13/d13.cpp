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

    vector<vector<ull>> grid;   
    string line;
        vector<ull> row;

    while (getline(file, line)) {
        if (line.empty()) continue;  

        stringstream ss(line);
        ull x;
        char c;
        ss>>c;
        if(c=='B'){
            for(ull i=0;i<9;i++){
                ss >> c;
            }
            ss>>x;
            row.push_back(x);
            for(ull i=0;i<3;i++){
                ss >> c;
            }
            ss>>x;
            row.push_back(x);
        }else if(c=='P'){
            for(ull i=0;i<7;i++){
                ss >> c;
            }
            ss>>x;
            //x=x+10000000000000;
            row.push_back(x);
            for(ull i=0;i<3;i++){
                ss >> c;
            }
            ss>>x;
            //x=x+10000000000000;
            row.push_back(x);
            grid.push_back(row);
            row.clear();

        }

    }

    
    for (const auto& row : grid) {
        for (ull x : row) cout << x << " ";
        cout << "\n";
    }

    ull praviRez=0;

    for(ull i=0;i<grid.size();i++){
        ull div1=0,div2=0;
        vector<pair<ull,ull>> posX;
        div1=grid.at(i).at(4)/grid.at(i).at(0);
        for(ull j=1;j<=div1;j++){
            if((grid.at(i).at(4)-(grid.at(i).at(0)*j))%grid.at(i).at(2)==0){
                pair<ull,ull> temp;
                temp.first=j;
                temp.second=(grid.at(i).at(4)-(grid.at(i).at(0)*j))/grid.at(i).at(2);
                posX.push_back(temp);
            }
        }

        
        vector<pair<ull,ull>> posY;
        div1=grid.at(i).at(5)/grid.at(i).at(1);
        for(ull j=1;j<=div1;j++){
            if((grid.at(i).at(5)-(grid.at(i).at(1)*j))%grid.at(i).at(3)==0){
                pair<ull,ull> temp;
                temp.first=j;
                temp.second=(grid.at(i).at(5)-(grid.at(i).at(1)*j))/grid.at(i).at(3);
                posY.push_back(temp);
            }
        }

        vector<pair<ull,ull>> rez;
        for(ull j=0;j<posX.size();j++){
            for(ull k=0;k<posY.size();k++){
                if(posX.at(j)==posY.at(k)){
                    rez.push_back(posX.at(j));
                    break;
                }
            }
        }

        if(rez.size()>1){
            ull min=0;
            for(auto p:rez){
                ull temp=p.first*3+p.second;
                if(temp<min){
                    min=temp;
                }
            }
            praviRez=praviRez+min;
        }else{
            for(auto p:rez){
                //cout<<p.first<<" "<<p.second<<endl;
                praviRez=praviRez+p.first*3+p.second;
            }
        }
        //for(auto p:posX){cout<<p.first<<" "<<p.second<<endl;}
        //cout<<endl;
        //for(auto p:posY){cout<<p.first<<" "<<p.second<<endl;}
        //cout<<endl;
        //cout<<endl;
    }

    
    /*
    for(ull i=0;i<grid.size();i++){
        ull D=grid.at(i).at(0)*grid.at(i).at(3)-grid.at(i).at(2)*grid.at(i).at(1);
        if(D!=0){
            ull B=(grid.at(i).at(1)*grid.at(i).at(4)-grid.at(i).at(0)*grid.at(i).at(5))/(grid.at(i).at(2)*grid.at(i).at(1)-grid.at(i).at(0)*grid.at(i).at(3));
            ull A=(grid.at(i).at(4)-grid.at(i).at(2)*B)/grid.at(i).at(0);
            if(B<100000000){
                praviRez=praviRez+A+B;
                cout<<A<<" "<<B<<endl;
            }
        }
    }*/

    cout<<praviRez;
    return 0;
}