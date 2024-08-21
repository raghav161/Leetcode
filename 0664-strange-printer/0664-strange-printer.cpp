class Solution {
public:
    int n;
    vector<vector<int>> t;
    int solve(int l, int r, string& s){
        if(l == r)
            return 1;
        if(l > r)
            return 0;
        if(t[l][r] != -1)
            return t[l][r];
        int i = l+1;
        while(i <= r && s[i] == s[l])
            i++;
        if(i == r+1)
            return 1;
        int aage_ka = 1 + solve(i, r, s);;
        for(int j = i; j <= r; j++)
        {
            if(s[l] == s[j])
                aage_ka = min(aage_ka, solve(i, j-1, s) + solve(j, r, s));
        }
        return t[l][r] = aage_ka;
    }
    int strangePrinter(string s) {
        n = s.length();   
        t.resize(n, vector<int>(n+1, -1));
        return solve(0, n-1, s);
    }
};