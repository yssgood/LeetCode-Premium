class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        int smallest = arrays.get(0).get(0); 
        int largest = arrays.get(0).getLast(); 
        int answer = 0; 
        for(int i = 1; i < arrays.size(); i++){
            answer = Math.max(answer, Math.abs(arrays.get(i).getLast() - smallest)); 
            answer = Math.max(answer, Math.abs(arrays.get(i).get(0) - largest)); 
            smallest = Math.min(smallest, arrays.get(i).get(0)); 
            largest = Math.max(largest, arrays.get(i).getLast()); 
        }
        return answer; 
    }
}