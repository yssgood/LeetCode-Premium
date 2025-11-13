class Solution {
    public int[] findBuildings(int[] heights) {
        List<Integer> answer = new ArrayList<>(); 
        int max_ = -1; 
        for(int i = heights.length-1; i >= 0; i--){
            if(heights[i] > max_){
                answer.add(i); 
                max_ = heights[i]; 
            }
        }

        Collections.sort(answer); 
        int[] answerArray = new int[answer.size()]; 
        for(int i = 0; i < answer.size(); i++){
            answerArray[i] = answer.get(i); 
        }
        return answerArray; 
    }
}