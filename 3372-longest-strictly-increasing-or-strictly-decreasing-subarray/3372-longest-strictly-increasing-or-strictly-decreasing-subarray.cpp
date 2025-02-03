
class Solution {
public:
    int dec(vector<int>&a)
    {
        int maxi=1, cur=1, n=a.size();
        for(int i=1;i<n;i++)
        {
            if(a[i]<a[i-1])
                cur++;
            else 
            {
                maxi = max(maxi, cur);
                cur=1;
            }
        }
        return max(cur, maxi);
    }
    int inc(vector<int>&a)
    {
        int maxi = 1, cur = 1, n = a.size();
        for(int i=1;i<n;i++)
        {
            if(a[i]>a[i-1])
                cur++;
            else 
            {
                maxi = max(maxi, cur);
                cur = 1;
            }
        }
        return max(cur, maxi);
    }
    int longestMonotonicSubarray(vector<int>& nums) 
    {
        return max(inc(nums), dec(nums));
    }
};
