class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a,b) -> a[1] - b[1]); 
        int remove = 0; 
        int end = 0; 
        while(end < intervals.length){
            int currEnd = intervals[end][1]; 
            while(end + 1 < intervals.length && intervals[end+1][0] < currEnd){
                remove++; 
                end++; 
            }
            end++; 
        }

        return remove; 
    }
}