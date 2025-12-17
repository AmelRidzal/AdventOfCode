#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
typedef long long int ull;

ull getCombo(ull x, ull ra, ull rb, ull rc){
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

void adv(ull &A, ull comboOperand){
    ull denominator = 1 << comboOperand;   
    A = A / denominator;
}

void bxl(ull &B, ull literalOperand){
    B ^= literalOperand;
}

void bst(ull &B, ull comboOperand){
    B = comboOperand % 8; 
}

void jnz(ull A, ull literalOperand, ull &ip){
    if (A != 0){
        ip = literalOperand; 
    }
    else{
        ip += 2; 
    }
}

void bxc(ull &B, ull C){
    B ^= C;
}


void out(ull comboOperand, vector<ull>& cur, vector<ull>& rez, bool &chekc){
    ull value = comboOperand % 8;
    cout << value<< ",";
    if(rez.at(cur.size())!=value){
        chekc=false;
        cur.clear();
        return;
    }
    cur.push_back(value);
}

void bdv(ull A, ull comboOperand, ull &B){
    ull denominator = 1 << comboOperand;
    B = A / denominator;
}

void cdv(ull A, ull comboOperand, ull &C){
    ull denominator = 1 << comboOperand;
    C = A / denominator;
}

inline int f(long long A)
{
    long long B = (A & 7) ^ 2;
    long long C = A >> B;
    return (int)((B ^ C) & 7);
}

bool valid(long long X)
{
    static int want[16] = {
        5, 3, 6, 5, 0, 2, 7, 4,
        3, 0, 6, 0, 2, 2, 4, 7
    };

    long long A = X;
    for (int i = 0; i < 16; i++)
    {
        if (f(A) != want[i])
            return false;
        A >>= 3; // A = A / 8
    }

    return A == 0;
}








int main(){

    ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    ofstream outFile("output");
    if (!outFile) {
        cerr << "Could not open output file!\n";
        return 1;
    }
    vector<ull> prog;
    ull regA,regB,regC;   
    string line;
    ull regCounter=0;

    while (getline(file, line)) {
        if (line.empty()) continue;  

        stringstream ss(line);
        char c;
        ull x;
        if (line.find('R') != string::npos) {
            for(ull i=0;i<10;i++){
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
            for(ull i=0;i<7;i++){
                ss>>c;
            }
            while (ss >> c >> x) {
                prog.push_back(x);
            }

        }
    }
    
    for (ull x : prog) cout << x << " ";
    cout << "\n";

    ull ip=0;
    ull temp;
    ull tempRegA=147100114959;
    ull write=tempRegA+100000000;
    vector<ull> cur;

    bool check =false;
    while(!check || cur.size()!=prog.size()){
        check=true;
        while(!valid(tempRegA)){
            tempRegA++;
            if(write<tempRegA){
                cout<<endl<<tempRegA-1<<endl;
                write+=100000000;
                outFile << tempRegA - 1 << endl;
            }
        }
        regA=tempRegA;
        tempRegA++;
        ip=0;
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
                out(temp,cur,prog,check);
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
            if(!check){
                break;
            }
        }
    }
    cout<<tempRegA - 1;
    return 0;
}

/*
A=X 
B=Amod8 
B=Bxor2 
C=A/(pow(2,B)) **if B=3 then its A/8**
A=A/8
B=BxorC 
B=Bxor7 
Bmod8==2 
B=Amod8 
B=Bxor2 
C=A/(pow(2,B)) **if B=3 then its A/8**
A=A/8
B=BxorC 
B=Bxor7 
Bmod8==4  
B=Amod8 
B=Bxor2 
C=A/(pow(2,B)) **if B=3 then its A/8**
A=A/8
B=BxorC 
B=Bxor7 
Bmod8==1  
B=Amod8 
B=Bxor2 
C=A/(pow(2,B)) **if B=3 then its A/8**
A=A/8
B=BxorC 
B=Bxor7 
Bmod8==2 
B=Amod8 
B=Bxor2 
C=A/(pow(2,B)) **if B=3 then its A/8**
A=A/8
B=BxorC 
B=Bxor7 
Bmod8==7  
B=Amod8 
B=Bxor2 
C=A/(pow(2,B)) **if B=3 then its A/8**
A=A/8
B=BxorC 
B=Bxor7 
Bmod8==5    
B=Amod8 
B=Bxor2 
C=A/(pow(2,B)) **if B=3 then its A/8**
A=A/8
B=BxorC 
B=Bxor7 
Bmod8==0    
B=Amod8 
B=Bxor2 
C=A/(pow(2,B)) **if B=3 then its A/8**
A=A/8
B=BxorC 
B=Bxor7 
Bmod8==3    
B=Amod8 
B=Bxor2 
C=A/(pow(2,B)) **if B=3 then its A/8**
A=A/8
B=BxorC 
B=Bxor7 
Bmod8==4    
B=Amod8 
B=Bxor2 
C=A/(pow(2,B)) **if B=3 then its A/8**
A=A/8
B=BxorC 
B=Bxor7 
Bmod8==7    
B=Amod8 
B=Bxor2 
C=A/(pow(2,B)) **if B=3 then its A/8**
A=A/8
B=BxorC 
B=Bxor7 
Bmod8==1    
B=Amod8 
B=Bxor2 
C=A/(pow(2,B)) **if B=3 then its A/8**
A=A/8
B=BxorC 
B=Bxor7 
Bmod8==7      
B=Amod8 
B=Bxor2 
C=A/(pow(2,B)) **if B=3 then its A/8**
A=A/8
B=BxorC 
B=Bxor7 
Bmod8==5      
B=Amod8 
B=Bxor2 
C=A/(pow(2,B)) **if B=3 then its A/8**
A=A/8
B=BxorC 
B=Bxor7 
Bmod8==5      
B=Amod8 
B=Bxor2 
C=A/(pow(2,B)) **if B=3 then its A/8**
A=A/8
B=BxorC 
B=Bxor7 
Bmod8==3      
B=Amod8 
B=Bxor2 
C=A/(pow(2,B)) **if B=3 then its A/8**
A=A/8
B=BxorC 
B=Bxor7 
Bmod8==0  
A==0
find the X formula, integers */