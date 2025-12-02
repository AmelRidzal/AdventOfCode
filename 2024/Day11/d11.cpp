#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include<math.h>
using namespace std;


int getDigits(int);



int main(){

ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<long long int> row;   
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  

        stringstream ss(line);
        long long int x;
        while (ss >> x) {
            row.push_back(x);
        }
    }

    
        for (long long int x : row) cout << x << " ";
        cout << "\n";




    for(int i=0;i<25;i++){
        cout<<"After "<<i+1<<" blink:"<<endl;
        for(int j=0;j<row.size();j++){
            if(row[j]==0){
                row[j]=1;
            }else{ 
                int numOfDigits=getDigits(row[j]);
                if(numOfDigits%2==0){
                    int first=row[j], second=0;
                    for(int k=0;k<numOfDigits/2;k++){
                        second=pow((first%10),k);
                        first=first/10;
                    }
                }else{
                    row[j]*=2025;
                }
            }
        }
        for (long long int x : row) cout << x << " ";
        cout << "\n";

    }

    return 0;
}

int getDigits(int x){
    int ret=0;
    while(x>0){
        ret++;
        x=x/10;
    }
    return ret;
}