class Solution {
    public List<List<Integer>> findMissingRanges(int[] nums, int lower, int upper) {
        List<List<Integer>> answer = new ArrayList<>();
        int n = nums.length;

        if (n == 0) {
            answer.add(List.of(lower, upper));
            return answer;
        }

        // 1. lower ~ 첫 원소 앞
        if (nums[0] > lower) {
            answer.add(List.of(lower, nums[0] - 1));
        }

        // 2. 원소들 사이
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i-1] > 1) {
                answer.add(List.of(nums[i-1] + 1, nums[i] - 1));
            }
        }

        // 3. 마지막 원소 뒤 ~ upper
        if (nums[n-1] < upper) {
            answer.add(List.of(nums[n-1] + 1, upper));
        }

        return answer;
    }
}