class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        List<Integer> lst = new ArrayList<>();
        
        // Add all elements to list
        for(int n : arr){
            lst.add(n);
        }
        
        // Sort by distance to x
        Collections.sort(lst, (a, b) -> {
            int diffA = Math.abs(a - x); 
            int diffB = Math.abs(b - x);
            
            if(diffA == diffB) return a - b;  // tie: smaller value first
            return diffA - diffB;  // closer value first
        }); 
        
        // Take first k elements
        List<Integer> answer = new ArrayList<>();
        for(int i = 0; i < k; i++){
            answer.add(lst.get(i));
        }
        
        // Sort result in ascending order
        Collections.sort(answer);
        
        return answer; 
    }
}