class Solution {
    public long maximumImportance(int n, int[][] roads) {
        long ans = 0;
        long x = 1;
        int[] degree = new int[n];

        for (int[] road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }

        Arrays.sort(degree);

        for (int i : degree) {
            ans += (long)i * x;
            x++;
        }

        return ans;
    }
}