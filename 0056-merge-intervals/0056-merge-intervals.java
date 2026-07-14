class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a,b) -> a[0] - b[0]); 
        List<int[]> answer = new ArrayList<>(); 
        int end = 0, n = intervals.length; 
        while(end < n){
            int[] curr = intervals[end]; 
            int nextMax = curr[1]; 
            while(end + 1 < n && intervals[end+1][0] <= nextMax){
                nextMax = Math.max(nextMax, intervals[end+1][1]); 
                end++; 
            }

            answer.add(new int[]{curr[0], nextMax}); 
            end++; 
        }
        
        return answer.toArray(new int[answer.size()][]);
    }
}