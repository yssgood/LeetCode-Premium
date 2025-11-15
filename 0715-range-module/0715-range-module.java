class RangeModule {
    private TreeMap<Integer,Integer> map; 

    public RangeModule() {
        this.map = new TreeMap<>(); 
    }
    
    public void addRange(int left, int right) {
        if(left >= right) return; 

        Map.Entry<Integer,Integer> entry = map.floorEntry(left); 
        if(entry != null && entry.getValue() >= left){
            left = Math.min(left, entry.getKey()); 
            right = Math.max(right, entry.getValue()); 
            map.remove(entry.getKey()); 
        }

        entry = map.ceilingEntry(left); 
        while(entry != null && entry.getKey() <= right){
            right = Math.max(right, entry.getValue()); 
            map.remove(entry.getKey()); 
            entry = map.ceilingEntry(left); 
        }

        map.put(left,right); 
    }
    
    public boolean queryRange(int left, int right) {
        if (left >= right) return true; 
        Map.Entry<Integer,Integer> entry = map.floorEntry(left); 
        if(entry == null) return false; 

        return entry.getValue() >= right; 
    }
    
    public void removeRange(int left, int right) {
        if(left >= right) return; 

        Map.Entry<Integer,Integer> entry = map.floorEntry(left); 
        if(entry != null && entry.getValue() > left){
            int start = entry.getKey(); 
            int end = entry.getValue(); 
            map.remove(start); 

            if(start < left) {
                map.put(start, left); 
            }

            if(end > right){
                map.put(right,end); 
            }
        }

        entry = map.ceilingEntry(left); 
        while(entry != null && entry.getKey() < right){
            int start = entry.getKey(); 
            int end = entry.getValue(); 
            map.remove(start); 

            if(end > right) {
                map.put(right,end); 
                break; 
            }

            entry = map.ceilingEntry(left); 
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