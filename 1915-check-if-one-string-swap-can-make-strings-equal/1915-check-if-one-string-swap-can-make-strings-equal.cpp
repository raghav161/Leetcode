class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = size(s1), mismatch = 0, flag = 1;
        vector<int> arr(26);
        for (int i = 0; i < n; i++)
            arr[s1[i] - 'a']++, arr[s2[i] - 'a']--;
        for (auto freqDiff : arr){
            if (freqDiff) {
                flag = 0;
                break;
            }
        }
        if (!flag)
            return 0;
        for (int i = 0; i < n; i++){
            if (s1[i] != s2[i])
                mismatch++;
        }
        return mismatch <= 2;
    }
};