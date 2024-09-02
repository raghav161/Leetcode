class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        vector<long long> pre(chalk.size());
        pre[0]=chalk[0];
        for(int i=1;i<pre.size();i++)
            pre[i]=(long long)chalk[i]+pre[i-1];
        long long sum=accumulate(chalk.begin(), chalk.end(), 0LL);
        k=k%sum;
        for(int i=0;i<chalk.size();i++)
        {
            if(k<pre[i])
                return i;
        }
        return 0;
    }
};