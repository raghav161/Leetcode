int dp[800][800][2];
const int MOD = 1e9 + 7;
class Solution {
    int rec(int i, bool flag, int ct, string &s, int &k) {
        if(i == s.size()) {
            if(flag) 
                return 0;
            int K = k - 1;
            int num = ct;
            while(K--)
                num = __builtin_popcount(num);
            return num==1;
        }
        if(dp[i][ct][flag]!=-1) 
            return dp[i][ct][flag];
        int limit = flag ? s[i]-'0' : 1;
        int choice = rec(i+1, flag && !limit, ct, s, k);
        if(limit) 
            choice = (choice + rec(i+1, flag && limit, ct+1, s, k))%MOD;
        return dp[i][ct][flag]=choice;
    }
public:
    int countKReducibleNumbers(string s, int k) {
        int n = s.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) 
                dp[i][j][0]=dp[i][j][1]=-1;
        }
        return rec(0, true, 0, s, k);
    }
};