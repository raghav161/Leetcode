class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxsum) {
        set<int> s(banned.begin(), banned.end());
        int sum=0, count=0;
        for(int i=1;i<=n;i++)
        {
            int x=sum;
            x+=i;
            if(s.find(i)==s.end() && x<=maxsum)
            {
                count++;
                sum+=i;
            }
        }
        return count;
    }
};