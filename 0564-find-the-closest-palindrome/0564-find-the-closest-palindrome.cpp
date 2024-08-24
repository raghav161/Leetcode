class Solution {
public:
    string nearestPalindromic(string n) {
        int l = n.size();
        set<long> canBeNumber;
        canBeNumber.insert(long(pow(10, l)) + 1);
        canBeNumber.insert(long(pow(10, l-1) - 1)); 
        long long prefix = stol(n.substr(0, (l+1)/2));
        for(int i=-1;i<=1;i++)
        {
            string p = to_string(prefix + i);
            string pp = p + string(p.rbegin() + (l & 1), p.rend());
            canBeNumber.insert(stol(pp));
        }
        long num = stol(n), minDiff = LONG_MAX, ans;
        for(auto val:canBeNumber)
        {
            if(val == num) 
                continue;
            if(minDiff > abs(val - num))
            {
                ans = val;
                minDiff = abs(val - num);
            } 
            else if(minDiff == abs(val - num))
                ans = min(ans, val);
        }
        return to_string(ans);
    }
};
