class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sing=0, doub=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=9)
                sing+=nums[i];
            else if(nums[i]>9)
                doub+=nums[i];
        }
        if(sing==doub)
            return 0;
        return 1;
    }
};