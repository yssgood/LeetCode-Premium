class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a,b)-> a[0] - b[0]); 
        List<int[]> answer = new ArrayList<>(); 
        int end = 0; 
        while(end < intervals.length){
            int start = intervals[end][0]; 
            int curr = intervals[end][1]; 
            while(end + 1 < intervals.length && intervals[end+1][0] <= curr){
                curr = Math.max(curr, intervals[end+1][1]); 
                end++; 
            }
            answer.add(new int[]{start, curr}); 
            end++; 
        }
        int[][] res = new int[answer.size()][]; 
        for(int i = 0; i < res.length; i++){
            res[i] = answer.get(i); 
        }
        return res; 
    }
}