class TimeMap {
    class Pair {
        int timestamp; 
        String value; 
        public Pair(int timestamp, String value){
            this.timestamp = timestamp;
            this.value = value; 
        }
    }
    
    Map<String, List<Pair>> hashMap = new HashMap<>(); 

    public TimeMap() {
        
    }
    
    public void set(String key, String value, int timestamp) {
        hashMap.computeIfAbsent(key, k -> new ArrayList<>()).add(new Pair(timestamp, value)); 
    }
    
    public String get(String key, int timestamp) {
        if(!hashMap.containsKey(key)) return ""; 
        List<Pair> target = hashMap.get(key); 
        int left = 0, right = target.size()-1; 
        String candidate = ""; 
        while(left <= right){
            int mid = left + (right - left) / 2; 
            if(target.get(mid).timestamp > timestamp){
                right = mid - 1; 
            } else if(target.get(mid).timestamp <= timestamp){
                candidate = target.get(mid).value; 
                left = mid + 1; 
            }  
        }
    
        
        return candidate; 
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */