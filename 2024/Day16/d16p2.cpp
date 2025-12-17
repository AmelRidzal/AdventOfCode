#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
#include <unordered_set>

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

    // First, set the entire grid to 0
    for (auto& row : grid) {
        for (auto& x : row) {
            if (x != -1) // keep walls as -1
                x = 0;
        }
    }

    // Then, mark all squares used in any best path as 1
    for (const auto& path : paths) {
        for (const auto& p : path) {
            ull x = p.first;
            ull y = p.second;
            grid[x][y] = 1;
        }
    }

    // Print the grid
    for (const auto& row : grid) {
        for (ull x : row) {
            if (x == -1) cout << "# ";  // optional: show walls
            else cout << x << " ";
        }
        cout << "\n";
    }


    cout << "Best score: " << bestScore << endl;
    cout << "Number of best paths: " << paths.size() << endl;

    ull uniqueCount = countUniqueSquares();
    cout << "Unique squares used in any best path: " << uniqueCount << endl;

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



// Function to count unique squares across all best paths
ull countUniqueSquares() {
    unordered_set<ull> uniqueSquares;

    for (const auto& path : paths) {
        for (const auto& p : path) {
            // Encode (x, y) into a single number
            // Assuming grid size < 1e6, this avoids collisions
            ull key = p.first * 1000000 + p.second;
            uniqueSquares.insert(key);
        }
    }

    return uniqueSquares.size();
}
