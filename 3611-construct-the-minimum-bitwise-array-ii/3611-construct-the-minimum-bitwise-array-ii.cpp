class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
                ans.push_back(-1);
            else
            {
                int x=nums[i];
                int count=0;
                while(1)
                {
                    x=x/2;
                    count++;
                    if(x%2==0)
                        break;
                }
                ans.push_back(nums[i]-pow(2, count-1));
            }
        }
        return ans;
    }
};