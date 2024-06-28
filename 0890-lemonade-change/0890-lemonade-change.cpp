class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count1=0, count2=0;
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)
                count1++;
            else if(bills[i]==10)
            {
                count2++;
                if(count1==0)
                    return false;
                count1--;
            }
            else if(bills[i]==20)
            {
                if((count2==0 && count1<=2) || (count2>=1 && count1==0))
                    return false;
                if(count2>=1 && count1>=1)
                {
                    count2--;
                    count1--;
                }
                else if(count2==0 && count1>=3)
                    count1=count1-3;
            }
        }
        return true;
    }
};