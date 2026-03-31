#include <iostream>
#include <set>
#include <tuple>
using namespace std;

int grid[10][10];
int score = 0;

// Directions: 0=Up, 1=Right, 2=Down, 3=Left
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// Returns the relative direction: 0=Right, 1=Straight, 2=Left, 3=Back
int getRelativeDir(int currentDir, int newDir) {
    int diff = (newDir - currentDir + 4) % 4;
    return diff;
}

bool isValid(int x, int y) {
    return x >= 0 && x < 10 && y >= 0 && y < 10 && grid[x][y] != 0;
}

int main() {
    int startX = -1, startY = -1;

    // Read the grid
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 4) {
                startX = i;
                startY = j;
                grid[i][j] = 1; // Treat starting position as empty
            }
        }
    }

    int x = startX, y = startY;
    int dir = 0; // Start moving up

    // Track visited states: (x, y, direction)
    set<tuple<int, int, int>> visited;

    while (true) {
        // Check for infinite loop
        if (visited.count({x, y, dir})) {
            cout << "Silly Pacman" << endl;
            return 0;
        }
        visited.insert({x, y, dir});

        // Try to find next valid move using right-hand rule
        // Priority: Right > Straight > Left > Back
        int priorities[] = {0, 1, 2, 3}; // Right, Straight, Left, Back
        int nextDir = -1;
        int nextX = -1, nextY = -1;

        for (int p : priorities) {
            int tryDir = (dir + 4 - p + 4) % 4; // Convert relative to absolute
            // Right: dir-1, Straight: dir, Left: dir+1, Back: dir+2
            if (p == 0) tryDir = (dir + 1) % 4; // Right
            else if (p == 1) tryDir = dir; // Straight
            else if (p == 2) tryDir = (dir + 3) % 4; // Left (dir-1)
            else tryDir = (dir + 2) % 4; // Back

            int tx = x + dx[tryDir];
            int ty = y + dy[tryDir];

            if (isValid(tx, ty)) {
                nextDir = tryDir;
                nextX = tx;
                nextY = ty;
                break;
            }
        }

        // If no valid move found, we're stuck
        if (nextDir == -1) {
            break;
        }

        // Move to next position
        x = nextX;
        y = nextY;
        dir = nextDir;

        // Check what's at this position
        if (grid[x][y] == 3) {
            // Hit a ghost
            score -= 500;
            break;
        } else if (grid[x][y] == 2) {
            // Eat a bean
            score += 2;
            grid[x][y] = 1; // Bean is eaten
        }
    }

    cout << score << endl;
    return 0;
}
