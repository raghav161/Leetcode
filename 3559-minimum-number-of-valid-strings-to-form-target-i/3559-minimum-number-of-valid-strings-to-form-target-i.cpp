class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
    const int INF = INT_MAX / 2;
    int n = target.size();
    vector<int> dp(n + 1, INF);
    dp[0] = 0;

    struct TrieNode {
        TrieNode* children[26];
        TrieNode() {
            memset(children, 0, sizeof(children));
        }
    };

    TrieNode* root = new TrieNode();

    // Insert all words into the Trie
    for (const string& word : words) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
    }

    // Dynamic Programming to find the minimum number of valid strings
    for (int i = 0; i < n; ++i) {
        if (dp[i] == INF) continue;

        TrieNode* node = root;
        for (int j = i; j < n; ++j) {
            int idx = target[j] - 'a';
            if (!node->children[idx]) break;
            node = node->children[idx];
            dp[j + 1] = min(dp[j + 1], dp[i] + 1);
        }
    }

    return dp[n] == INF ? -1 : dp[n];
}
};
