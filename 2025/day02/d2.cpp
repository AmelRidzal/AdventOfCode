#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include<math.h>
using namespace std;



int getDigits(int );
bool isFivePartRepeat(long long );
bool isThreePartRepeat(long long );
bool isSevenPartRepeat(long long );
bool isNinePartRepeat(long long );
bool isTwoPartRepeat(long long );
bool allDigitsSame(long long );



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

    
    for (const auto& row : grid) {
        cout << row.first << " "<<row.second;
        cout << "\n";
    }

    long long int rez=0;
    for(int i=0;i<grid.size();i++){
        for(long long int j=grid.at(i).first;j<=grid.at(i).second;j++){
            long long int numOfdigits=0;
            long long int x=j;
            while(x>0){
                numOfdigits++;
                x=x/10;
            }
            if(numOfdigits%2==0 && numOfdigits>2){
                if(isTwoPartRepeat(j)){
                    rez=rez+j;
                    cout<<"two "<<j<<endl;
                    continue;
                }//37432260639
                 //37432260594
            }
            if(numOfdigits%3==0 && numOfdigits>3){
                if(isThreePartRepeat(j)){
                    rez=rez+j;
                    cout<<"tree "<<j<<endl;
                    continue;
                }
            }
            if(numOfdigits%5==0 && numOfdigits>5){
                if(isFivePartRepeat(j)){
                    rez=rez+j;
                    cout<<"five "<<j<<endl;
                    continue;
                }
            }
            if(numOfdigits%7==0 && numOfdigits>7){
                if(isSevenPartRepeat(j)){
                    rez=rez+j;
                    cout<<"seven "<<j<<endl;
                    continue;
                }
            }
            if(numOfdigits%9==0 && numOfdigits>9){
                if(isNinePartRepeat(j)){
                    rez=rez+j;
                    cout<<"nini "<<j<<endl;
                    continue;
                }
            }
            if(allDigitsSame(j)&&numOfdigits>1){
                    rez=rez+j;
                    cout<<"same "<<j<<endl;
                    continue;
            }
           
    }
}

    cout << "\n";
    cout<<rez;

    return 0;
}

int getDigits(int x){
    int ret=0;
    
    return ret;
}


bool isFivePartRepeat(long long x) {
    string s = to_string(x);
    int n = s.size();

    if (n % 5 != 0) return false;

    int len = n / 5;
    string part = s.substr(0, len);

    for (int i = 1; i < 5; i++) {
        if (s.substr(i * len, len) != part)
            return false;
    }

    return true;
}


bool isThreePartRepeat(long long x) {
    string s = to_string(x);
    int n = s.size();

    // Must split into 3 equal parts
    if (n % 3 != 0) return false;

    int len = n / 3;
    string part = s.substr(0, len);

    // Check all 3 parts
    for (int i = 1; i < 3; i++) {
        if (s.substr(i * len, len) != part)
            return false;
    }

    return true;
}


bool isSevenPartRepeat(long long x) {
    string s = to_string(x);
    int n = s.size();

    // Must split into 3 equal parts
    if (n % 7 != 0) return false;

    int len = n / 7;
    string part = s.substr(0, len);

    // Check all 3 parts
    for (int i = 1; i < 7; i++) {
        if (s.substr(i * len, len) != part)
            return false;
    }

    return true;
}
bool isNinePartRepeat(long long x) {
    string s = to_string(x);
    int n = s.size();

    // Must split into 3 equal parts
    if (n % 9 != 0) return false;

    int len = n / 9;
    string part = s.substr(0, len);

    // Check all 3 parts
    for (int i = 1; i < 9; i++) {
        if (s.substr(i * len, len) != part)
            return false;
    }

    return true;
}
bool isTwoPartRepeat(long long x) {
    string s = to_string(x);
    int n = s.size();

    // Must split into 3 equal parts
    if (n % 2 != 0) return false;

    int len = n / 2;
    string part = s.substr(0, len);

    // Check all 3 parts
    for (int i = 1; i < 2; i++) {
        if (s.substr(i * len, len) != part)
            return false;
    }

    return true;
}

bool allDigitsSame(long long x) {
    string s = to_string(x);
    for (char c : s)
        if (c != s[0])
            return false;
    return true;
}