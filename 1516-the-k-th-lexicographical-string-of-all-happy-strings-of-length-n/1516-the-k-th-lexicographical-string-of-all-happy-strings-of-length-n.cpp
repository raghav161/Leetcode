class Solution {
public:
    void helper(vector<string>& ans, int n, int k, string& temp, vector<char>& inp)
    {
        if(ans.size()==k)
            return;
        if(temp.size()==n)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<3;i++)
        {
            if(temp.size()==0 or temp.back()!=inp[i])
            {
                temp.push_back(inp[i]);
                helper(ans,n,k,temp,inp);
                temp.pop_back();
            }
        }
        return;
    }
    string getHappyString(int n, int k)
    {
        string temp="";
        vector<char> inp={'a','b','c'};
        vector<string> ans;
        helper(ans, n, k, temp, inp);
        if(ans.size()==k)
            return ans.back();
        return "";
    }
};