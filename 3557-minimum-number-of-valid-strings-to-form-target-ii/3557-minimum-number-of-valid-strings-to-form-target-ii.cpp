class Solution {
public:
    vector<int> f(string pre)
    {
        vector<int> lps(pre.size());
        int i=1, j=0;
        while(i<pre.size())
        {
            if(pre[i]==pre[j])
            {
                j++;
                lps[i]=j;
                i++;
            }
            else
            {
                if(j)
                    j = lps[j-1];
                else
                    i++;
            }
        }
        return lps;
    }
    int minValidStrings(vector<string>& words, string target) {
        vector<vector<int>> vec;
        for(auto i:words)
            vec.push_back(f(i + "#" + target));
        int len=target.size(), ans=0;
        while(len>0)
        {
            int temp=0;
            for(int i=0;i<words.size();i++)
                temp=max(temp, vec[i][words[i].size()+len]);
            if(temp==0)
                return -1;
            ans++;
            len-=temp;
        }
        return ans;
    }
};