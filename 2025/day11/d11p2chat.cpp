#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

struct State {
    int node;
    bool fft;
    bool dac;

    bool operator==(State const& o) const {
        return node == o.node && fft == o.fft && dac == o.dac;
    }
};

struct StateHash {
    size_t operator()(State const& s) const noexcept {
        // 64-bit hash combine
        uint64_t h = s.node;
        h = (h << 1) ^ (s.fft ? 0x9e3779b97f4a7c15ULL : 0);
        h = (h << 1) ^ (s.dac ? 0x6a09e667f3bcc909ULL : 0);
        return (size_t)h;
    }
};

vector<vector<int>> adj;  // compressed graph
unordered_map<string,int> id; 
vector<string> names;

int get_id(const string &s) {
    auto it = id.find(s);
    if (it != id.end()) return it->second;
    int x = names.size();
    id[s] = x;
    names.push_back(s);
    adj.push_back({});
    return x;
}

unordered_map<State,long long,StateHash> memo;
unordered_set<int> visiting;  // for cycle detection

long long dfs(int node, bool seen_fft, bool seen_dac,
              int id_fft, int id_dac, int id_out)
{
    if (node == id_fft) seen_fft = true;
    if (node == id_dac) seen_dac = true;

    // If we reached 'out'
    if (node == id_out) {
        return (seen_fft && seen_dac) ? 1 : 0;
    }

    State st{node, seen_fft, seen_dac};
    if (memo.count(st)) return memo[st];

    // Detect cycles in same DFS path
    if (visiting.count(node)) return 0;
    visiting.insert(node);

    long long total = 0;
    for (int nxt : adj[node]) {
        total += dfs(nxt, seen_fft, seen_dac, id_fft, id_dac, id_out);
    }

    visiting.erase(node);
    memo[st] = total;
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("input");
    if (!file) {
        cerr << "Could not open input\n";
        return 1;
    }

    string line;
    auto trim = [&](string &s){
        size_t a = s.find_first_not_of(" \t\r\n");
        size_t b = s.find_last_not_of(" \t\r\n");
        if (a == string::npos) { s.clear(); return; }
        s = s.substr(a, b - a + 1);
    };

    // Read graph
    while (getline(file, line)) {
        if (line.empty()) continue;
        size_t colon = line.find(':');
        if (colon == string::npos) continue;

        string parent = line.substr(0, colon);
        trim(parent);
        if (parent.empty()) continue;

        int pid = get_id(parent);

        string rest = line.substr(colon + 1);
        stringstream ss(rest);
        string child;
        while (ss >> child) {
            trim(child);
            if (!child.empty()) {
                int cid = get_id(child);
                adj[pid].push_back(cid);
            }
        }
    }

    int id_svr = get_id("svr");
    int id_fft = get_id("fft");
    int id_dac = get_id("dac");
    int id_out = get_id("out");

    long long result = dfs(id_svr, false, false, id_fft, id_dac, id_out);

    cout << "Number of paths from svr → out through BOTH fft and dac = "
         << result << "\n";
}
