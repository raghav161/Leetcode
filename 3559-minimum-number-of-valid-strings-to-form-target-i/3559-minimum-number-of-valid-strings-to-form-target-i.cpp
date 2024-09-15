class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        int n = target.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        struct TrieNode {
            TrieNode* children[26];
            TrieNode() { memset(children, 0, sizeof(children)); }
        };
        TrieNode* root = new TrieNode();
        for(auto& word:words) {
            TrieNode* node=root;
            for(auto c:word)
            {
                if(!node->children[c-'a'])
                    node->children[c-'a'] = new TrieNode();
                node = node->children[c-'a'];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dp[i]==INT_MAX)
                continue;
            TrieNode* node = root;
            for(int j=i;j<n;j++)
            {
                if(!node->children[target[j]-'a'])
                    break;
                node = node->children[target[j]-'a'];
                dp[j+1] = min(dp[j+1], dp[i]+1);
            }
        }
        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};
