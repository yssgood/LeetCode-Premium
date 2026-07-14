class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        if(intervals.length == 0) return new int[][]{newInterval};   // 2차원 배열로 감싸기
        List<int[]> answer = new ArrayList<>(); 
        int end = 0, n = intervals.length; 
        while(end < n && intervals[end][1] < newInterval[0]){
            answer.add(intervals[end]); 
            end++; 
        }

        int currMin = newInterval[0]; 
        int currMax = newInterval[1]; 
        while(end < n && intervals[end][0] <= currMax){
            currMin = Math.min(currMin, intervals[end][0]); 
            currMax = Math.max(currMax, intervals[end][1]); 
            end++; 
        }

        answer.add(new int[]{currMin, currMax}); 

        while(end < n) answer.add(intervals[end++]); 

        return answer.toArray(new int[answer.size()][]); 
    }
}