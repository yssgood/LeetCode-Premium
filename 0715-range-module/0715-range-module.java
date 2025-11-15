class RangeModule {

    TreeMap<Integer,Integer> rangeMap; 

    public RangeModule() {
        this.rangeMap = new TreeMap<>(); 
    }
    
    public void addRange(int left, int right) {
        
        Map.Entry<Integer,Integer> entry = rangeMap.floorEntry(left); 
        if(entry != null && entry.getValue() >= left){
            left = Math.min(entry.getKey(), left); 
            right = Math.max(entry.getValue(), right); 
            rangeMap.remove(entry.getKey()); 
        }

        entry = rangeMap.ceilingEntry(left); 
        while(entry != null && entry.getKey() <= right){
            right = Math.max(entry.getValue(), right); 
            rangeMap.remove(entry.getKey()); 
            entry = rangeMap.ceilingEntry(left); 
        }


        rangeMap.put(left, right); 
    }
    
    public boolean queryRange(int left, int right) {
        //search for the lowerbound of the left 
        //return true if the right value is bigger than or equal to the right 
        Map.Entry<Integer,Integer>  entry = rangeMap.floorEntry(left); 
        if(entry == null) return false; 
        return entry.getValue() >= right; 
    }
    
    public void removeRange(int left, int right) {
        Map.Entry<Integer,Integer> entry = rangeMap.floorEntry(left);
        if(entry != null && entry.getValue() > left){
            int start = entry.getKey();
            int end = entry.getValue(); 
            rangeMap.remove(start); 
            if(start < left){
                rangeMap.put(start, left); 
            }

            if(end > right){
                rangeMap.put(right, end); 
            }
        }

        entry = rangeMap.ceilingEntry(left); 
        while(entry != null && entry.getKey() < right){
            int start = entry.getKey();
            int end = entry.getValue();
            rangeMap.remove(start); 

            if(end > right){
                rangeMap.put(right, end);
                break; 
            }

            entry = rangeMap.ceilingEntry(left); 
        }
    }
}

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * boolean param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */