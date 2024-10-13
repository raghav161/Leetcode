class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> result;
        unordered_map<int, int> freqMap;
        multiset<pair<int, int>> freqSet;

        for (int i = 0; i < k; i++)
            freqMap[nums[i]]++;
        for (auto it : freqMap)
            freqSet.insert({it.second, it.first});

        auto calculateXSum = [&](multiset<pair<int, int>>& freqSet, int x) {
            int sum = 0;
            auto it = freqSet.rbegin();
            while (x-- > 0 && it != freqSet.rend()) {
                sum += (it->second) * (it->first);
                ++it;
            }
            return sum;
        };

        result.push_back(calculateXSum(freqSet, x));

        for (int i = k; i < n; i++) {
            int newElem = nums[i];
            int oldElem = nums[i - k];

            freqSet.erase({freqMap[oldElem], oldElem});
            freqMap[oldElem]--;
            if (freqMap[oldElem] > 0) {
                freqSet.insert({freqMap[oldElem], oldElem});
            } else {
                freqMap.erase(oldElem);
            }

            freqSet.erase({freqMap[newElem], newElem});
            freqMap[newElem]++;
            freqSet.insert({freqMap[newElem], newElem});

            result.push_back(calculateXSum(freqSet, x));
        }

        return result;
    }
};
