#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
    std::ifstream file("input");
    if (!file) {
        std::cerr << "Could not open file!\n";
        return 1;
    }

    std::cout << std::setprecision(10); 

    std::vector<unsigned long long int> left;
    std::vector<unsigned long long int> right;

    unsigned long long int a, b;
    while (file >> a >> b) {
        left.push_back(a);
        right.push_back(b);
    }
    
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    
    unsigned long long int rez=0;
    for (size_t i = 0; i < left.size(); i++) {
        int mull =0;
        for(size_t j = 0; j < left.size(); j++){
            if(left[i]==right[j]) {
                mull++; 
                //std::cout<<left[i]<<std::endl;
            }
        }
        rez=rez+left[i]*mull;
    }
    
    std::cout<<rez<<std::endl;
    return 0;
}
