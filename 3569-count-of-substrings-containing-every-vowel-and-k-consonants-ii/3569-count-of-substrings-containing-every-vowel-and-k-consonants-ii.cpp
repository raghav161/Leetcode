class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        vector<int> pre(word.length() + 1);
        for(int i=1;i<=word.length();i++)
        {
            char ch = word[i-1];
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                pre[i] = pre[i-1];
            else
                pre[i] = pre[i-1] + 1;
        }
        unordered_map<int, vector<int>> arr;
        for(int i=0;i<=word.length();i++)
            arr[pre[i]].push_back(i);        
        int last_a = -1, last_e = -1, last_i = -1, last_o = -1, last_u = -1;
        long long result = 0;
        for(int r = 1; r <= word.length(); ++r){
            char ch = word[r-1];
            if(ch == 'a') last_a = r;
            if(ch == 'e') last_e = r;
            if(ch == 'i') last_i = r;
            if(ch == 'o') last_o = r;
            if(ch == 'u') last_u = r;
            if(last_a != -1 && last_e != -1 && last_i != -1 && last_o != -1 && last_u != -1)
            {
                int left_min = min({last_a, last_e, last_i, last_o, last_u});
                int C = pre[r] - k;
                if(C < 0)
                    continue;
                if(arr.find(C) != arr.end())
                {
                    int cnt = upper_bound(arr[C].begin(), arr[C].end(), left_min - 1) - arr[C].begin();
                    result += cnt;
                }
            }
        }
        return result;
    }
};
