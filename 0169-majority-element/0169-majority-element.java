class Solution {
    public int majorityElement(int[] nums) {
        int len = nums.length; 
        Map<Integer,Integer> hashMap = new HashMap<>(); 
        for(int n : nums) hashMap.put(n, hashMap.getOrDefault(n,0) + 1);

        for(Map.Entry<Integer,Integer> e : hashMap.entrySet()){
            if(e.getValue() > (len / 2)){
                System.out.println(e.getValue()); 
                return e.getKey(); 
            }
        }
        return -1; 
    }
}