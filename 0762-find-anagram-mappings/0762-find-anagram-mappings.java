class Solution {
    public int[] anagramMappings(int[] nums1, int[] nums2) {
        HashMap<Integer,Integer> hashMap = new HashMap<>(); 
        for(int i = 0; i < nums2.length; i++){
            hashMap.put(nums2[i], i); 
        }
        int[] answer = new int[nums1.length]; 
        for (int i = 0; i < nums1.length; i++){
            answer[i] = hashMap.get(nums1[i]); 
        }
        return answer; 
    }
}