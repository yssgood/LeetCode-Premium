class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        int maxDiff = Integer.MIN_VALUE; 
        int min_ = arrays.get(0).get(0); 
        int max_ = arrays.get(0).getLast(); 
        for(int i = 1; i < arrays.size(); i++){
            int calc1 = Math.abs(max_ - arrays.get(i).get(0)); 
            int calc2 = Math.abs(min_ - arrays.get(i).getLast());
            maxDiff = Math.max(maxDiff, Math.max(calc1, calc2));
            min_ = Math.min(min_, arrays.get(i).get(0)); 
            max_ = Math.max(max_, arrays.get(i).getLast()); 
        }
        return maxDiff; 
    }
}