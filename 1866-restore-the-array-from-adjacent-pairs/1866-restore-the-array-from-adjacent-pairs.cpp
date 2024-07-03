class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& vals) {
        unordered_map<int, vector<int>> pairs;
        for(auto& val:vals) 
        {
            pairs[val[0]].push_back(val[1]);
            pairs[val[1]].push_back(val[0]);
        }
        vector<int> result;
        int curr = 0;
        for(auto& entry:pairs)
        {
            if(entry.second.size() == 1)
            {
                curr = entry.first;
                break;
            }
        }
        int left = curr;
        result.push_back(curr);
        for(int i=0;i<vals.size();i++) 
        {
            auto temp = pairs[curr];
            int newval = (temp[0] != left) ? temp[0] : temp[1];
            result.push_back(newval);
            left = curr;
            curr = newval;
        }
        return result;
    }
};