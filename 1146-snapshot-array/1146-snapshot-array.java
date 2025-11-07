class SnapshotArray {
    List<Map<Integer, Integer>> arr = new ArrayList<>(); 
    int snapId = 0; 

    public SnapshotArray(int length) {
        for(int i = 0; i < length; i++){
            arr.add(new HashMap<>()); 
        }
    }
    
    public void set(int index, int val) {
        arr.get(index).put(snapId, val); 
    }
    
    public int snap() {
        return snapId++; 
    }
    
    public int get(int index, int snap_id) {
        Map<Integer,Integer> history = arr.get(index); 
        for(int id = snap_id;  id >= 0; id--){
            if(history.containsKey(id)){
                return history.get(id); 
            }
        }
        return 0; 
    }
}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray obj = new SnapshotArray(length);
 * obj.set(index,val);
 * int param_2 = obj.snap();
 * int param_3 = obj.get(index,snap_id);
 */