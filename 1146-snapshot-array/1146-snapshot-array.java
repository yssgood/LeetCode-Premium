class SnapshotArray {

    List<TreeMap<Integer,Integer>> lst = new ArrayList<>(); 
    int snapId = 0; 

    public SnapshotArray(int length) {
        for(int i = 0; i < length; i++){
            lst.add(new TreeMap<>()); 
        }
    }
    
    public void set(int index, int val) {
        lst.get(index).put(snapId,val); 
    }
    
    public int snap() {
        return snapId++; 
    }
    
    public int get(int index, int snap_id) {
        Map.Entry<Integer,Integer> entry = lst.get(index).floorEntry(snap_id); 
        if(entry == null) return 0; 
        return entry.getValue(); 
    }
}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray obj = new SnapshotArray(length);
 * obj.set(index,val);
 * int param_2 = obj.snap();
 * int param_3 = obj.get(index,snap_id);
 */