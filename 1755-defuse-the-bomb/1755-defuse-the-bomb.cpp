class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if(k==0)
            return vector<int>(code.size());
        vector<int> circular;
        for(int i=0; i<code.size(); i++)
            circular.push_back(code[i]);
        for(int i=0; i<code.size(); i++)
            circular.push_back(code[i]);
        vector<int> ans(code.size());
        if(k>0)
        {
            for(int i=0; i<code.size(); i++)
            {
                int sum=0;
                for(int j=i+1; j<=i+k; j++)
                    sum+=circular[j];
                ans[i]=sum;
            }
        }
        else if(k<0)
        {
            for(int i=code.size(); i<2*code.size(); i++)
            {
                int sum=0;
                for(int j=i-1; j>=i+k; j--)
                    sum+=circular[j];
                ans[i-code.size()]=sum;
            }
        }
        return ans;
    }
};