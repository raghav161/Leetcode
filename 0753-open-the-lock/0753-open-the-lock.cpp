class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        unordered_set<string> deadendsSet(deadends.begin(), deadends.end()), visited;
        int result = 0;
        if(deadendsSet.find("0000") != deadendsSet.end())
            return -1;
        queue<pair<string, int>> wheelQueue;
        wheelQueue.push({"0000", 0});
        visited.insert("0000");
        while(!wheelQueue.empty())
        {
            string up, down, currentWheel = wheelQueue.front().first;
            int result=wheelQueue.front().second;
            wheelQueue.pop();
            if (currentWheel == target)
                return result;
            for (int i = 0; i < 4; i++)
            {
                down = up = currentWheel;
                char upCh = up[i], downCh = down[i];
                up[i] = (upCh == '9' ? '0' : upCh + 1);
                down[i] = (downCh == '0' ? '9' : downCh - 1);
                if (visited.find(up) == visited.end() && deadendsSet.find(up) == deadendsSet.end()) {
                    wheelQueue.push({up, result+1});
                    visited.insert(up);
                }
                if (visited.find(down) == visited.end() && deadendsSet.find(down) == deadendsSet.end()) {
                    wheelQueue.push({down, result+1});
                    visited.insert(down);
                }
            }
        }
        return -1;
    }
};