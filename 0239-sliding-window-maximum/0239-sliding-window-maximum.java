class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        List<Integer> lst = new ArrayList<>(); 
        LinkedList<Integer> dequeue = new LinkedList<>(); 

        for(int i = 0; i < nums.length; i++){
            //widow checking 
            if(!dequeue.isEmpty() && dequeue.peekFirst() <= i - k){
                dequeue.pollFirst(); 
            }

            while(!dequeue.isEmpty() && nums[dequeue.peekLast()] < nums[i]){
                dequeue.pollFirst(); 
            }

            dequeue.add(i); 
            //System.out.println(dequeue.size()); 
            if(i - k + 1 >= 0){
                lst.add(nums[dequeue.peekFirst()]); 
            }
        }

        int[] res = new int[lst.size()]; 
        for(int i = 0; i < lst.size(); i++){
            res[i] = lst.get(i); 
        }

        return res; 
    }
}