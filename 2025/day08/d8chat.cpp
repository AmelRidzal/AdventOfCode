#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;

typedef long long ull;

// ----------------- Your distance function -----------------
ull findDistance(const vector<ull>& first, const vector<ull>& second){
    ull dx = first[0] - second[0];
    ull dy = first[1] - second[1];
    ull dz = first[2] - second[2];
    return dx*dx + dy*dy + dz*dz;
}

// ----------------- DSU STRUCT -----------------
struct DSU {
    vector<int> parent, sz;

    DSU(int n) : parent(n), sz(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }

    vector<int> getComponentSizes() {
        vector<int> count(parent.size(), 0);
        for (int i = 0; i < parent.size(); i++)
            count[find(i)]++;

        vector<int> result;
        for (int c : count)
            if (c > 0) result.push_back(c);

        return result;
    }
};

// -----------------------------------------------------------

int main() {

    ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<vector<ull>> grid;
    string line;

    // -------- Read coordinates from input --------
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        vector<ull> row(3);
        char c;

        ss >> row[0] >> c >> row[1] >> c >> row[2];
        grid.push_back(row);
    }

    int n = grid.size();
    if (n < 3) {
        cout << "Not enough points.\n";
        return 0;
    }

    // -------- Build lower-triangle distance matrix --------
    vector<vector<ull>> dgrid(n, vector<ull>(n, 0));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            dgrid[i][j] = findDistance(grid[i], grid[j]);
        }
    }

    // ------------------------------------------------------
    //      OPTIMIZED: FIND 1000 SMALLEST DISTANCES
    // ------------------------------------------------------

    // Max-heap for 1000 smallest distances
    auto cmp = [](const tuple<ull,int,int>& a, const tuple<ull,int,int>& b){
        return get<0>(a) < get<0>(b); // max-heap: largest dist on top
    };

    priority_queue<
        tuple<ull,int,int>,
        vector<tuple<ull,int,int>>,
        decltype(cmp)
    > heap(cmp);

    // Scan only lower half (i > j)
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            ull d = dgrid[i][j];

            if (heap.size() < 1000) {
                heap.push({d, i, j});
            }
            else if (d < get<0>(heap.top())) {
                heap.pop();
                heap.push({d, i, j});
            }
        }
    }

    // Extract edges
    vector<tuple<ull,int,int>> edges;
    while (!heap.empty()) {
        edges.push_back(heap.top());
        heap.pop();
    }

    // Sort those 1000 edges (ascending)
    sort(edges.begin(), edges.end(),
         [](auto &a, auto &b){ return get<0>(a) < get<0>(b); });

    // ------------------------------------------------------
    //                      DSU MERGING
    // ------------------------------------------------------

    DSU dsu(n);
    int used = 0;

    for (auto &e : edges) {
        if (used == 1000) break;

        auto [dist, a, b] = e;

        if (dsu.unite(a, b)) {
            used++;
        }
    }

    // ------------------------------------------------------
    //                     GET LOOP SIZES
    // ------------------------------------------------------

    vector<int> sizes = dsu.getComponentSizes();

    cout << "\nLoop sizes:\n";
    for (int s : sizes) cout << s << "\n";

    // ------------------------------------------------------
    //           MULTIPLY THE 3 LARGEST LOOPS
    // ------------------------------------------------------

    if (sizes.size() < 3) {
        cout << "\nNot enough loops to multiply 3 largest.\n";
        return 0;
    }

    sort(sizes.begin(), sizes.end(), greater<int>());
    long long result = 1LL * sizes[0] * sizes[1] * sizes[2];

    cout << "\nThree largest loops multiply to: " << result << "\n";

    return 0;
}


/*part 2
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <tuple>
#include <algorithm>
#include <numeric>
using namespace std;

typedef unsigned long long ull;

// ----------------- Your distance function -----------------
ull findDistance(const vector<ull>& first, const vector<ull>& second){
    // compute squared Euclidean distance
    long long dx = static_cast<long long>(first[0]) - static_cast<long long>(second[0]);
    long long dy = static_cast<long long>(first[1]) - static_cast<long long>(second[1]);
    long long dz = static_cast<long long>(first[2]) - static_cast<long long>(second[2]);
    return static_cast<ull>(dx*dx + dy*dy + dz*dz);
}

// ----------------- DSU STRUCT -----------------
struct DSU {
    vector<int> parent, sz;

    DSU(int n) : parent(n), sz(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

static void print_int128(__int128 v) {
    if (v == 0) { cout << "0"; return; }
    bool neg = v < 0;
    if (neg) v = -v;
    string s;
    while (v > 0) {
        int digit = static_cast<int>(v % 10);
        s.push_back('0' + digit);
        v /= 10;
    }
    if (neg) s.push_back('-');
    reverse(s.begin(), s.end());
    cout << s;
}

int main() {

    ifstream file("input");
    if (!file) {
        cerr << "Could not open file \"input\"!\n";
        return 1;
    }

    vector<vector<ull>> grid;
    string line;

    // -------- Read coordinates from input --------
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        vector<ull> row(3);
        char c;
        ss >> row[0] >> c >> row[1] >> c >> row[2];
        grid.push_back(row);
    }

    int n = grid.size();
    if (n < 2) {
        cout << "Not enough points.\n";
        return 0;
    }

    // Collect all edges (i > j) with distances
    vector<tuple<ull,int,int>> edges;
    edges.reserve(static_cast<size_t>(n) * (n-1) / 2);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            ull d = findDistance(grid[i], grid[j]);
            edges.emplace_back(d, i, j);
        }
    }

    // Sort ascending by distance
    sort(edges.begin(), edges.end(), [](const auto &a, const auto &b){
        return get<0>(a) < get<0>(b);
    });

    // Kruskal-style: unite until single component
    DSU dsu(n);
    int components = n;
    int last_a = -1, last_b = -1;
    ull last_dist = 0;

    for (const auto &e : edges) {
        ull d; int a, b;
        tie(d, a, b) = e;
        if (dsu.unite(a, b)) {
            components--;
            last_a = a;
            last_b = b;
            last_dist = d;
            if (components == 1) break; // fully connected
        }
    }

    if (components != 1) {
        cout << "Could not connect all components.\n";
        return 0;
    }

    cout << "Last connected pair: indices (" << last_a << ", " << last_b << "), distance = " << last_dist << "\n";
    cout << "X coordinates: " << grid[last_a][0] << " and " << grid[last_b][0] << "\n";

    __int128 product = static_cast<__int128>(grid[last_a][0]) * static_cast<__int128>(grid[last_b][0]);
    cout << "Product of their X coordinates: ";
    print_int128(product);
    cout << "\n";

    return 0;
}
*/

//WE WILL HAVE REDEMPTION