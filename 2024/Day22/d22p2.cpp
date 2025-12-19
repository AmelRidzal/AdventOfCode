#include <bits/stdc++.h>
using namespace std;

typedef long long ull;
ull next_secret(ull );

int main() {
ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<ull> row;
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  

        stringstream ss(line);
        ull x;
        ss>>x;
        row.push_back(x);
    }

    map<array<int,4>, ull> total;

    for (ull start : row) {
        vector<int> prices;
        vector<int> changes;
        ull secret = start;
        prices.push_back(secret % 10);

        for (int i = 0; i < 2000; i++) {
            secret = next_secret(secret);
            prices.push_back(secret % 10);
        }

        for (int i = 1; i < (int)prices.size(); i++) {
            changes.push_back(prices[i] - prices[i - 1]);
        }

        set<array<int,4>> used;
        for (int i = 0; i + 3 < (int)changes.size(); i++) {
            array<int,4> seq = {
                changes[i],
                changes[i + 1],
                changes[i + 2],
                changes[i + 3]
            };

            if (used.count(seq)) continue;
            used.insert(seq);
            int price_at_sale = prices[i + 4];
            total[seq] += price_at_sale;
        }
    }

    ull answer = 0;
    for (auto &[seq, bananas] : total) {
        answer = max(answer, bananas);
    }

    cout << answer << "\n";
}



ull next_secret(ull secret) {
    secret ^= (secret * 64);
    secret %= 16777216;

    secret ^= (secret / 32);
    secret %= 16777216;

    secret ^= (secret * 2048);
    secret %= 16777216;

    return secret;
}