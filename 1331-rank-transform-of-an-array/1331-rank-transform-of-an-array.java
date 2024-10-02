class Solution {
    public int[] arrayRankTransform(int[] arr) {
        int[] copy = new int[arr.length]; 
        int[] answer = new int[arr.length]; 
        HashMap<Integer,Integer> hashMap = new HashMap<>(); 
        for(int i = 0; i < arr.length; i++) copy[i] = arr[i]; 
        Arrays.sort(copy); 
        int count = 1; 
        for(int i = 0; i < arr.length; i++){
            if(!hashMap.containsKey(copy[i])){
                hashMap.put(copy[i],count++); 
            }
        }

        for(int i = 0; i < arr.length; i++){
            answer[i] = hashMap.get(arr[i]); 
        }

        return answer; 
    }
}