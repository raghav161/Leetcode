class Solution {
    int MOD = (int) 1e9 + 7;
    private int recursion(int[][] freq, String target, int[][] memo, int i, int tlen) {
        if (tlen == target.length()) {
            return 1;
        }

        if (i >= freq.length) {
            return 0;
        }

        if (memo[i][tlen] != -1) {
            return memo[i][tlen];
        }

        int take = 0, notTake = 0;

        char tchar = target.charAt(tlen);

        if (freq[i][tchar - 'a'] > 0) {
            take = (int) ((long) freq[i][tchar - 'a'] * recursion(freq, target, memo, i + 1, tlen + 1) % MOD);
        }

        notTake = recursion(freq, target, memo, i + 1, tlen) % MOD;

        memo[i][tlen] = (take + notTake) % MOD;
        return memo[i][tlen];
    }

    public int numWays(String[] words, String target) {
        int m = words[0].length();
        int[][] freq = new int[m][26];

        for (String word : words) {
            for (int i = 0; i < m; i++) {
                freq[i][word.charAt(i) - 'a']++;
            }
        }

        int[][] memo = new int[m][target.length()];
        for (int[] dp : memo) {
            Arrays.fill(dp, -1);
        }

        return recursion(freq, target, memo, 0, 0);
    }
}