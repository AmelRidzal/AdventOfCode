#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

bool isGoodDec(std::vector<unsigned long long int>);
bool isGoodAce(std::vector<unsigned long long int>);

int main() {
    
        std::ifstream file("input");
    if (!file) {
        std::cerr << "Could not open file!\n";
        return 1;
    }

    
    std::vector<std::vector<unsigned long long int>> vecvec;   
    std::string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  

        std::stringstream ss(line);
        std::vector<unsigned long long int> row;
        int x;

        while (ss >> x) {
            row.push_back(x);
        }

        vecvec.push_back(row);
    }



    unsigned long long int rez=0;
    for (size_t i = 0; i < vecvec.size(); i++) {
        if(isGoodDec(vecvec[i]) || isGoodAce(vecvec[i])){
            rez++;
        }else{
            std::cout<<"here"<<std::endl;
            for (int k = 0; k < vecvec[i].size(); k++)
                std::cout<<vecvec[i][k]<<" ";
                std::cout<<std::endl;
            for (int k = 0; k < vecvec[i].size(); k++) {
                std::vector<unsigned long long int> temp;
                temp.reserve(vecvec[i].size() - 1);

                for (int j = 0; j < vecvec[i].size(); j++) {
                    if (k != j) temp.push_back(vecvec[i][j]);
                }
                
                //std::cout<<temp[k]<<" "<<std::endl;
                if (isGoodDec(temp) || isGoodAce(temp)) {
                    rez++;
                    break;
                }
            }
        }
    }
    
    std::cout<<rez;
    return 0;
}

bool isGoodDec(std::vector<unsigned long long int> vec){
    for (size_t j = 1; j < vec.size(); j++){
        if(vec[j-1]-vec[j]>3 || vec[j-1]-vec[j]<1){
            return false;
        }
    }
    return true;
}

bool isGoodAce(std::vector<unsigned long long int> vec){
    for (size_t j = 1; j < vec.size(); j++){
        if(vec[j]-vec[j-1]>3 || vec[j]-vec[j-1]<1){
            return false;
        }
    }
    return true;
}


