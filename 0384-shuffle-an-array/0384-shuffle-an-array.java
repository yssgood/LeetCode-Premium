class Solution {
    int[] original; 
    int[] arr; 
    Random rand = new Random(); 

    public Solution(int[] nums) {
        original = nums.clone(); 
        arr = nums.clone(); 
    }
    
    public int[] reset() {
        arr = original.clone(); 
        return arr; 
    }
    
    public int[] shuffle() {
        for(int i = arr.length-1; i>= 0; i--){
            int tmp = arr[i]; 
            int j = rand.nextInt(i+1); 
            arr[i] = arr[j]; 
            arr[j] = tmp; 
        }
        return arr; 
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */