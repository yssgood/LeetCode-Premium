class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        long answer = 0; 
        Integer[] arr = new Integer[happiness.length]; 
        for(int i = 0; i < happiness.length; i++){
            arr[i] = happiness[i]; 
        }
        Arrays.sort(arr, Collections.reverseOrder()); 
        
        for(int i = 0; i < k; i++){
            arr[i] -= i; 
            if(arr[i] >= 0) answer += arr[i]; 
        }

        return answer; 
    }
}