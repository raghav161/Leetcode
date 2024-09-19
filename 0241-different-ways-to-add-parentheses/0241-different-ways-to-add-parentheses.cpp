class Solution {
  public:
    vector<int> func(int i, int j, vector<vector<vector<int>>>& dp, string expression) {
        if(dp[i][j].size())
            return dp[i][j];
        int len = j-i+1;
        if(len <= 2)
            return dp[i][j] = {stoi(expression.substr(i, len))};
        vector<int> res;
        for(int ind=i;ind<=j;ind++)
        {
            char op = expression[ind];
            if(op == '+' || op == '-' || op == '*')
            {
                vector<int> left = func(i, ind - 1, dp, expression);
                vector<int> right = func(ind + 1, j, dp, expression);
                for(int l : left)
                {
                    for(int r : right)
                    {
                        if(op == '+')
                            res.push_back(l + r);
                        else if(op == '-')
                            res.push_back(l - r);
                        else if(op == '*')
                            res.push_back(l * r);
                    }
                }
            }
        }
        return dp[i][j] = res;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<vector<vector<int>>> dp(expression.size(), vector<vector<int>>(expression.size()));
        return func(0, expression.size()-1, dp, expression);
    }
};