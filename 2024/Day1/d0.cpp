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
    //std::cout << std::setprecision(10); 

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
    std::vector<unsigned long long int> x;
    for (size_t i = 0; i < left.size(); i++) {
        std::cout<<left[i] <<" - "<< right[i] <<" = "<<left[i] - right[i]<<std::endl;
        x.push_back(left[i] - right[i]);
        //std::cout<<x[i];

    }
    
    for (size_t i = 0; i < left.size(); i++) {
        rez=rez + abs(x.at(i));
    }
    std::cout<<left.size()<<std::endl;
    std::cout<<rez;

    return 0;
}
