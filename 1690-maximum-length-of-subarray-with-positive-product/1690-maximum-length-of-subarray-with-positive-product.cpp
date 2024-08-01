class Solution {
public:
    int getMaxLen(vector<int>& nums)
    {
        int maxi=0, lastPos=0, lastNeg=-1, neg=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) 
                lastPos=i+1, lastNeg=-1, neg=0;
            else if(nums[i]<0)
            {
                if(lastNeg==-1) 
                    lastNeg=i;
                neg++;
            }
            else if(nums[i]>0 && neg%2) 
                maxi=max(maxi, i-lastNeg);
            if(neg%2==0) 
                maxi=max(maxi, i-lastPos+1);
        }
        return maxi;
    }
};