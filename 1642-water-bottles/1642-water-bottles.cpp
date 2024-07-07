class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum=numBottles;
        int count=0;
        while(numBottles>=numExchange && numExchange)
        {   
            if((numBottles + count)<numExchange)
                break;
            int x=numBottles/numExchange;
            sum+=x;
            count=numBottles%numExchange;
            numBottles=x+count;
        }
        return sum;
    }
};