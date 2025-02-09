class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (target > x + y)
            return 0;
        int limit = x + y + 1;
        vector<int> vis(limit), dir = {-x, x, -y, y};
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            if (top == target)
                return 1;
            for (int i = 0; i < 4; i++) {
                int newNode = top + dir[i];
                if (newNode >= 0 && newNode < limit && vis[newNode]==0) {
                    q.push(newNode);
                    vis[newNode] = 1;
                }
            }
        }
        return 0;
    }
};