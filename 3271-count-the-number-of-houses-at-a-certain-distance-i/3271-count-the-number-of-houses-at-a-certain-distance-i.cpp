class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> ans(n);
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int a = abs(i-j);
                int b = abs(i-x)+abs(y-j)+1;
                int c = abs(i-y)+abs(x-j)+1;
                int mini = min({a, b, c});
                ans[mini-1]+=2;
            }
        }
        return ans;
    }
};