class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start="", dest="123450";
        vector<vector<int>> direc={{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
                start+=to_string(board[i][j]);
        }
        unordered_set<string> vis;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> q;
        vis.insert(start);
        q.push({0, start});
        while(!q.empty())
        {
            auto p=q.top(); 
            q.pop();
            string curr=p.second;
            int ans=p.first, idx=curr.find("0");
            if(curr==dest)
                return ans;
            for(auto& i:direc[idx])
            {
                string temp=curr;
                swap(temp[idx], temp[i]);
                if(vis.count(temp)==0)
                {
                    vis.insert(temp);
                    q.push({ans+1, temp});
                }
            }
        }
        return -1;
    }
};