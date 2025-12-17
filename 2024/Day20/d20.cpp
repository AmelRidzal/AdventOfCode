#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
#include <unordered_set>
#include <algorithm>

using namespace std;

typedef long long int ull;

void goingUp   (vector<vector<ull>>&, ull, ull, ull, vector<pair<ull,ull>>&);
void goingDown (vector<vector<ull>>&, ull, ull, ull, vector<pair<ull,ull>>&);
void goingLeft (vector<vector<ull>>&, ull, ull, ull, vector<pair<ull,ull>>&);
void goingRight(vector<vector<ull>>&, ull, ull, ull, vector<pair<ull,ull>>&);
ull countUniqueSquares();

ull posEX, posEY;
ull bestScore = numeric_limits<ull>::max();
vector<vector<pair<ull,ull>>> paths;

int main() {

    ifstream file("input");
    if (!file) {
        cerr << "Could not open file!\n";
        return 1;
    }

    vector<vector<ull>> grid;
    string line;
    ull posX = 0, posY = 0;

    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        vector<ull> row;
        char x;
        while (ss >> x) {
            if (x == 'S') {
                posX = grid.size();
                posY = row.size();
                row.push_back(numeric_limits<ull>::max());
            }
            else if (x == '#') {
                row.push_back(-1);
            }
            else if (x == 'E') {
                posEX = grid.size();
                posEY = row.size();
                row.push_back(numeric_limits<ull>::max());
            }
            else {
                row.push_back(numeric_limits<ull>::max());
            }
        }
        grid.push_back(row);
    }

    grid[posX][posY] = 0;

    vector<pair<ull,ull>> path;
    path.push_back({posX, posY});

    if (grid[posX-1][posY] != -1)
        goingUp(grid, posX-1, posY, 1, path);
    if (grid[posX+1][posY] != -1)
        goingDown(grid, posX+1, posY, 1, path);
    if (grid[posX][posY-1] != -1)
        goingLeft(grid, posX, posY-1, 1, path);
    if (grid[posX][posY+1] != -1)
        goingRight(grid, posX, posY+1, 1, path);


    vector<ull> rez;
    auto p=paths.at(0);
    for(int i=0;i<p.size();i++){
        for(int j=i+3;j<p.size();j++){
            if(p[i].first==p[j].first && abs(p[i].second-p[j].second)==2){
                rez.push_back(j-i-2);
            }else if(p[i].second==p[j].second && abs(p[i].first-p[j].first)==2){
                rez.push_back(j-i-2);
            }
        }
    }

    
    sort(rez.begin(),rez.end());
    auto temp=rez[0];
    int count=0;
    ull actualRez=0;
    for(auto x:rez){
        if(x==temp){
            count++;
        }else{
            if(temp>=100)actualRez+=count;
            //cout<<temp<<" "<<count<<endl;
            count=1;
            temp=x;
        }
    }
    if(temp>=100)actualRez+=count;
    //cout<<rez[rez.size()-1]<<" "<<count<<endl;

    cout << "Best score: " << bestScore << endl;
    cout << "Over 100ps: " << actualRez << endl;


    return 0;
}


void goingUp(vector<vector<ull>>& grid, ull posX, ull posY,
             ull score, vector<pair<ull,ull>>& path)
{
    path.push_back({posX, posY});

    if (posX == posEX && posY == posEY) {
        if (score < bestScore) {
            bestScore = score;
            paths.clear();
            paths.push_back(path);
        }
        else if (score == bestScore) {
            paths.push_back(path);
        }
        path.pop_back();
        return;
    }

    if (score >= bestScore) {
        path.pop_back();
        return;
    }

    grid[posX][posY] = score;
    score++;

    if (grid[posX-1][posY] != -1 && grid[posX-1][posY] >= score)
        goingUp(grid, posX-1, posY, score, path);

    if (grid[posX][posY+1] != -1 && grid[posX][posY+1] >= score)
        goingRight(grid, posX, posY+1, score, path);

    if (grid[posX][posY-1] != -1 && grid[posX][posY-1] >= score)
        goingLeft(grid, posX, posY-1, score, path);

    path.pop_back();
}

void goingDown(vector<vector<ull>>& grid, ull posX, ull posY,
               ull score, vector<pair<ull,ull>>& path)
{
    path.push_back({posX, posY});

    if (posX == posEX && posY == posEY) {
        if (score < bestScore) {
            bestScore = score;
            paths.clear();
            paths.push_back(path);
        }
        else if (score == bestScore) {
            paths.push_back(path);
        }
        path.pop_back();
        return;
    }

    if (score >= bestScore) {
        path.pop_back();
        return;
    }

    grid[posX][posY] = score;
    score++;

    if (grid[posX+1][posY] != -1 && grid[posX+1][posY] >= score)
        goingDown(grid, posX+1, posY, score, path);

    if (grid[posX][posY+1] != -1 && grid[posX][posY+1] >= score)
        goingRight(grid, posX, posY+1, score, path);

    if (grid[posX][posY-1] != -1 && grid[posX][posY-1] >= score)
        goingLeft(grid, posX, posY-1, score, path);

    path.pop_back();
}

void goingRight(vector<vector<ull>>& grid, ull posX, ull posY,
                ull score, vector<pair<ull,ull>>& path)
{
    path.push_back({posX, posY});

    if (posX == posEX && posY == posEY) {
        if (score < bestScore) {
            bestScore = score;
            paths.clear();
            paths.push_back(path);
        }
        else if (score == bestScore) {
            paths.push_back(path);
        }
        path.pop_back();
        return;
    }

    if (score >= bestScore) {
        path.pop_back();
        return;
    }

    grid[posX][posY] = score;
    score++;

    if (grid[posX][posY+1] != -1 && grid[posX][posY+1] >= score)
        goingRight(grid, posX, posY+1, score, path);

    if (grid[posX+1][posY] != -1 && grid[posX+1][posY] >= score)
        goingDown(grid, posX+1, posY, score, path);

    if (grid[posX-1][posY] != -1 && grid[posX-1][posY] >= score)
        goingUp(grid, posX-1, posY, score, path);

    path.pop_back();
}

void goingLeft(vector<vector<ull>>& grid, ull posX, ull posY,
               ull score, vector<pair<ull,ull>>& path)
{
    path.push_back({posX, posY});

    if (posX == posEX && posY == posEY) {
        if (score < bestScore) {
            bestScore = score;
            paths.clear();
            paths.push_back(path);
        }
        else if (score == bestScore) {
            paths.push_back(path);
        }
        path.pop_back();
        return;
    }

    if (score >= bestScore) {
        path.pop_back();
        return;
    }

    grid[posX][posY] = score;
    score++;

    if (grid[posX][posY-1] != -1 && grid[posX][posY-1] >= score)
        goingLeft(grid, posX, posY-1, score, path);

    if (grid[posX+1][posY] != -1 && grid[posX+1][posY] >= score)
        goingDown(grid, posX+1, posY, score, path);

    if (grid[posX-1][posY] != -1 && grid[posX-1][posY] >= score)
        goingUp(grid, posX-1, posY, score, path);

    path.pop_back();
}



