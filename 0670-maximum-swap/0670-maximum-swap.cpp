class Solution {
public:
    int maximumSwap(int num) {
        string numstr=to_string(num);
        int maxidx=-1, maxdigit=-1, leftidx=-1, rightidx=-1;        
        for(int i=numstr.size()-1;i>=0;--i)
        {
            if(numstr[i]>maxdigit)
            {
                maxdigit = numstr[i];
                maxidx = i;
            }
            else if(numstr[i]<maxdigit)
            {
                leftidx = i;
                rightidx = maxidx;
            }
        }
        if(leftidx==-1)
            return num;
        swap(numstr[leftidx], numstr[rightidx]);
        return stoi(numstr);
    }

};