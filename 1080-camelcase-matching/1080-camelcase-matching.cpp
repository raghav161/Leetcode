class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string t) {
        vector<bool> ans;
        for(int i=0;i<queries.size();i++)
        {
            int j=0, flag=1;
            for(auto c:queries[i])
            {
                if(c >= 'A' && c <= 'Z' && c != t[j]) 
                {
                    flag=0;
                    break;
                }
                if(c==t[j])
                    j++;
            }
            ans.push_back(flag and j==t.size());
        }
        return ans;
    }
};