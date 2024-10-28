class Solution {
    public int longestSquareStreak(int[] nums) {
        Arrays.sort(nums);
        Map<Integer, Integer> dp = new HashMap<>();
        int result = 0;

        for (int num : nums) {
            if (dp.containsKey((int) Math.sqrt(num)) && Math.sqrt(num) == (int) Math.sqrt(num)) {
                dp.put(num, dp.get((int) Math.sqrt(num)) + 1);
            } else {
                dp.put(num, 1);
            }
            result = Math.max(result, dp.get(num));
        }

        return result == 1 ? -1 : result;
    }
}