class Solution {
    public int[] findBuildings(int[] heights) {
        List<Integer> answer = new ArrayList<>(); 
        int max_ = 0; 
        for(int i = heights.length-1; i >= 0; i--){
            if(heights[i] > max_){
                answer.add(i); 
            }
            max_ = Math.max(max_, heights[i]); 
        }
        Collections.sort(answer); 
        return answer.stream().mapToInt(i -> i).toArray(); 
    }
}