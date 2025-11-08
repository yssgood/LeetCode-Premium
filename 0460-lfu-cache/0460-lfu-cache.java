class Cache {
    int key; 
    int value; 
    int count; 
    public Cache(int key, int value) {
        this.key = key;
        this.value = value;
        this.count = 1; 
    }
}

class LFUCache {
    private final int capacity; 
    private int size; 
    private int minFreq; 

    private Map<Integer, Cache> cacheMap; 
    private Map<Integer, LinkedHashSet<Cache>> freqMap; 

    public LFUCache(int capacity) {
        this.capacity = capacity; 
        this.size = 0;
        this.minFreq = 0; 
        this.cacheMap = new HashMap<>(); 
        this.freqMap = new HashMap<>(); 
    }
    
    public int get(int key) {
        if(!cacheMap.containsKey(key)) return -1; 

        Cache node = cacheMap.get(key); 
        updateFrequency(node); 
        return node.value; 
    }
    
    public void put(int key, int value) {
        if(capacity == 0) return; 
        if(cacheMap.containsKey(key)){
            Cache node = cacheMap.get(key); 
            node.value = value; 
            updateFrequency(node); 
            return; 
        } 

        if (size >= capacity) {
            LinkedHashSet<Cache> minFreqSet = freqMap.get(minFreq); 
            Cache toRemove = minFreqSet.iterator().next(); 
            minFreqSet.remove(toRemove); 
            if(minFreqSet.isEmpty()) freqMap.remove(minFreq); 

            cacheMap.remove(toRemove.key); 
            size--; 
        }

        Cache newNode = new Cache(key, value); 
        cacheMap.put(key, newNode); 
        freqMap.computeIfAbsent(1, k -> new LinkedHashSet<>()).add(newNode); 
        minFreq = 1; 
        size++; 
    }

    void updateFrequency(Cache node){
        int oldVal = node.count; 
        LinkedHashSet<Cache> oldSet = freqMap.get(oldVal); 
        oldSet.remove(node); //this may remove value in the middle? 
        if(oldSet.isEmpty()){
            freqMap.remove(oldVal); 
            if(oldVal == minFreq) minFreq++; 
        }
        node.count++;
        freqMap.computeIfAbsent(node.count, k -> new LinkedHashSet<>()).add(node); 
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */