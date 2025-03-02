class Solution {
    public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        Map<Integer,Integer> hashMap = new TreeMap<>(); 
        for(int[] arr : nums1){
            int id = arr[0], val = arr[1]; 
            
            hashMap.put(id,val); 
        }

        for(int[] arr : nums2){
            int id = arr[0], val = arr[1]; 
            hashMap.put(id, hashMap.getOrDefault(id,0) + val); 
        }

        int[][] result = new int[hashMap.size()][2]; 
        int index = 0; 
        for(Integer key : hashMap.keySet()){
            result[index][0] = key; 
            result[index][1] = hashMap.get(key); 
            index++; 
        }
        return result;  
    }
}