class Solution {
    public int minMeetingRooms(int[][] intervals) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(); 
        Arrays.sort(intervals, (a,b) -> a[0] - b[0]); 
        pq.add(intervals[0][1]);
        for(int i = 1; i < intervals.length; i++){
            int nextStart = intervals[i][0]; 
            int top = pq.peek(); 
            if(!pq.isEmpty() && top <= nextStart){
                pq.poll(); 
            }
            pq.add(intervals[i][1]); 
        }
        return pq.size(); 
    }
}