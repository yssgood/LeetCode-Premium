class Solution {
    public int minTaps(int n, int[] ranges) {
        int[] distance = new int[n+1]; 
        for(int i = 0; i < ranges.length; i++){
            int l = Math.max(i - ranges[i],0); 
            int r = Math.min(i + ranges[i],n); 
            distance[l] = Math.max(distance[l],r); 
        }

        int currJump = 0; 
        int currMax = 0; 
        int answer = 0; 

        for(int i = 0; i < n; i++){
            currMax = Math.max(currMax, distance[i]); 
            if(currMax <= i) return -1; 
            if(i >= currJump){
                currJump = currMax; 
                answer++; 
                if(currJump >= n) return answer; 
            }
        }

        return -1; 

    }
}