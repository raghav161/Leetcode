class Solution {
public:
    long long minEnd(int n, int x) {
        long long a = x;
        while(n>1)
        {
            a=(a+1) | x;
            n--;
        }
        return a;
    }
};