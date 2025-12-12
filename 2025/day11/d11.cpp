#include <bits/stdc++.h>
#include <chrono>
using namespace std;

map<tuple<string, bool, bool>, long long> memo;

long long dfs(map<string, vector<string>> &adj, string curr, bool fft, bool dac) {
    if (curr == "out") {
        return (fft && dac) ? 1 : 0;
    }
    long long ans = 0;

    if (memo.find(tuple(curr, fft, dac)) != memo.end()) {
        return memo[make_tuple(curr, fft, dac)];
    }

    for (string &child : adj[curr]) {
        if (child == "fft")
            ans += dfs(adj, child, true, dac);
        else if (child == "dac")
            ans += dfs(adj, child, fft, true);
        else 
            ans += dfs(adj, child, fft, dac);
    }
    return memo[make_tuple(curr, fft, dac)] = ans;
}

int main() {
    //auto start = chrono::high_resolution_clock::now();
    map<string, vector<string>> adj;
    ifstream inputFile("input");
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string word;
        vector<string> v;
        while (ss >> word) {
            v.push_back(word);
        }

        for (int i = 1; i < v.size(); i++) {
            adj[v[0].substr(0, v[0].size() - 1)].push_back(v[i]);
        }
    }
    cout << dfs(adj, "svr", false, false) << endl;
    //auto end = chrono::high_resolution_clock::now();
    //chrono::duration<double> elapsed = end - start;
    //cout << "Time taken: " <<elapsed.count() << " seconds\n";
}