class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, maxi=values[0];
        for(int j = 1; j < values.size(); j++)
        {
            ans = max(ans, values[j]-j+maxi);
            maxi = max(maxi, values[j]+j);
        }
        return ans;
    }
};
