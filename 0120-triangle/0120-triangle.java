class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        if(triangle.size() == 1) return triangle.get(0).get(0); 
        for(int i = 1; i < triangle.size(); i++){
            for(int j = 0; j < triangle.get(i).size(); j++){
                int curr = triangle.get(i).get(j); 
                int left_min = j > 0 ? triangle.get(i-1).get(j-1) : 10001; 
                int right_min = j < triangle.get(i-1).size() ? triangle.get(i-1).get(j) : 10001; 
                //triangle.get(i).get(j) = Math.min(curr + left_min, curr + right_min); 
                triangle.get(i).set(j,Math.min(curr + left_min, curr + right_min)); 
            }
        }
        

        return Collections.min(triangle.get(triangle.size()-1)); 
    }
}