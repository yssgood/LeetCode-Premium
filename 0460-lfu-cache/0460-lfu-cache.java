class Cache {
    int key; 
    int value; 
    int frequency; 
    public Cache (int key, int value, int frequency){
        this.key = key; 
        this.value = value; 
        this.frequency = frequency; 
    }
}
class LFUCache {

    private Map<Integer, LinkedList<Cache>> freqMap = new HashMap<>(); 
    private Map<Integer, Cache> hashMap = new HashMap<>(); 
    private int capacity = 0; 
    private int size = 0; 
    private int min_counter = 1; 

    public LFUCache(int capacity) {
        this.capacity = capacity; 
    }
    
    public int get(int key) {
        if(!hashMap.containsKey(key)) return -1; 
        Cache target = hashMap.get(key); 
        //frequency update 
        updateFrequency(target); 
        return target.value; 
    }
    
    public void put(int key, int value) {
        if(hashMap.containsKey(key)){
            Cache target = hashMap.get(key); 
            target.value = value; 
            //frequency update 
            updateFrequency(target); 
            hashMap.put(key, target); 
            return;   
        }

        if(size >= capacity){
            LinkedList<Cache> lfuList = freqMap.get(min_counter); 
            Cache evictCache = lfuList.pollFirst(); //least recently used 
            if(lfuList.isEmpty()){
                freqMap.remove(min_counter); 
            }
            size--; 
            hashMap.remove(evictCache.key); 
        }

        Cache newCache = new Cache(key,value,1);
        min_counter = 1; 
        size++; 

        hashMap.put(key, newCache); 
        freqMap.computeIfAbsent(1, k -> new LinkedList<Cache>()).add(newCache); 
    }

    void updateFrequency(Cache target){
        int oldCount = target.frequency; 
        LinkedList<Cache> oldGroup = freqMap.get(oldCount); 
        if(!oldGroup.isEmpty()){
            oldGroup.remove(target); 
            if(oldGroup.isEmpty() && oldCount == min_counter){
                min_counter++; 
            }
        }
        target.frequency++; 
        freqMap.computeIfAbsent(target.frequency, k -> new LinkedList<Cache>()).add(target); 
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */