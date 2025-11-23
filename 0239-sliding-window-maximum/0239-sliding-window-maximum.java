class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        //have monotonic increasing queue 
        LinkedList<Integer> dq = new LinkedList<>(); 
        List<Integer> answer = new ArrayList<>(); 

        for(int i = 0; i < nums.length; i++){
            if(!dq.isEmpty() && dq.peekFirst() <= i - k){
                dq.pollFirst(); 
            }

            while(!dq.isEmpty() && nums[i] > nums[dq.peekLast()]){
                dq.pollLast(); 
            }

            dq.add(i); 

            if(i - k + 1 >= 0){
                answer.add(nums[dq.peekFirst()]); 
            }
        }

        return answer.stream().mapToInt(Integer::intValue).toArray(); 
    }
}