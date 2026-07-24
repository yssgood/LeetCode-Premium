class Solution {
    public int countElements(int[] arr) {
        Map<Integer,Integer> hashMap = new HashMap<>(); 
        int answer = 0; 
        for(int i = 0; i < arr.length; i++){
            hashMap.merge(arr[i],1,Integer::sum); 
        }
        for(var e : hashMap.entrySet()){
            if(hashMap.containsKey(e.getKey()-1)){
                answer += hashMap.get(e.getKey()-1); 
            }
        }
        return answer; 
    }
}