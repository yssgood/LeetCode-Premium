class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int answer = 0; 
        Queue<Integer> q = new ArrayDeque<>(); 
        int index = 0; 
        int start = 0; 
        int k = 1; 
        while(index < nums.length){
            
            if(nums[index] == 0){
                q.add(index); 
            }

            while(q.size() > k){
                start = q.poll() + 1; 
            }

            answer = Math.max(answer, index - start + 1); 
            index++; 
        }
        return answer; 
    }
}