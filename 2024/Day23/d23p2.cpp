#include <bits/stdc++.h>
using namespace std;

static const int BIG_N = 700;

struct pc {
    string name;                       // 2 chars
    vector<string> links;              // each link is 2 chars
};

int n = 0;

// link[a1][a2][b1][b2] == true if connected
bool link_map[26][26][26][26] = {false};

void check_lan(string& linked,
               const vector<string>& links,
               int idx,
               int pcn)
{
    if (idx == pcn) return;

    bool good = true;

    for (size_t i = 0; i + 1 < linked.size(); i += 3) {
        int a1 = linked[i]   - 'a';
        int a2 = linked[i+1] - 'a';
        int b1 = links[idx][0] - 'a';
        int b2 = links[idx][1] - 'a';

        if (!link_map[a1][a2][b1][b2]) {
            good = false;
            break;
        }
    }

    string next = linked;
    if (good) {
        next += ",";
        next += links[idx];
    }

    check_lan(next, links, idx + 1, pcn);
    linked = next;
}

int main(int argc, char* argv[]) {
    string filename = (argc > 1) ? argv[1] : "input";
    ifstream file(filename);
    if (!file) {
        cerr << "Could not open file\n";
        return 1;
    }

    vector<pc> pcs(BIG_N);

    char a1, a2, b1, b2;
    while (file >> a1 >> a2) {
        file.ignore(1); // '-'
        file >> b1 >> b2;

        link_map[a1-'a'][a2-'a'][b1-'a'][b2-'a'] = true;
        link_map[b1-'a'][b2-'a'][a1-'a'][a2-'a'] = true;

        pc* p = nullptr;
        for (int i = 0; i < n; i++) {
            if (pcs[i].name == string({a1,a2})) {
                p = &pcs[i];
                break;
            }
        }
        if (!p) {
            pcs[n].name = string({a1,a2});
            p = &pcs[n++];
        }
        p->links.push_back(string({b1,b2}));

        p = nullptr;
        for (int i = 0; i < n; i++) {
            if (pcs[i].name == string({b1,b2})) {
                p = &pcs[i];
                break;
            }
        }
        if (!p) {
            pcs[n].name = string({b1,b2});
            p = &pcs[n++];
        }
        p->links.push_back(string({a1,a2}));
    }

    string result;
    int max_len = 0;

    for (int i = 0; i < n; i++) {
        string linked = pcs[i].name;
        check_lan(linked, pcs[i].links, 0, pcs[i].links.size());

        if ((int)linked.size() > max_len) {
            result = linked;
            max_len = linked.size();
        }
    }

    // Replace commas with null separators temporarily
    vector<string> names;
    for (size_t i = 0; i + 1 < result.size(); i += 3)
        names.push_back(result.substr(i, 2));

    sort(names.begin(), names.end());

    for (size_t i = 0; i < names.size(); i++) {
        cout << names[i];
        if (i + 1 < names.size()) cout << ",";
    }
    cout << "\n";

    return 0;
}
