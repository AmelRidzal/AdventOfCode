#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int getCombo(int x, int ra, int rb, int rc){
    if(x>=0 && x<=3){
        return x;
    }else if(x==4){
        return ra;
    }else if(x==5){
        return rb;
    }else if(x==6){
        return rc;
    }return -1;
};

void adv(int &A, int comboOperand){
    int denominator = 1 << comboOperand;   
    A = A / denominator;
}

void bxl(int &B, int literalOperand){
    B ^= literalOperand;
}

void bst(int &B, int comboOperand){
    B = comboOperand % 8; 
}

void jnz(int A, int literalOperand, int &ip){
    if (A != 0){
        ip = literalOperand; 
    }
    else{
        ip += 2; 
    }
}

void bxc(int &B, int C){
    B ^= C;
}


void out(int comboOperand){
    int value = comboOperand % 8;
    cout << value<< ",";
}

void bdv(int A, int comboOperand, int &B){
    int denominator = 1 << comboOperand;
    B = A / denominator;
}

void cdv(int A, int comboOperand, int &C){
    int denominator = 1 << comboOperand;
    C = A / denominator;
}


int main(){

ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<int> prog;
    int regA,regB,regC;   
    string line;
    int regCounter=0;

    while (getline(file, line)) {
        if (line.empty()) continue;  

        stringstream ss(line);
        char c;
        int x;
        if (line.find('R') != string::npos) {
            for(int i=0;i<10;i++){
                ss>>c;
            }
            ss>>x;
            if(regCounter==0){
                regA=x;
                regCounter++;
            }else if(regCounter==1){
                regB=x;
                regCounter++;
            }else{
                regC=x;
                regCounter++;
            }
        }else{
            for(int i=0;i<7;i++){
                ss>>c;
            }
            while (ss >> c >> x) {
                prog.push_back(x);
            }

        }
    }
    
    for (int x : prog) cout << x << " ";
    cout << "\n";

    int ip=0;
    int temp;
    while(ip<prog.size()){
        switch (prog[ip])
        {
        case 0:
            temp=getCombo(prog[ip+1],regA,regB,regC);
            adv(regA,temp);
            break;
        case 1:
            bxl(regB, prog[ip+1]);
            break;
        case 2:
            temp=getCombo(prog[ip+1],regA,regB,regC);
            bst(regB, temp);
            break;
        case 3:
            jnz(regA,prog[ip+1],ip);
            continue;
            break;
        case 4:
            bxc(regB, regC);
            break;
        case 5:
            temp=getCombo(prog[ip+1],regA,regB,regC);
            out(temp);
            break;
        case 6:
            temp=getCombo(prog[ip+1],regA,regB,regC);
            bdv(regA, temp, regB);
            break;
        case 7:
            temp=getCombo(prog[ip+1],regA,regB,regC);
            cdv(regA, temp, regC);
            break;
        default:
            break;
        }
        ip+=2;
    }

    return 0;
}