class RangeModule {
    TreeMap<Integer,Integer> treeMap = new TreeMap<>(); 

    public RangeModule() {
        
    }
    
    public void addRange(int left, int right) {
        
        Map.Entry<Integer,Integer> leftEntry = treeMap.floorEntry(left); 
        if(leftEntry != null && leftEntry.getValue() >= left){
            left = Math.min(left, leftEntry.getKey()); 
            right = Math.max(right, leftEntry.getValue());
            treeMap.remove(leftEntry.getKey()); 
        }

        Map.Entry<Integer,Integer> rightEntry = treeMap.ceilingEntry(left); 
        while(rightEntry != null && rightEntry.getKey() <= right){
            left = Math.min(left, rightEntry.getKey()); 
            right = Math.max(right, rightEntry.getValue()); 
            treeMap.remove(rightEntry.getKey()); 
        }

        treeMap.put(left, right); 
    }
    
    public boolean queryRange(int left, int right) {
        Map.Entry<Integer,Integer> targetEntry = treeMap.floorEntry(left);
        if(targetEntry == null) return false; 
        return targetEntry.getValue() >= right; 
    }
    
    public void removeRange(int left, int right) {
        
        Map.Entry<Integer,Integer> leftEntry = treeMap.floorEntry(left); 
        if(leftEntry != null && leftEntry.getValue() > left){
            int start = leftEntry.getKey(); 
            int end = leftEntry.getValue(); 
            if(start < left){
                treeMap.put(start, left); 
            }
            if(end > right){
                treeMap.put(right,end); 
            }
        }

        Map.Entry<Integer,Integer> rightEntry = treeMap.ceilingEntry(left); 
        while(rightEntry != null && rightEntry.getKey() < right){
            if(right < rightEntry.getValue()){
                treeMap.put(right, rightEntry.getValue()); 
                break; 
            }
            rightEntry = treeMap.ceilingEntry(left); 
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