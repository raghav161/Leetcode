class Solution {
public:
    int minSteps(int n) {
        if(n==1) 
            return 0;
        int ans=0, i=2;
        while(n>1)
        {
            while(n%i==0) 
            {
                ans+=i;
                n/=i;
            }
            i++;
        }
        return ans;
    }
};