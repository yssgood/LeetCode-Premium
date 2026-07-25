class Solution {
    public List<List<Integer>> removeInterval(int[][] intervals, int[] toBeRemoved) {
        List<List<Integer>> answer = new ArrayList<>(); 
        for(int i = 0; i < intervals.length; i++){
            int L = intervals[i][0], R = intervals[i][1]; 

            if(L < toBeRemoved[0]){
                answer.add(List.of(L, Math.min(R,toBeRemoved[0]))); 
            }

            if(R > toBeRemoved[1]){
                answer.add(List.of(Math.max(L,toBeRemoved[1]), R)); 
            }
        }

        return answer; 
    }
}