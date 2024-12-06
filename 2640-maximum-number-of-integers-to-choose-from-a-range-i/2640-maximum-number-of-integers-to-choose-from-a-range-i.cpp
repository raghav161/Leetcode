class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxsum) {
        set<int> s;
        for(int i=0;i<banned.size();i++)
            s.insert(banned[i]);
        vector<int> ans;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            int x=sum;
            x+=i;
            if(s.find(i)==s.end() && x<=maxsum)
            {
                ans.push_back(i);
                sum+=i;
            }
        }
        return ans.size();
    }
};