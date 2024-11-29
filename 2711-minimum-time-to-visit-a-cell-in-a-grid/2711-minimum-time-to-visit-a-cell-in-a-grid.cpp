class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) 
            return -1;
        int rows=grid.size(), cols=grid[0].size(), maxPos=rows*cols;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, 0});
        vector<bool> seen(maxPos); 
        seen[0]=true;
        int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!minHeap.empty()) {
            auto [currTime, pos] = minHeap.top();
            int currRow = pos/cols, currCol = pos % cols;
            minHeap.pop();
            if(currRow==rows-1 and currCol==cols-1) 
                return currTime;
            for(auto& move:moves) {
                int nextRow = move[0]+currRow, nextCol = move[1]+currCol, nextPos = nextRow*cols + nextCol; 
                if(nextRow >= 0 and nextCol >= 0 and nextRow < rows and nextCol < cols and !seen[nextPos]) {
                    int waitTime = ((grid[nextRow][nextCol]-currTime)%2==0);
                    int nextTime = max(currTime + 1, grid[nextRow][nextCol] + waitTime);
                    minHeap.push({nextTime, nextPos});
                    seen[nextPos] = true;
                }
            }
        }
        return -1;
    }
};