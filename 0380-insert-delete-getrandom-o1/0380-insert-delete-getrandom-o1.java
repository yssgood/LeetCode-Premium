class RandomizedSet {

    List<Integer> arrayList = new ArrayList<>(); 
    Map<Integer,Integer> hashMap = new HashMap<>(); 
    int index = 0; 

    public RandomizedSet() {
        
    }
    
    public boolean insert(int val) {
        if(hashMap.containsKey(val)) return false; 

        arrayList.add(val); 
        hashMap.put(val, index++); 

        return true; 
    }
    
    public boolean remove(int val) {
        if(!hashMap.containsKey(val)) return false; 

        int targetVal = arrayList.get(arrayList.size()-1); 
        int valIndex = hashMap.get(val); 

        arrayList.set(valIndex, targetVal); 
        arrayList.set(arrayList.size()-1, val); 

        arrayList.removeLast(); 
        hashMap.put(targetVal, valIndex); 
        hashMap.remove(val); 
        index--; 

        return true; 
    }
    
    public int getRandom() {
        int randomIndex = (int)(Math.random() * arrayList.size()); 
        return arrayList.get(randomIndex);
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */