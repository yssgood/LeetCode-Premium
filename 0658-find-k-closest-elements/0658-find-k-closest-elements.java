class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        List<Integer> lst = new ArrayList<>(); 
        for(int n : arr) lst.add(n); 

        lst.sort((a,b) -> {
            int resA = Math.abs(a - x); 
            int resB = Math.abs(b - x); 

            if(resA == resB) return Integer.compare(a,b); 

            return Integer.compare(resA,resB); 
        });

        List<Integer> answer = new ArrayList<>(); 
        for(int i = 0; i < k; i++) answer.add(lst.get(i)); 
        answer.sort(Comparator.naturalOrder()); 
        return answer; 
    }
}