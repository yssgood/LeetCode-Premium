class Solution {
    int[] prefixArr; 

    public Solution(int[] w) {
        prefixArr = new int[w.length]; 
        prefixArr[0] = w[0]; 
        for(int i = 1; i < w.length; i++){
            prefixArr[i] = w[i] + prefixArr[i-1]; 
        }
    }
    
    public int pickIndex() {
        int randomIndex = (int)(Math.random() * prefixArr[prefixArr.length-1]) + 1; 
        return binarySearch(randomIndex); 
    }

    private int binarySearch(int target){
        int left = 0, right = prefixArr.length; 
        int res = 0; 
        while(left < right){
            int middle = (left + right) / 2; 
            if(prefixArr[middle] >= target){
                res = middle; 
                right = middle; 
            } else{
                left = middle + 1; 
            }
        }
        return res; 
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */