class Solution {
    public boolean canAttendMeetings(int[][] intervals) {
        if(intervals.length == 0) return true; 
        Arrays.sort(intervals, (a,b) -> Integer.compare(a[0],b[0])); 
        int endTime = intervals[0][1]; 
        for(int i = 1; i < intervals.length; i++){
            int nextEndTime = intervals[i][1]; 
            int nextStartTime = intervals[i][0]; 
            if(endTime > nextStartTime) return false; 
            endTime = nextEndTime; 
        }
        return true; 
    }
}