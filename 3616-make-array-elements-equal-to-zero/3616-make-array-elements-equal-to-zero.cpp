class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int cnt=0, lsum=0, rsum = accumulate(begin(nums), end(nums), 0);
        for(int i=0;i<n;i++) {
            if(nums[i]==0) {
                if(lsum==rsum)
                    cnt+=2;
                else if(abs(lsum-rsum)==1)
                    cnt+=1;
            }
            lsum+=nums[i];
            rsum-=nums[i];
        }
        return cnt;
    }
};