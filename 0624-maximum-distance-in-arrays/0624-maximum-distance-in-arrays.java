class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        int min_ = arrays.get(0).get(0);  
        int curr_max = arrays.get(0).get(arrays.get(0).size()-1); 
        int answer = 0; 
        for(int i = 1; i < arrays.size(); i++){
            int last = arrays.get(i).size()-1; 
            answer = Math.max(answer, Math.abs(min_ - arrays.get(i).get(last))); 
            answer = Math.max(answer, Math.abs(arrays.get(i).get(0) - curr_max)); 

            min_ = Math.min(min_, arrays.get(i).get(0)); 
            curr_max = Math.max(curr_max, arrays.get(i).get(last)); 
        }
        return answer; 
    }
}