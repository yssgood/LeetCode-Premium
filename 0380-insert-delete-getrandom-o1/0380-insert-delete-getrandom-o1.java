class RandomizedSet {
    Map<Integer,Integer> hashMap = new HashMap<>(); 
    ArrayList<Integer> lst = new ArrayList<>(); 

    public RandomizedSet() {
        
    }
    
    public boolean insert(int val) {
        if(hashMap.containsKey(val)) return false; 

        lst.add(val); 
        hashMap.put(val, lst.size() - 1); 

        return true;  
    }
    
    public boolean remove(int val) {
        if(!hashMap.containsKey(val)) return false; 

        int originPos = hashMap.get(val); 
        int lastNum = lst.get(lst.size()-1); 

        lst.set(originPos, lastNum); 
        lst.set(lst.size()-1, val); 

        lst.remove(lst.size()-1); 
        hashMap.put(lastNum, originPos); 

        hashMap.remove(val); 

        return true; 
    }
    
    public int getRandom() {
        int randomIndex = (int)(Math.random() * lst.size()); 
        return lst.get(randomIndex);
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */