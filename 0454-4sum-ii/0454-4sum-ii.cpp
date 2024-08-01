class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans=0;
        unordered_map<int, int> mp; 
        for(auto x: nums1)
        {
            for(auto y: nums2) 
                mp[x+y]++;
        }
        for(auto x:nums3)
        {
            for(auto y:nums4)
            {
                int target = -(x+y);
                if(mp.find(target) != mp.end()) 
                    ans+=mp[target];
            }
        }
        return ans;
    }
};

//tc: o(n^2). 