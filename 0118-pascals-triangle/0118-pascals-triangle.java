class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> answer = new ArrayList<>(); 
        for(int i = 0; i < numRows; i++){
            List<Integer> tmp = new ArrayList<>(Collections.nCopies(i+1,1)); 
            for(int j = 1; j < i; j++){
                int number = answer.get(i-1).get(j-1) + answer.get(i-1).get(j);
                tmp.set(j,number); 
            }
            answer.add(tmp); 
        }
        return answer; 
    }
}