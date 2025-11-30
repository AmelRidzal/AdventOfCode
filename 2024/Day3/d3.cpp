#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

bool checkNumber(char);
int getNumber(char);

int main() {
    ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<string> rows;   
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  

        stringstream ss(line);
        rows.push_back(line);

    }

    long long int rez=0;
    bool enable = true;
    for(int i=0;i<rows.size();i++){
        for(int j=0;j<rows.at(i).size();j++){
            if(rows[i][j]=='m' && enable){
                if(rows[i][j+1]=='u' && rows[i][j+2]=='l' && rows[i][j+3]=='('){
                    j+=4;
                    int num1=0,num2=0;
                    if(checkNumber(rows[i][j])){
                        num1=getNumber(rows[i][j]);
                        j++;
                        if(checkNumber(rows[i][j])){
                            num1=num1*10+getNumber(rows[i][j]);
                            j++;
                            if(checkNumber(rows[i][j])){
                                num1=num1*10+getNumber(rows[i][j]);
                                j++;
                            }
                        }
                        if(rows[i][j]==','){
                            j++;
                            if(checkNumber(rows[i][j])){
                                num2=getNumber(rows[i][j]);
                                j++;
                                if(checkNumber(rows[i][j])){
                                    num2=num2*10+getNumber(rows[i][j]);
                                    j++;
                                    if(checkNumber(rows[i][j])){
                                        num2=num2*10+getNumber(rows[i][j]);
                                        j++;
                                    }
                                }if(rows[i][j]==')'){
                                    rez=rez+num1*num2;
                                }
                            }
                        }
                    }
                }
            }else if(rows[i][j]=='d'){
                if(rows[i][j+1]=='o' && rows[i][j+2]=='(' && rows[i][j+3]==')'){
                    enable=true;
                    j=j+3;
                }else if(rows[i][j+1]=='o' && rows[i][j+2]=='n' && rows[i][j+3]=='\'' && rows[i][j+4]=='t' && rows[i][j+5]=='(' && rows[i][j+6]==')'){
                    enable=false;
                    j=j+6;
                }
            }
        }
    }

   
        std::cout << rez << " ";
  

    return 0;
}


bool checkNumber(char c){
    if(c>='0' && c<= '9'){
        return true;
    }
    return false;
}

int getNumber(char c){
    return c-'0';
}