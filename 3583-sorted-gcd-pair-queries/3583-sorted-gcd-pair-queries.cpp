class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n=nums.size(), max_num=0;
        for(auto num:nums)
            max_num = max(max_num, num);
        vector<int> freq(max_num+1);
        for(auto num:nums)
            freq[num]++;
        vector<long long> cnt(max_num+1);
        for(int x=1;x<=max_num;x++)
        {
            for(int m=x;m<=max_num;m+=x)
                cnt[x]+=freq[m];
        }
        vector<long long> f(max_num+1);
        for(int x=max_num;x>=1;x--)
        {
            f[x]=cnt[x]*(cnt[x]-1)/2;
            for(int m=2*x;m<=max_num;m+=x)
                f[x]-=f[m];
        }
        vector<int> gcd_values;
        vector<long long> frequencies;
        for(int x=1;x<=max_num;x++)
        {
            if(f[x])
            {
                gcd_values.push_back(x);
                frequencies.push_back(f[x]);
            }
        }
        vector<long long> cum_freq(frequencies.size());
        cum_freq[0] = frequencies[0];
        for(int i=1;i<frequencies.size();i++)
            cum_freq[i] = cum_freq[i-1] + frequencies[i];
        long long total_pairs = (long long)n*(n-1)/2;
        vector<int> ans;
        for(auto q:queries)
        {
            if(q>=total_pairs)
            {
                ans.push_back(-1);
                continue;
            }
            int left = 0, right = cum_freq.size() - 1;
            while(left<=right)
            {
                int mid = left + (right-left)/2;
                if(cum_freq[mid] > q)
                    right=mid-1;
                else
                    left=mid+1;
            }
            ans.push_back(gcd_values[left]);
        }
        return ans;
    }
};
