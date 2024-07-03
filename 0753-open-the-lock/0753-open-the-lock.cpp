class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadendsSet(deadends.begin(), deadends.end()), visited;
        int result = 0;
        if(deadendsSet.find("0000") != deadendsSet.end())
            return -1;
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        visited.insert("0000");
        while(!q.empty())
        {
            string curr=q.front().first;
            int result=q.front().second;
            q.pop();
            if(curr==target)
                return result;
            for(int i=0;i<4;i++)
            {
                string down=curr, up=curr;
                char upCh = up[i], downCh = down[i];
                up[i] = (upCh == '9' ? '0' : upCh + 1);
                down[i] = (downCh == '0' ? '9' : downCh - 1);
                if (visited.find(up) == visited.end() && deadendsSet.find(up) == deadendsSet.end()) {
                    q.push({up, result+1});
                    visited.insert(up);
                }
                if (visited.find(down) == visited.end() && deadendsSet.find(down) == deadendsSet.end()) {
                    q.push({down, result+1});
                    visited.insert(down);
                }
            }
        }
        return -1;
    }
};