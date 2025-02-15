class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i-k >= 0 and i+k < nums.size() and nums[i] > nums[i-k] and nums[i] > nums[i+k])
                sum += nums[i];
            else if(i-k < 0 and i+k >= nums.size())
                sum += nums[i];
            else if(i-k < 0 and i+k < nums.size() and nums[i] > nums[i+k])
                sum += nums[i];
            else if(i-k >= 0 and i+k >= nums.size() and nums[i] > nums[i-k])
                sum += nums[i];
        }
        return sum;
    }
};