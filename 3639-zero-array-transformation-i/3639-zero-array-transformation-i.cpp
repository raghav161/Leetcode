class Solution {
public:
    bool isZeroArray(vector<int>& N, vector<vector<int>>& Q) {
        vector<int> compute(N.size()+1);
        for (auto q: Q) {
            auto l = q.front(), r = q.back();
            compute[l]++;
            compute[r+1]--;
        }
        int now=0;
        for (auto i = 0; i < N.size(); i++) {
            now += compute[i];
            if (now < N[i]) 
                return false;
        }
        return true;
    }
};