#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Directions for moving up, down, left, and right
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // Queue for BFS: stores {x, y, remaining_health}
        queue<tuple<int, int, int>> q;
        q.push({0, 0, health - grid[0][0]});  // Start with initial health minus the health cost of the first cell
        
        // Visited matrix to store the maximum health left at each cell
        vector<vector<int>> visited(m, vector<int>(n, -1));
        visited[0][0] = health - grid[0][0];
        
        // BFS traversal
        while (!q.empty()) {
            auto [x, y, remaining_health] = q.front();
            q.pop();
            
            // If we've reached the bottom-right corner with health >= 1
            if (x == m - 1 && y == n - 1 && remaining_health >= 1) {
                return true;
            }
            
            // Explore all 4 possible directions
            for (auto [dx, dy] : directions) {
                int new_x = x + dx;
                int new_y = y + dy;
                
                // Check if the new position is within bounds
                if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n) {
                    int new_health = remaining_health - grid[new_x][new_y];
                    
                    // Only proceed if the new health is positive and better than previous at this cell
                    if (new_health > 0 && new_health > visited[new_x][new_y]) {
                        visited[new_x][new_y] = new_health;
                        q.push({new_x, new_y, new_health});
                    }
                }
            }
        }
        
        // If we exhaust the queue without reaching the bottom-right corner
        return false;
    }
};