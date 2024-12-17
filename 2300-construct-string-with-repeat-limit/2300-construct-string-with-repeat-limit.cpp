class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char, int> mp;
        for(auto& ch : s)
            mp[ch]++;
        string ans;
        while (!mp.empty()) {
            auto it = prev(mp.end());
            char ch = it->first;
            int freq = min(it->second, repeatLimit);
            ans.append(freq, ch);
            mp[ch] -= freq;
            if (mp[ch] > 0) {
                auto nextIt = prev(it);
                if (it == mp.begin() || nextIt == mp.end())
                    break;
                char nextCh = nextIt->first;
                ans.push_back(nextCh);
                mp[nextCh]--;
                if (mp[nextCh] == 0)
                    mp.erase(nextCh);
            }
            if (mp[ch] == 0)
                mp.erase(ch);
        }
        return ans;
    }
};
