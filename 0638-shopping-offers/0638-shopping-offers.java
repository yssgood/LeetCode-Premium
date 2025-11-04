class Solution {
    private Map<List<Integer>, Integer> memo = new HashMap<>();
    public int shoppingOffers(List<Integer> price, List<List<Integer>> special, List<Integer> needs) {
        return dfs(price, special, needs); 
    }

    public int dfs(List<Integer> price, List<List<Integer>> special, List<Integer> needs){
        if(memo.containsKey(needs)) return memo.get(needs);
        
        int minPrice = 0; 
        for(int i = 0; i < needs.size(); i++){
            minPrice += needs.get(i) * price.get(i);  
        }

        for(List<Integer> offer : special){
            List<Integer> newNeeds = new ArrayList<>(needs); 
            boolean valid = true; 
            for(int i = 0; i < needs.size(); i++){
                newNeeds.set(i, newNeeds.get(i) - offer.get(i)); 
                if(newNeeds.get(i) < 0){
                    valid = false;
                    break; 
                }
            }

            if(valid){
                minPrice = Math.min(minPrice, offer.get(offer.size()-1) + dfs(price, special, newNeeds)); 
            }
        }
        memo.put(needs, minPrice);
        return minPrice; 
    }
}