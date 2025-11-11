class TwoSum {
    private Map<Integer,Integer> hashMap;  
    public TwoSum() {
        hashMap = new HashMap<>(); 
    }
    
    public void add(int number) {
        hashMap.put(number,hashMap.getOrDefault(number,0)+1); 
    }
    
    public boolean find(int value) {
        for(int keys : hashMap.keySet()){
            int target = value - keys; 
            if(target == keys){
                if(hashMap.get(target) > 1) return true; 
            } else if(hashMap.containsKey(target)){
                return true; 
            }
        }
        return false; 
    }
}

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * boolean param_2 = obj.find(value);
 */