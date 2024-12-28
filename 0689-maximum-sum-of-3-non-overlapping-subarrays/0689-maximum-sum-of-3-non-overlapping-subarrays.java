class Solution {
    private int getMaxSum(int[] pre, int i, int n, int k, int[][] memo, int c) {
        if (c == 3 || i > n - k) {
            return 0;
        }
        if (memo[i][c] != 0) {
            return memo[i][c];
        }
        int sum = pre[i + k - 1] - (i > 0 ? pre[i - 1] : 0);
        int keep = sum + getMaxSum(pre, i + k, n, k, memo, c + 1);
        int skip = getMaxSum(pre, i + 1, n, k, memo, c);
        return memo[i][c] = Math.max(keep, skip);
    }

    private List<Integer> getIndexList(int[] pre, int i, int n, int k, List<Integer> indexList, int[][] memo, int c, int maxSum) {
        if ((c == 3 && maxSum == 0) || i > n - k) {
            return new ArrayList<>(indexList);
        }
        if (c == 3 || memo[i][c] != maxSum) {
            List<Integer> invalidList = new ArrayList<>();
            for (int j = 0; j < 3; j++) {
                invalidList.add(Integer.MAX_VALUE);
            }
            return invalidList;
        }
        int sum = pre[i + k - 1] - (i > 0 ? pre[i - 1] : 0);
        indexList.add(i);
        List<Integer> keep = getIndexList(pre, i + k, n, k, indexList, memo, c + 1, maxSum - sum);
        indexList.remove(indexList.size() - 1);
        List<Integer> skip = getIndexList(pre, i + 1, n, k, indexList, memo, c, maxSum);
        return lexicographicallySmaller(keep, skip) ? keep : skip;
    }

    private boolean lexicographicallySmaller(List<Integer> a, List<Integer> b) {
        // Check if either list is invalid
        if (a.contains(Integer.MAX_VALUE)) return false; // Skip invalid lists
        if (b.contains(Integer.MAX_VALUE)) return true;  // Prefer valid lists
        
        // Compare based on size first
        if (a.size() != b.size()) return a.size() > b.size();
        
        // Lexicographical comparison
        for (int i = 0; i < a.size(); i++) {
            if (a.get(i) < b.get(i)) {
                return true;
            }
            if (a.get(i) > b.get(i)) {
                return false;
            }
        }
        return false; // Both lists are equal
    }

    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int n = nums.length;
        int[] pre = new int[n];
        int[][] memo = new int[n][3];
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }
        int maxSum = getMaxSum(pre, 0, n, k, memo, 0);
        List<Integer> result = getIndexList(pre, 0, n, k, new ArrayList<>(), memo, 0, maxSum);
        return result.stream().mapToInt(x -> x).toArray();
    }
}
