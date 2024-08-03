#include <iostream>
#include <vector>
using namespace std;
//152120201054 Alperen Güneþ
const int N = 10;  // Assuming a 10x10 maze as per the problem statement, you can change the value as per your requirement

// Directions for moving in the maze (right, down, left, up), we use these to explore the maze.
//We define dx direction for x axis and dy direction for y axis
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

// Function to check if the given cell is safe to move
static bool isSafe(int x, int y, const vector<vector<int>>& maze, vector<vector<bool>>& visited) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0 && !visited[x][y]);
}

// Function to perform DFS to find the path from the start to the exit
static bool dfs(int x, int y, const vector<vector<int>>& maze, vector<vector<bool>>& visited, vector<pair<int, int>>& path) {
    // If we've reached the exit
    if (x == N - 1 && y == N - 1) {
        path.push_back({ x, y });
        return true;
    }

    // Mark the current cell as visited and add it to the path
    visited[x][y] = true;
    path.push_back({ x, y });

	// Explore the four possible directions, we can move in the maze (right, down, left, up) with the help of dx and dy arrays
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
		//Check if the next cell is safe to move
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
// Function to solve the maze, it calls the dfs function to find the path
static void solveMaze(const vector<vector<int>>& maze) {
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
// Main function
int main() {
	// Define the maze as a 2D grid
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
	// Call the function to solve the maze
    solveMaze(maze);
    return 0;
}
