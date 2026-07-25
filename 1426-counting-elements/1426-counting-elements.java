class Solution {
    public int countElements(int[] arr) {
        Map<Integer,Integer> hashMap = new HashMap<>(); 
        int answer = 0; 
        for(int n : arr) hashMap.merge(n,1,Integer::sum); 
        for(var e : hashMap.entrySet()){
            if(hashMap.containsKey(e.getKey() + 1)){
                answer += e.getValue(); 
            }
        }
        return answer; 
    }
}