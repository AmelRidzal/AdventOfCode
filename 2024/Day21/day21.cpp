#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;



typedef unsigned long long int ull;
void findCords(vector<vector<char>>& ,ull& ,ull& ,char );
void makeInputs(vector<vector<char>>& , vector<vector<char>>&, vector<vector<char>>& , ull , ull );

int main(){

ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<vector<char>> target;   
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;  

        stringstream ss(line);
        vector<char> row;
        char x;
        while (ss >> x) {
            row.push_back(x);
        }

        target.push_back(row);
    }

    
    /*for (const auto& row : target) {
        for (char x : row) cout << x << " ";
        cout << "\n";
    }*/

    vector<vector<char>> numpad;
    vector<char> numrow;   
    numrow.push_back('7'); 
    numrow.push_back('8'); 
    numrow.push_back('9');
    numpad.push_back(numrow);
    numrow.clear();
    numrow.push_back('4'); 
    numrow.push_back('5'); 
    numrow.push_back('6');
    numpad.push_back(numrow);
    numrow.clear();
    numrow.push_back('1'); 
    numrow.push_back('2'); 
    numrow.push_back('3');
    numpad.push_back(numrow);
    numrow.clear();
    numrow.push_back(' '); 
    numrow.push_back('0'); 
    numrow.push_back('A');
    numpad.push_back(numrow);
    numrow.clear();

    /*for (const auto& row : numpad) {
        for (char x : row) cout << x << " ";
        cout << "\n";
    }*/

    vector<vector<char>> target2;
    makeInputs(target, numpad, target2, 3, 2);
    for (char x : target2[0]) cout << x << " ";
    cout << "\n";

    numrow.clear();
    numpad.clear();
    numrow.push_back(' '); 
    numrow.push_back('^'); 
    numrow.push_back('A');
    numpad.push_back(numrow);
    numrow.clear();
    numrow.push_back('<'); 
    numrow.push_back('v'); 
    numrow.push_back('>');
    numpad.push_back(numrow);
    numrow.clear();

    vector<vector<char>> target3;
    //change for p2
    for(int i=0;i<2;i++){
    makeInputs(target2, numpad, target3, 0, 2);
        target2.clear();
        target2=target3;
        target3.clear();
    }

    for (const auto& row : target2) {
        cout<<row.size()<<endl;
        for (char x : row) cout << x << " ";
        cout << "\n";
    }
    ull rez=0;
    for(int i=0;i<target.size();i++){
        string s;
        for(int j=0;j<target[i].size()-1;j++){
            s+=target[i][j];
        }
        int si=stoi(s);
        rez+=si*target2[i].size();
    }

    cout<<rez<<endl;

    return 0;
}


void findCords(vector<vector<char>>& numpad,ull& xf,ull& yf,char c){
    for(int i=0;i<numpad.size();i++){
        for(int j=0;j<numpad[i].size();j++){
            if(numpad[i][j]==c){
                xf=i;
                yf=j;
                return;
            }
        }
    }
}

void makeInputs(vector<vector<char>>& input,vector<vector<char>>& grid,vector<vector<char>>& output,ull x, ull y) {
    vector<char> row;

    ull gap_i = 0, gap_j = 0;
    for (ull a = 0; a < grid.size(); a++)
        for (ull b = 0; b < grid[a].size(); b++)
            if (grid[a][b] == ' ') {
                gap_i = a;
                gap_j = b;
            }

    bool moving_numeral = (gap_i == 3 && gap_j == 0);

    for (ull i = 0; i < input.size(); i++) {
        row.clear();

        for (ull j = 0; j < input[i].size(); j++) {
            ull xf, yf;
            findCords(grid, xf, yf, input[i][j]);

            long di = (long)xf - (long)x;
            long dj = (long)yf - (long)y;

            bool already_processed = false;

            if (moving_numeral) {
                if (xf == gap_i && y == gap_j) { 
                    for (int c = 0; c < dj; c++) row.push_back('>');
                    for (int c = 0; c < di; c++) row.push_back('v');
                    already_processed = true;
                }
                else if (x == gap_i && yf == gap_j) { 
                    for (int c = 0; c < -di; c++) row.push_back('^');
                    for (int c = 0; c < -dj; c++) row.push_back('<');
                    already_processed = true;
                }
            } else {
                if (x == gap_i && yf == gap_j) { 
                    for (int c = 0; c < di; c++) row.push_back('v');
                    for (int c = 0; c < -dj; c++) row.push_back('<');
                    already_processed = true;
                }
                else if (xf == gap_i && y == gap_j) { 
                    for (int c = 0; c < dj; c++) row.push_back('>');
                    for (int c = 0; c < -di; c++) row.push_back('^');
                    already_processed = true;
                }
            }

            if (!already_processed) {
                bool going_right = dj > 0;
                bool going_up = di < 0;

                if (!going_right)
                    for (int c = 0; c < -dj; c++) row.push_back('<');

                if (!going_up)
                    for (int c = 0; c < di; c++) row.push_back('v');

                if (going_right)
                    for (int c = 0; c < dj; c++) row.push_back('>');

                if (going_up)
                    for (int c = 0; c < -di; c++) row.push_back('^');
            }

            row.push_back('A');
            x = xf;
            y = yf;
        }

        output.push_back(row);
    }
}
