class Solution {
public:
    int countPrimes(int n) {
        int count=0;
        vector<bool> v(n+1, 1);
        v[0] = v[1] = 0;
        for(int i=2;i*i<=n;i++) 
        {
            if(v[i]) 
            {
                for(int j=i*i;j<=n;j+=i)
                    v[j]=0;
            }
        }
        for(int i=2; i<n; i++)
        {
            if(v[i]) 
                count++;
        }
        return count;
    }
};