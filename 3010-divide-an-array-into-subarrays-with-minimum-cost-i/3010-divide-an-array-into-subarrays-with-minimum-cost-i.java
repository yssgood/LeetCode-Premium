class Solution {
    public int minimumCost(int[] nums) {
        int answer = nums[0]; 
        List<Integer> arrList = new ArrayList<>();
        for(int i = 1; i < nums.length; i++) arrList.add(nums[i]); 
        Collections.sort(arrList);
        answer += arrList.get(0);
        answer += arrList.get(1); 
        return answer; 
    }
}