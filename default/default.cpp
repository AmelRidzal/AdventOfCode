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

    std::vector<unsigned long long int> vecA, vecB,  vecC, vecD, vecE;

    unsigned long long int a, b, c, d, e;
    while (file >> a >> b) {
        vecA.push_back(a);
        vecB.push_back(b);
        vecC.push_back(c);
        vecD.push_back(d);
        vecE.push_back(e);
    }
    /*
    std::sort(vecA.begin(), vecA.end());
    std::sort(vecB.begin(), vecB.end());
    std::sort(vecC.begin(), vecC.end());
    std::sort(vecD.begin(), vecD.end());
    std::sort(vecE.begin(), vecE.end());
    */
    
    for (size_t i = 0; i < vecA.size(); i++) {

    }
    
    return 0;
}
