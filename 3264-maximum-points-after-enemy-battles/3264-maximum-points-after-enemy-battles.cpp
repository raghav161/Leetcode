class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        long long profit = 0, n = enemyEnergies.size(), j = n - 1;
        sort(enemyEnergies.begin(), enemyEnergies.end());
        if(enemyEnergies[0] > currentEnergy)
            return 0;
        while(j >= 0)
        {
            if(enemyEnergies[0] <= currentEnergy)
            {
                profit += currentEnergy/enemyEnergies[0];
                currentEnergy %= enemyEnergies[0];
            }
            else{
                currentEnergy += enemyEnergies[j];
                j--;
            }
        }
        return profit;
    }
};