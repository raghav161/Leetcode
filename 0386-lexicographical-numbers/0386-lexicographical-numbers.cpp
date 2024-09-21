class Solution {
public:
    void f(int target, int n, vector<int>& ans)
    {
        if(target>n)
            return;
        ans.push_back(target);
        f(target*10, n, ans);
        if(target%10 != 9)
            f(target+1, n, ans);
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        f(1, n, ans);
        return ans;
    }  
};