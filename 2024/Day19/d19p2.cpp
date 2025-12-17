#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

typedef unsigned long long ull;

long long countWays(const string& s, const vector<string>& parts) {
    int n = s.size();
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        if (dp[i] == 0) continue;

        for (const string& w : parts) {
            int len = w.size();
            if (i + len <= n && s.compare(i, len, w) == 0) {
                dp[i + len] += dp[i];
            }
        }
    }
    return dp[n];
}

int main() {
ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }
 
    vector<string> comp; 
    vector<string> target; 
    string line;
    getline(file, line);
    stringstream ss(line);
    char c;
    string s;
    while(ss>>c){
        if(c!=',' && c!=' '){
            s=s+c;
        }else if(c==','){
            comp.push_back(s);
            s.clear();
        }
    }
    comp.push_back(s);

    while (getline(file, line)) {
        if (line.empty()) continue;  

        stringstream ss(line);
        ss>>s;
        target.push_back(s);
    }


    ull rez = 0;
    for (const string& x : target) {
        rez += countWays(x, comp);
    }

    cout << rez << endl;
    //for (string x : comp) cout <<"c "<< x <<endl;
    //for (string x : target) cout << x <<endl;
    return 0;
}
