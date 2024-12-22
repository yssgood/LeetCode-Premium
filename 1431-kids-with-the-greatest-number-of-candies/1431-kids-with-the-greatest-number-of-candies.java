class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        List<Boolean> answer = new ArrayList<>(Collections.nCopies(candies.length,false)); 
        int max_ = 0; 
        for(int n : candies) max_ = Math.max(max_,n); 
        for(int i = 0; i < candies.length; i++){
            if(candies[i] + extraCandies >= max_){
                answer.set(i,true); 
            }
        }


        return answer; 
    }
}