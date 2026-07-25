class Solution {
    public int minMeetingRooms(int[][] intervals) {
        Arrays.sort(intervals, (a,b) -> Integer.compare(a[0], b[0])); 
        PriorityQueue<Integer> pq = new PriorityQueue<>(); 
        pq.offer(intervals[0][1]); 
        for(int i = 1; i < intervals.length; i++){
            int nextStartTime = intervals[i][0]; 
            int nextEndTime = intervals[i][1]; 
            if(!pq.isEmpty() && pq.peek() <= nextStartTime) pq.poll(); 
            pq.offer(nextEndTime); 
        }
        return pq.size(); 
    }
}