class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, (a,b) -> Integer.compare(a[0],b[0])); 
        int end = 0, n = points.length; 
        int answer = 0; 
        while(end < n){
            int currEnd = points[end][1]; 
            while(end + 1 < n && points[end+1][0] <= currEnd){
                currEnd = Math.min(currEnd, points[end+1][1]);
                end++; 
            }
            
            answer++; 
            end++; 
        }
        return answer;  
    }
}