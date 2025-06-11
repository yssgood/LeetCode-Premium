class Solution {
    public int longestSubsequence(int[] arr, int difference) {
        int n = arr.length; 
        if(n <= 1) return 1; 
        Map<Integer,Integer> dp = new HashMap<>(); 
        int max_ = 1; 
        
        for(int i = 0; i < n; i++){
            int target = arr[i] - difference; 
            if(dp.containsKey(target)){
                dp.put(arr[i], dp.getOrDefault(target,0) + 1); 
                max_ = Math.max(max_, dp.get(arr[i])); 
            } else{
                dp.put(arr[i],1); 
            }
        }

        return max_; 
    }
}