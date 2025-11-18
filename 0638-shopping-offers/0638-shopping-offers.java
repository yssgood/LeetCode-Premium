class Solution {
    Map<List<Integer>, Integer> memo = new HashMap<>(); 
    public int shoppingOffers(List<Integer> price, List<List<Integer>> special, List<Integer> needs) {
        return helper(price, special, needs); 
    }

    public int helper(List<Integer> price, List<List<Integer>> special, List<Integer> needs){
        if(memo.containsKey(needs)) return memo.get(needs); 
        int min_price = 0;  
        for(int i = 0; i < price.size(); i++){
            min_price += price.get(i) * needs.get(i); 
        }

        for(int i = 0; i < special.size(); i++){
            List<Integer> newNeeds = new ArrayList<>(); 
            boolean valid = true; 
            for(int j = 0; j < special.get(i).size()-1; j++){
                int leftOver = needs.get(j) - special.get(i).get(j); 
                newNeeds.add(leftOver); 
                if(leftOver < 0){
                    valid = false; 
                    break; 
                }
            }

            if(valid){
                min_price = Math.min(min_price, helper(price, special, newNeeds) + special.get(i).get(special.get(i).size()-1));
            }
        }

        memo.put(needs,min_price); 

        return min_price; 
    }
}