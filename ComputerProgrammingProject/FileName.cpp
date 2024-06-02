#include <iostream>
#include <vector>
using namespace std;

const int N = 10;  // Assuming a 10x10 maze as per the problem statement

// Directions for moving in the maze (right, down, left, up)
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

bool isSafe(int x, int y, const vector<vector<int>>& maze, vector<vector<bool>>& visited) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0 && !visited[x][y]);
}

bool dfs(int x, int y, const vector<vector<int>>& maze, vector<vector<bool>>& visited, vector<pair<int, int>>& path) {
    // If we've reached the exit
    if (x == N - 1 && y == N - 1) {
        path.push_back({ x, y });
        return true;
    }

    // Mark the current cell as visited and add it to the path
    visited[x][y] = true;
    path.push_back({ x, y });

    // Explore the four possible directions
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isSafe(nx, ny, maze, visited)) {
            if (dfs(nx, ny, maze, visited, path)) {
                return true;
            }
        }
    }

    // If none of the moves work out, backtrack
    path.pop_back();
    visited[x][y] = false;
    return false;
}

void solveMaze(const vector<vector<int>>& maze) {
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<pair<int, int>> path;

    if (dfs(0, 0, maze, visited, path)) {
        cout << "Output Path\nx y\n";
        for (const auto& p : path) {
            cout << p.first << " " << p.second << endl;
        }
    }
    else {
        cout << "No path found." << endl;
    }
}

int main() {
    vector<vector<int>> maze = {
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 1, 1, 1, 1},
        {1, 0, 0, 1, 1, 0, 0, 0, 1, 1},
        {1, 1, 0, 1, 1, 0, 0, 1, 1, 1},
        {1, 1, 0, 0, 1, 1, 0, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 0}
    };

    solveMaze(maze);

    return 0;
}
