class Solution {
    public int minMeetingRooms(int[][] intervals) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(); 
        Arrays.sort(intervals, (a,b) -> a[0] - b[0]); 
        pq.offer(intervals[0][1]); 

        for(int i = 1; i < intervals.length; i++){
            int nextStart = intervals[i][0]; 
            int nextEnd = intervals[i][1]; 

            if(!pq.isEmpty() && nextStart >= pq.peek()){
                pq.poll(); 
            }

            pq.offer(nextEnd); 
        }

        return pq.size(); 
    }
}