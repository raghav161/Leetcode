class Solution {
public:
    int passThePillow(int n, int time) {
        if(n==2 && time==2)
            return 1;
        if(n==2)
        {
            int x=time%2;
            if(x==1)
                return 2;
            return 1;
        }
        if(n<=time)
        {
            int x=time%(n-1);
            int y=time/(n-1);
            if(y%2==0)
                return x+1;
            return n-x;
        }
        return time+1;
    }
};