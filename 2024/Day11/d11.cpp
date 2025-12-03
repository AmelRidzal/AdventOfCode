#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include<math.h>
using namespace std;


typedef unsigned long long int ull;

ull getDigits(ull);



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
        while (ss >> x) {
            row.push_back(x);
        }
    }

    
        for (ull x : row) cout << x << " ";
        cout << "\n";




    for(ull i=0;i<75;i++){
        cout<<"After "<<i+1<<" blink:"<<endl;
        for(ull j=0;j<row.size();j++){
            if(row[j]==0){
                row[j]=1;
            }else{ 
                ull numOfDigits=getDigits(row[j]);
                if(numOfDigits%2==0){
                    ull first=row[j], second=0;
                    for(ull k=0;k<numOfDigits/2;k++){
                        second=second+ (first%10)*pow(10,k);
                        first=first/10;
                    }
                    row.push_back(row.at(row.size()-1));
                    for(ull k=1;k<row.size()-j-1;k++){
                        row.at(row.size()-1-k)=row.at(row.size()-2-k);
                    }
                    row.at(j)=first; //cout<<first<<" "<<second<<endl;
                    row.at(j+1)=second;
                    j++;
                }else{
                    row[j]*=2024;
                }
            }
        }
        if(i==74){
            for (ull x : row) cout << x << " ";
            cout << "\n";
        }

    }

    cout<<row.size()<<endl;

    return 0;
}

ull getDigits(ull x){
    ull ret=0;
    while(x>0){
        ret++;
        x=x/10;
    }
    return ret;
}