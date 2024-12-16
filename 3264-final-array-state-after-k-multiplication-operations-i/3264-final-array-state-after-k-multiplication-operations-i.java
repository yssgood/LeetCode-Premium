class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        PriorityQueue<int[]> heap = new PriorityQueue<>((a,b) -> {
            if(a[0] == b[0]){
                return Integer.compare(a[1],b[1]); 
            }
            return Integer.compare(a[0],b[0]); 
        });

        for(int i = 0; i < nums.length; i++){
            heap.offer(new int[]{nums[i],i}); 
        }

        while(k-- > 0){
            int[] smallest = heap.poll(); 
            nums[smallest[1]] *= multiplier;  
            heap.offer(new int[] {nums[smallest[1]], smallest[1]}); 
        }
        
        return nums; 
    }
}