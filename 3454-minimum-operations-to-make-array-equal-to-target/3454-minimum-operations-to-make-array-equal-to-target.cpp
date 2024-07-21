class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        
        int n = nums.size();
        vector<long long> diff(n);
        for (int i = 0; i < n; ++i)
            diff[i] = (long long)(target[i] - nums[i]);
        long long res = abs(diff[0]);
        for(int i=1;i<n;++i)
        {
            if(diff[i]!=diff[i-1])
            {
                if((long long)diff[i]*diff[i-1]>0)
                {
                    if(abs(diff[i])>abs(diff[i-1]))
                        res+=(long long)abs(diff[i]-diff[i-1]);
                }
                else
                    res+=abs(diff[i]);
            }
        }
        return res;
    }
};